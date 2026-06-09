package utils;

public enum TokenType {
    IDENFR,
    INTCON,
    STRCON,

    /* new */
    CHRCON,

    MAINTK,
    CONSTTK,
    INTTK,

    /* new */
    CHARTK,

    BREAKTK,
    CONTINUETK,
    IFTK,
    ELSETK,
    NOT,
    AND,
    OR,

    /* new */
    FORTK,

    GETINTTK,

    /* new */
    GETCHARTK,

    PRINTFTK,
    RETURNTK,
    PLUS,
    MINU,
    VOIDTK,
    MULT,
    DIV,
    MOD,
    LSS,
    LEQ,
    GRE,
    GEQ,
    EQL,
    NEQ,
    ASSIGN,
    SEMICN,
    COMMA,
    LPARENT,
    RPARENT,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE,

    EOF,
    ERROR;
}
