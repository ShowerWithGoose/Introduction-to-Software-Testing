package frontend.lexer;

public enum TokenType {
    IDENFR("Ident", "[a-zA-Z_][a-zA-Z0-9_]*"),
    INTCON("IntConst", "0|[1-9]\\d*"),
    STRCON("StringConst", "\\\"[.]*\\\""),
    CHRCON("CharConst", "\\'[.]\\'"),
    MAINTK("main", "main"),
    CONSTTK("const", "const"),
    INTTK("int", "int"),
    CHARTK("char", "char"),
    BREAKTK("break", "break"),
    CONTINUETK("continue", "continue"),
    IFTK("if", "if"),
    ELSETK("else", "else"),
    NOT("!", "!"),
    AND("&&", "&&"),
    OR("||", "\\|\\|"),
    FORTK("for", "for"),
    GETINTTK("getint", "getint"),
    GETCHARTK("getchar", "getchar"),
    PRINTFTK("printf", "printf"),
    RETURNTK("return", "return"),
    PLUS("+", "+"),
    MINU("-", "-"),
    VOIDTK("void", "void"),
    MULT("*", "*"),
    DIV("/", "/"),
    MOD("%", "%"),
    LSS("<", "<"),
    LEQ("<=", "<="),
    GRE(">", ">"),
    GEQ(">=", ">="),
    EQL("==", "=="),
    NEQ("!=", "!="),
    ASSIGN("=", "="),
    SEMICN(";", ";"),
    COMMA(",", ","),
    LPARENT("(", "\\("),
    RPARENT(")", "\\)"),
    LBRACK("[", "\\["),
    RBRACK("]", "\\]"),
    LBRACE("{", "\\{"),
    RBRACE("}", "\\}");

    private String name;
    private String pattern;

    private TokenType(String name, String pattern) {
        this.name = name;
        this.pattern = pattern;
    }

    public String TokenName() {
        return this.name;
    }



}
