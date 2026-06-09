//
// Created by  on 2024-09-02.
//

#ifndef SYS_COMPILER_TOKEN_H
#define SYS_COMPILER_TOKEN_H

#include <string>
#include <unordered_map>

#include "../../utils/utils.h"

namespace frontend {
    // 语义单元
    class Token {
    public:
        enum class TokenType {
            // 标识符
            IDENFR,

            // 常量
            INTCON, STRCON, CHRCON,

            // 保留字
            MAINTK, CONSTTK, INTTK, BREAKTK, CONTINUETK, IFTK,
            ELSETK, FORTK, RETURNTK, VOIDTK, GETINTTK, PRINTFTK,
            CHARTK, GETCHARTK,

            // 分界符
            NOT, AND, OR, PLUS, MINU, MULT, DIV, MOD,
            LSS, LEQ, GRE, GEQ, EQL, NEQ,
            ASSIGN, SEMICN, COMMA, LPARENT,
            RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
        };

    public:
        // 判断 token 类型
        bool is_type(TokenType type) const;

        TokenType getTokenType() const { return type; }

        int getLineNum() const { return lineNum; }

        std::string getContent() const { return content; }

        Token(TokenType type, std::string& content, int lineNum) : type(type), lineNum(lineNum), content(content) {}

        // 尝试匹配各类token，匹配成功返回匹配到的末尾索引 + 1（即下次开始匹配的位置），否则返回0
        // 尝试匹配保留字
        static int tryMatchReserved(const std::string &text, int start_index);

        // 尝试匹配标识符
        static int tryMatchIdentifier(const std::string &text, int start_index);

        // 尝试匹配字符串常量
        static int tryMatchStr(const std::string &text, int start_index);

        // 尝试匹配整数常量
        static int tryMatchInt(const std::string &text, int start_index);

        // 尝试匹配字符常量
        static int tryMatchChar(const std::string &text, int start_index);

        // 尝试匹配分界符
        static int tryMatchDelimiter(const std::string &text, int start_index);
    private:
        TokenType type;  // 类别码
        int lineNum;  // 行号
        std::string content;  // 内容
    };

    extern std::unordered_map<std::string, Token::TokenType> reserved_to_type_map;
    extern std::unordered_map<std::string, Token::TokenType> delimiter_to_type_map;
    extern std::string token_type_to_string_map[];
} // frontend

#endif //SYS_COMPILER_TOKEN_H
