package frontend;

public enum TokenType {
    IDENFR,
    INTCON,
    STRCON,
    CHRCON,
    MAINTK("main"),
    CONSTTK("const"),
    INTTK("int"),
    CHARTK("char"),
    BREAKTK("break"),
    CONTINUETK("continue"),
    IFTK("if"),
    ELSETK("else"),
    NOT("!"),
    AND("&&"),
    OR("||"),
    FORTK("for"),
    GETINTTK("getint"),
    GETCHARTK("getchar"),
    PRINTFTK("printf"),
    RETURNTK("return"),
    PLUS("+"),
    MINU("-"),
    VOIDTK("void"),
    MULT("*"),
    DIV("/"),
    MOD("%"),
    LSS("<"),
    LEQ("<="),
    GRE(">"),
    GEQ(">="),
    EQL("=="),
    NEQ("!="),
    ASSIGN("="),
    SEMICN(";"),
    COMMA(","),
    LPARENT("("),
    RPARENT(")"),
    LBRACK("["),
    RBRACK("]"),
    LBRACE("{"),
    RBRACE("}");

    private final String symbol;

    TokenType(String symbol) {
        this.symbol = symbol;
    }

    TokenType() {
        this.symbol = null;
    }

    public String getSymbol() {
        return symbol;
    }

    public static TokenType getBySymbol(String symbol) {
        for (TokenType tokenType : TokenType.values()) {
            if (tokenType.getSymbol().equals(symbol)) {
                return tokenType;
            }
        }
        return null;
    }

}