package frontend.lexer;
public enum TokenType {
    /* ---------- specific elements begin ---------- */
    MAINTK,//("main"),
    CONSTTK,//("const"),
    INTTK,//( "int"),
    CHARTK,
    BREAKTK,//("break"),
    CONTINUETK,//( "continue"),
    IFTK,//("if"),
    ELSETK,//( "else"),

    FORTK,//for
    GETINTTK,//("getint"),
    GETCHARTK,
    PRINTFTK,//( "printf"),
    RETURNTK,//( "return"),
    VOIDTK,//( "void"),


    IDENFR,//ident即变量命名
    INTCON,//IntConst常量数字
    STRCON,//StringConst字符串常量"ab"
    CHRCON,//'a'
    NOT,//( "!"),
    AND,//( "&&"),
    OR,//("\\|\\|"),
    PLUS,//("\\+"),
    MINU,//( "-"),
    MULT,//( "\\*"),
    DIV,//( "/"),
    MOD,//( "%"),
    LEQ,//( "<="),
    LSS,//( "<"),
    GEQ,//( ">="),
    GRE,//( ">"),
    EQL,//( "=="),
    NEQ,//( "!="),
    ASSIGN,//( "="),
    SEMICN,//( ";"),
    COMMA,//( ","),
    LPARENT,//( "\\("),
    RPARENT,//( "\\)"),
    LBRACK,//( "\\["),
    RBRACK,//( "]"),
    LBRACE,//("\\{"),
    RBRACE,//( "}");


    END,////多出来，用来自己判断是否到结尾的

}
