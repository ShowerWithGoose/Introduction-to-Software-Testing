//
// Created by  on 2024/10/1.
//

#ifndef SYS_COMPILER_LEXER_H
#define SYS_COMPILER_LEXER_H

#include <utility>
#include <vector>
#include "Token.h"

namespace frontend {

    class Lexer {
    public:
        bool has_next(int offset = 0) const;

        Token *ahead_of(int index) const;

        Token *cur_token() const;

        Token *next_assert(Token::TokenType type);

        Token *next();

    public:
        void printTokenList(const std::string& output_path);

        explicit Lexer(std::string text) : text(std::move(text)) { init(); }

        ~Lexer();
    private:
        void init();

        void matchOneToken();

    private:
        std::string text;
        std::vector<Token *> tokenList;
        int cur_index = 0;
    };

} // frontend

#endif //SYS_COMPILER_LEXER_H
