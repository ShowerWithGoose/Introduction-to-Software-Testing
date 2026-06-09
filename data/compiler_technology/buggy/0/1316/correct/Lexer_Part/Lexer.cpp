#include "include/Lexer.h"
Lexer::Lexer(std::istream& input_stream)
{
	line_reader = new LineReader(input_stream);
	token_list = new list<Token*>;
}



void Lexer::process_lexer()
{
	while (!line_reader->input_is_end())
	{
		line_reader->skip_space();
		if (line_reader->skip_comment()) {
			continue;
		}
		if (Token* token = line_reader->get_token(); token != nullptr)
		token_list->push_back(token);
	}
}


void Lexer::put_tokens(std::ostream& output) const
{
	for (Token * token : *token_list)
	{
		output << *token;
	}
}




