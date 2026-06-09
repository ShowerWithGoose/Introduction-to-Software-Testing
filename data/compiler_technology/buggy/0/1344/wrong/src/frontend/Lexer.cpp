#include "../../include/frontend/Lexer.h"
#include <string>
#include <cstdio>

#define isSpace(x) (x == ' ') || (x == '\r') || (x == '\t')

using namespace std;

Lexer::Lexer(ifstream &input, ofstream &output_for_lexer, ofstream &output_error): input(input), output_for_lexer(output_for_lexer), output_error(output_error) {
	this->line_num = 1;
	while(getline(input, cur_line)) token_lists.push_back(cur_line);
}

void Lexer::printOut() {
	if (output_for_lexer.is_open()) {
		string str = out_for_lexer.at(this->cur_type);
		output_for_lexer << str << " " << this->cur_token << "\n";
	}
}

void Lexer::printOut_for_error() {
	if (output_error.is_open()) 
		output_error << this->line_num << " a" << "\n";
}

void Lexer::work() {
	for (auto &token_list: token_lists) {
		this->cur_line = token_list;
		this->line_num++;
		parseLine();
	}
}

void Lexer::parseLine() {
	this->index = 0;
	skip_comment(); // annotation
	while (index < cur_line.length()) next();
}

void Lexer::next() {
	this->cur_token.clear();
	while (isSpace(cur_line[index]) && index < this->cur_line.length()) {
		index++;
	}
	string str;
	str = cur_line[index];
	//cout << str << "\n";
	if (isdigit(cur_line[index])) getNum();
	else if (isalpha(cur_line[index]) || cur_line[index] == '_') getWord();
	else if (cur_line[index] == '"') getStr();
	else if (cur_line[index] == '\'') getChar();
	else if (symbol.count(str)) getSym();
}

void Lexer::getNum() {
	string str;
	while (isdigit(cur_line[index]) && index < cur_line.length()) str += cur_line[index++];
	this->cur_token = str;
	this->cur_type = INTCON;
	printOut();
}

void Lexer::getWord() {
	string str;
	while (isalpha(cur_line[index]) || cur_line[index] == '_' || isdigit(cur_line[index])) str += cur_line[index++];
	// exist ReserveWord or not
	if (ReserveWord.count(str)) {
		this->cur_token = str;
		this->cur_type = ReserveWord.at(str);
	} else {
		this->cur_token = str;
		this->cur_type = IDENFR;
	}
	printOut();
}

void Lexer::getStr() {
	string str;
	index++, str += '"';
	while (cur_line[index] != '"' && index < cur_line.length()) str += cur_line[index++];
	index++, str += '"';
	this->cur_token = str;
	this->cur_type = STRCON;
	printOut();
}

void Lexer::getChar() {
	string str;
	index++, str += '\'';
	// str = '\' 
	// ans = CHRCON '\''
	while (cur_line[index] != '\'' && index < cur_line.length()) {
		str += cur_line[index];
		if (cur_line[index] == '\\') str += cur_line[++index];
		index++;
	}
	index++, str += '\'';
	this->cur_token = str;
	this->cur_type = CHRCON;
	printOut();
}

void Lexer::getSym() {
	string str;
	str += cur_line[index++];
	// str = "&"
	if (index < cur_line.length()) {
		string rts = str + cur_line[index];
		// rts = "&&"
		if (symbol.count(rts)) {
			this->cur_token = rts;
			this->cur_type = symbol.at(rts);
			index++;
		} else {
			this->cur_token = str;
			this->cur_type = symbol.at(str);
			if (str[0] == '&' || str[0] == '|') printOut_for_error();
			if (str[0] == '&') this->cur_type = AND;
			if (str[0] == '|') this->cur_type = OR;
		}
	} else {
		this->cur_token = str;
		this->cur_type = symbol.at(str);
		if (str[0] == '&' || str[0] == '|') printOut_for_error();
		if (str[0] == '&') this->cur_type = AND;
		if (str[0] == '|') this->cur_type = OR;
	}

	printOut();
}

void Lexer::skip_comment() {
	bool f = false;
	string str;
	str = "";
	for (auto i = 0; i < cur_line.length(); ++i) {
		if (!this->annotation) {
			if (cur_line[i] == '"') f = !f;
			if (!f) {
				if (cur_line[i] == '/' && cur_line[i + 1] == '/') break;
				else if (cur_line[i] == '/' && cur_line[i + 1] == '*') {
					i++;
					this->annotation = true;
				}
			}
			if (!this->annotation) str += cur_line[i];
		} else {
			if (cur_line[i] == '*' && cur_line[i + 1] == '/') {
				i++;
				this->annotation = false;
			}
		}
	}
	this->cur_line = str;
}