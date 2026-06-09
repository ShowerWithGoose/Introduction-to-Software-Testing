package frontend;

public enum Type {
    IDENFR, INTCON, STRCON, CHRCON,
    MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, VOIDTK,
    NOT, AND, OR, PLUS, MINU, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,

    // 字母开头
    // IDENFR, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, VOIDTK,

    // 数字开头
    // INTCON

    // 符号开头（单字符识别）
    // STRCON("), CHRCON('), PLUS(+), MINU(-), MULT(*), DIV(/),
    // MOD(%), SEMICN(;), COMMA(,),
    // LPARENT('('), RPARENT(')'), LBRACK('['), RBRACK(']'),
    // LBRACE('{'), RBRACE('}')

    // 符号开头（多字符识别）
    // NOT(!), NEQ(!=)
    // AND(&&)
    // OR(||)
    // LSS(<), LEQ(<=)
    // GRE(>), GEQ(>=)
    // ASSIGN(=), EQL(==)
}
