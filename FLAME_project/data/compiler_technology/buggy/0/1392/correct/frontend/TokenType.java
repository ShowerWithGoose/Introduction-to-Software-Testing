package frontend;

public enum TokenType {
    // Ident, IntConst, StringConst, CharConst
    IDENFR, INTCON, STRCON, CHRCON,
    // main
    MAINTK,
    // const
    CONSTTK,
    // int, char
    INTTK, CHARTK,
    // break, continue
    BREAKTK, CONTINUETK,
    // if, else
    IFTK, ELSETK,
    // !. &&. ||
    NOT, AND, OR,
    // for
    FORTK,
    // getint, getchar
    GETINTTK, GETCHARTK,
    // printf
    PRINTFTK,
    // return
    RETURNTK,
    // +, -
    PLUS, MINU,
    // void
    VOIDTK,
    // *, /, %
    MULT, DIV, MOD,
    // <, <=, >, >=, ++, !=, =
    LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
    // ;
    SEMICN,
    // ,
    COMMA,
    // (, ), [, ], {, }
    LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
    // wrong
    HELP
}
