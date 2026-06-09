#pragma once
#ifndef LEXER_H_
#include <list>

#include "LineReader.h"
#include "Token.h"
using std::list;
class Lexer {
public:
	explicit Lexer(std::istream&);
	void process_lexer();
	void put_tokens(std::ostream& output) const;

private:
	LineReader* line_reader;
	list<Token*>* token_list;
};
#endif
