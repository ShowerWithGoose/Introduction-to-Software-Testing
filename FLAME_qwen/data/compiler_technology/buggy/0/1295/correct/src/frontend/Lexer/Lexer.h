//
// Created by  on 2024/10/1.
//

#ifndef SYS_COMPILER_LEXER_H
#define SYS_COMPILER_LEXER_H

#include <vector>
#include "Token.h"

namespace frontend {

    class Lexer {
    public:
        void printTokenList(const std::string& output_path);

        explicit Lexer(const std::string &text) : text(text) { init(); }

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
