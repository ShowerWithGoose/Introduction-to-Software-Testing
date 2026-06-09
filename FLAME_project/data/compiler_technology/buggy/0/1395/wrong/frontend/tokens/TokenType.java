package frontend.tokens;

public enum TokenType {
    // ident
    IDENFR,
    // int const
    INTCON,
    // string const
    STRCON,
    // char const
    CHRCON,
    // reserved words
    MAINTK, CONSTTK, INTTK, CHARTK, VOIDTK,
    BREAKTK, CONTINUETK, IFTK, ELSETK, FORTK, RETURNTK,
    GETINTTK, GETCHARTK, PRINTFTK,
    // delimiters
    NOT, AND, OR, PLUS, MINU, MULT, DIV, MOD,
    ASSIGN, LSS, LEQ, GRE, GEQ, EQL, NEQ,
    SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
    // 空白符, 注释
    BLANK, LINECOMMENT, BLOCKCOMMENT,
}