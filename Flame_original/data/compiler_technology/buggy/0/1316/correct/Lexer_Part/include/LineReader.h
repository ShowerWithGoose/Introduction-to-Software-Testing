#pragma once
#ifndef LINEREADER_H_
#include <map>
#include <iostream>
#include "Token.h"
#include "ErrorCollector.h"
using std::string;
class LineReader {
public:
	LineReader(std::istream&);
	void to_next_line();
	bool input_is_end() const;
	void skip_space();
	bool skip_comment();
	Token* get_token();
	void move_forward(int offset);

private:
	std::istream& input_stream;
	std::map<std::string, Token::TokenType> reserved_word;
	string line_content;
	int current_line;
	int pos;
	bool eof;
};
#endif
