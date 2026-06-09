#include <iostream>
#include <fstream>
#include <vector>
#include "print.h"
int main() {
    std::filebuf buf;
    if (buf.open("testfile.txt", std::ios::in) == nullptr) {
        //ERROR open
        return -1;
    }
    std::istream is(&buf);
    char first_char = is.get();
    Lexer *lexer = new Lexer(is, first_char);
    
    std::vector<Token> token_vec;
    Token *token = new Token();
    lexer->next(*token);
    while(token->type != Token::EOFTK) {
        token_vec.push_back(*token);
        token = new Token();
        lexer->next(*token);
    }
    if (!lexer->hasError) {
        for (auto it = token_vec.begin(); it != token_vec.end(); ++it) {
            std::cout << token_type_name_string(it->type) << " " << token_to_string(*it) << std::endl;
        }
    }
    return 0;
}