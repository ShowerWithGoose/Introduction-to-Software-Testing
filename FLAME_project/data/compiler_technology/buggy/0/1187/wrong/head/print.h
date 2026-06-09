#include "lexer.h"

inline std::string token_type_name_string(Token::TokenType type) {
    static const std::unordered_map<Token::TokenType, std::string>
        token_type_name = {
#define X(a, b) {Token::a, #a},
            TOKEN_TYPE
#undef X
        };
    return token_type_name.at(type);
}

inline std::string token_to_string(Token token) {
    static const std::unordered_map<Token::TokenType, std::string>
        token_type_str = {
#define X(a, b) {Token::a, b},
            TOKEN_TYPE
#undef X
        };
    switch (token.type) {
        case Token::IDENFR:
        case Token::INTCON:
        case Token::STRCON:
        case Token::CHRCON:
            return token.content;
            break;
        default:
            return token_type_str.at(token.type);
    }

}