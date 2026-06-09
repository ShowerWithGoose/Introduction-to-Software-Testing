package lexer;

public enum TokenType {
    IDENT("IDENFR", "Ident"),
    INT_CONST("INTCON", "IntConst"),
    STRING_CONST("STRCON", "StringConst"),
    CHAR_CONST("CHRCON", "CharConst"),
    MAIN("MAINTK", "main"),
    CONST("CONSTTK", "const"),
    INT("INTTK", "int"),
    CHAR("CHARTK", "char"),
    BREAK("BREAKTK", "break"),
    CONTINUE("CONTINUETK", "continue"),
    IF("IFTK", "if"),
    ELSE("ELSETK", "else"),
    NOT("NOT", "!"),
    AND("AND", "&&"),
    OR("OR", "||"),
    FOR("FORTK", "for"),
    GETINT("GETINTTK", "getint"),
    GETCHAR("GETCHARTK", "getchar"),
    PRINTF("PRINTFTK", "printf"),
    RETURN("RETURNTK", "return"),
    PLUS("PLUS", "+"),
    MINU("MINU", "-"),
    VOID("VOIDTK", "void"),
    MULT("MULT", "*"),
    DIV("DIV", "/"),
    MOD("MOD", "%"),
    LSS("LSS", "<"),
    LEQ("LEQ", "<="),
    GRE("GRE", ">"),
    GEQ("GEQ", ">="),
    EQL("EQL", "=="),
    NEQ("NEQ", "!="),
    ASSIGN("ASSIGN", "="),
    SEMICN("SEMICN", ";"),
    COMMA("COMMA", ","),
    LPARENT("LPARENT", "("),
    RPARENT("RPARENT", ")"),
    LBRACK("LBRACK", "["),
    RBRACK("RBRACK", "]"),
    LBRACE("LBRACE", "{"),
    RBRACE("RBRACE", "}");

    private final String code;
    private final String name;

    TokenType(String code, String name) {
        this.code = code;
        this.name = name;
    }

    public String getCode() {
        return this.code;
    }

    public String getName() {
        return this.name;
    }

    public String toString() {
        return getCode();
    }
}
