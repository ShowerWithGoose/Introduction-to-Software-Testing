package frontend.lexer;

public enum TokenType {
    IDENFR,   // Ident
    INTCON,   // IntConst
    STRCON,   // StringConst
    CHRCON,   // CharConst
    MAINTK,   // main
    CONSTTK,  // const
    INTTK,    // int
    CHARTK,   // char
    BREAKTK,  // break
    CONTINUETK, // continue
    IFTK,     // if
    ELSETK,   // else
    VOIDTK,   // void
    NOT,      // !
    AND,      // &&
    OR,       // ||
    FORTK,    // for
    GETINTTK, // getint
    GETCHARTK, // getchar
    PRINTFTK, // printf
    RETURNTK, // return
    PLUS,     // +
    MINU,     // -
    MULT,     // *
    DIV,      // /
    MOD,      // %
    LSS,      // <
    LEQ,      // <=
    GRE,      // >
    GEQ,      // >=
    EQL,      // ==
    NEQ,      // !=
    ASSIGN,   // =
    SEMICN,   // ;
    COMMA,    // ,
    LBRACE,   // {
    RBRACE,   // }
    LBRACK,   // [
    RBRACK,   // ]
    LPARENT,     // (
    RPARENT      // )
}
