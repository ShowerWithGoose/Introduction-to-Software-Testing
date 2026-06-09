#include "include/LineReader.h"

#include <algorithm>

LineReader::LineReader(std::istream& input) : input_stream(input)
{
	reserved_word = {
		{"main", Token::TokenType::MAINTK},
		{"const", Token::TokenType::CONSTTK},
		{"int", Token::TokenType::INTTK},
		{"char", Token::TokenType::CHARTK},
		{"break", Token::TokenType::BREAKTK},
		{"continue", Token::TokenType::CONTINUETK},
		{"if", Token::TokenType::IFTK},
		{"else", Token::TokenType::ELSETK},
		{"void", Token::TokenType::VOIDTK},
		{"for", Token::TokenType::FORTK},
		{"getint", Token::TokenType::GETINTTK},
		{"getchar", Token::TokenType::GETCHARTK},
		{"printf", Token::TokenType::PRINTFTK},
		{"return", Token::TokenType::RETURNTK},
	};
	current_line = 0;
	pos = 0;
	eof = false;
	to_next_line();
}

void LineReader::to_next_line()
{
	while (std::getline(input_stream, line_content)) {
		pos = 0;
		current_line++;
		if (!line_content.empty()) {
			return;
		}
	}
	eof = true;
}

bool LineReader::input_is_end() const
{
	return eof;
}

void LineReader::skip_space()
{
	while (pos < line_content.size() && std::isspace(line_content[pos])) {
		++pos;
	}
}

void LineReader::skip_comment()
{
	if (line_content[pos] == '/')
	{
		if (line_content[pos + 1] == '/') {
			to_next_line();
		} else if (line_content[pos + 1] == '*')
		{
			move_forward(DOUBLE_TOKEN_LEN);
			while (!(line_content[pos] == '*' && pos + 1 < line_content.length() && line_content[pos + 1] == '/'))
			{
				move_forward(SINGLE_TOKEN_LEN);
			}
			move_forward(DOUBLE_TOKEN_LEN);
		}
	}
}

void LineReader::move_forward(int offset)
{
	pos += offset;
	if (pos >= line_content.length())
	{
		to_next_line();
	}
}

Token* LineReader::get_token()
{
	Token::TokenType token_type;
	std::string content;
	if (line_content[pos] == '{')
	{
		token_type = Token::TokenType::LBRACE;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '}')
	{
		token_type = Token::TokenType::RBRACE;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '[')
	{
		token_type = Token::TokenType::LBRACK;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == ']')
	{
		token_type = Token::TokenType::RBRACK;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '(')
	{
		token_type = Token::TokenType::LPARENT;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == ')')
	{
		token_type = Token::TokenType::RPARENT;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == ',')
	{
		token_type = Token::TokenType::COMMA;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == ';')
	{
		token_type = Token::TokenType::SEMICN;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '=')
	{
		content += line_content[pos];
		if (line_content[pos + 1] == '=')
		{
			token_type = Token::TokenType::EQL;
			content += line_content[pos + 1];
			move_forward(DOUBLE_TOKEN_LEN);
		}
		else {
			token_type = Token::TokenType::ASSIGN;
			move_forward(SINGLE_TOKEN_LEN);
		}
	}
	else if (line_content[pos] == '!')
	{
		content += line_content[pos];
		if (line_content[pos + 1] == '=')
		{
			token_type = Token::TokenType::NEQ;
			content += line_content[pos + 1];
			move_forward(DOUBLE_TOKEN_LEN);
		}
		else {
			token_type = Token::TokenType::NOT;
			move_forward(SINGLE_TOKEN_LEN);
		}
	}
	else if (line_content[pos] == '>')
	{
		content += line_content[pos];
		if (line_content[pos + 1] == '=')
		{
			token_type = Token::TokenType::GEQ;
			content += line_content[pos + 1];
			move_forward(DOUBLE_TOKEN_LEN);
		}
		else {
			token_type = Token::TokenType::GRE;
			move_forward(SINGLE_TOKEN_LEN);
		}
	}
	else if (line_content[pos] == '<')
	{
		content += line_content[pos];
		if (line_content[pos + 1] == '=')
		{
			token_type = Token::TokenType::LEQ;
			content += line_content[pos + 1];
			move_forward(DOUBLE_TOKEN_LEN);
		}
		else {
			token_type = Token::TokenType::LSS;
			move_forward(SINGLE_TOKEN_LEN);
		}
	}
	else if (line_content[pos] == '%')
	{
		token_type = Token::TokenType::MOD;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '/')
	{
		token_type = Token::TokenType::DIV;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '*')
	{
		token_type = Token::TokenType::MULT;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '-')
	{
		token_type = Token::TokenType::MINU;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '+')
	{
		token_type = Token::TokenType::PLUS;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}
	else if (line_content[pos] == '|')
	{
		content += line_content[pos];
		if (line_content[pos + 1] == '|')
		{
			token_type = Token::TokenType::OR;
			content += line_content[pos + 1];
			move_forward(DOUBLE_TOKEN_LEN);
		}
		else {
			token_type = Token::TokenType::UNKNOWN;
			ErrorCollector::meet_error(ILLEGAL_SYMBOL, current_line);
			move_forward(SINGLE_TOKEN_LEN);
		}
	}
	else if (line_content[pos] == '&')
	{
		content += line_content[pos];
		if (line_content[pos + 1] == '&')
		{
			token_type = Token::TokenType::AND;
			content += line_content[pos + 1];
			move_forward(DOUBLE_TOKEN_LEN);
		}
		else {
			token_type = Token::TokenType::UNKNOWN;
			ErrorCollector::meet_error(ILLEGAL_SYMBOL, current_line);
			move_forward(SINGLE_TOKEN_LEN);
		}
	}
	else if (line_content[pos] == '_' || std::isalpha(line_content[pos]))
	{
		content += line_content[pos];
		while ((line_content[pos + content.length()] == '_' ||
			std::isalnum(line_content[pos + content.length()])
			&& pos + content.length() < line_content.length()))
		{
			content += line_content[pos + content.length()];
		}
		auto it = reserved_word.find(content);
		if (it != reserved_word.end()) {
			token_type = it->second;
		}
		else {
			token_type = Token::TokenType::IDENFR;
		}
		move_forward(content.length());
	}
	else if (std::isdigit(line_content[pos]))
	{
		content += line_content[pos];
		while (std::isdigit(line_content[pos + content.length()]
			&& pos + content.length() < line_content.length()))
		{
			content += line_content[pos + content.length()];
		}
		token_type = Token::TokenType::INTCON;
		move_forward(content.length());
	}
	else if (line_content[pos] == '\"')
	{
		content += line_content[pos];
		while (line_content[pos + content.length()] != '\"'
			&& pos + content.length() < line_content.length())
		{
			if (line_content[pos + content.length()] == '\\')
			{
				content += line_content[pos + content.length()];
			}
			content += line_content[pos + content.length()];
		}
		content += line_content[pos + content.length()];
		token_type = Token::TokenType::STRCON;
		move_forward(content.length());
	}
	else if (line_content[pos] == '\'')
	{
		content += line_content[pos];
		while (line_content[pos + content.length()] != '\''
			&& pos + content.length() < line_content.length())
		{
			if (line_content[pos + content.length()] == '\\')
			{
				content += line_content[pos + content.length()];
			}
			content += line_content[pos + content.length()];
		}
		content += line_content[pos + content.length()];
		token_type = Token::TokenType::CHRCON;
		move_forward(content.length());
	}
	else
	{
		token_type = Token::TokenType::UNKNOWN;
		content += line_content[pos];
		move_forward(SINGLE_TOKEN_LEN);
	}

	if (token_type != Token::TokenType::UNKNOWN) {
		Token* token = new Token(token_type, content, current_line);
		return token;
	}
	else
	{
		return nullptr;
	}
}