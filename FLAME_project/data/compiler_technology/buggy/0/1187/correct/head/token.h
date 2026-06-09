#include <string>
#define TOKEN_TYPE \
    X(OR, "||") \
    X(NOT, "!") \
    X(AND, "&&") \
    X(DIV, "/") \
    X(MOD, "%") \
    X(LSS, "<") \
    X(LEQ, "<=") \
    X(GRE, ">") \
    X(GEQ, ">=") \
    X(EQL, "==") \
    X(NEQ, "!=") \
    X(MULT, "*") \
    X(PLUS, "+") \
    X(MINU, "-") \
    X(IFTK, "if") \
    X(INTTK, "int") \
    X(FORTK, "for") \
    X(COMMA, ",") \
    X(ASSIGN, "=") \
    X(SEMICN, ";") \
    X(LBRACK, "[") \
    X(RBRACK, "]") \
    X(LBRACE, "{") \
    X(RBRACE, "}") \
    X(IDENFR, "") \
    X(INTCON, "") \
    X(STRCON, "") \
    X(CHRCON, "") \
    X(MAINTK, "main") \
    X(ELSETK, "else") \
    X(CHARTK, "char") \
    X(VOIDTK, "void") \
    X(LPARENT, "(") \
    X(RPARENT, ")") \
    X(CONSTTK, "const") \
    X(BREAKTK, "break") \
    X(GETINTTK, "getint") \
    X(PRINTFTK, "printf") \
    X(RETURNTK, "return") \
    X(GETCHARTK, "getchar") \
    X(CONTINUETK, "continue")


struct Token {
    enum TokenType {
#define X(a, b) a,
    TOKEN_TYPE
#undef X
    EOFTK
    } type;
    std::string content;
    int lineno;

    Token() = default;
    Token(TokenType type, int lineno)
        : type(type), lineno(lineno) {}

    Token(TokenType type, std::string content, int lineno)
        : type(type), content(content), lineno(lineno) {}
};