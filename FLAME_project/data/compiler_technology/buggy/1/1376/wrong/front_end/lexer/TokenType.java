package front_end.lexer;

public enum TokenType {
    //=
    ASSIGN,
    //+
    PLUS,
    //&&
    AND,

    BREAKTK,

    CONTINUETK,
    CHARTK,
    CONSTTK,
    CHRCON,
    //,
    COMMA,
    // /
    DIV,

    ELSETK,
    EOF,
    //==
    EQL,

    FORTK,

    GETINTTK,
    GETCHARTK,
    //>
    GRE,
    //>=
    GEQ,

    IFTK,
    INTTK,
    IDENFR,

    //[
    LBRACK,
    //(
    LPARENT,
    //{
    LBRACE,
    //<
    LSS,
    //<=
    LEQ,

    MAINTK,
    //*
    MULT,
    //%
    MOD,

    INTCON,
    //!=
    NEQ,
    //!
    NOT,

    //||
    OR,

    PRINTFTK,

    RETURNTK,
    //]
    RBRACK,
    //)
    RPARENT,
    //}
    RBRACE,

    STRCON,
    //;
    SEMICN,
    //-
    MINU,

    VOIDTK,
}
