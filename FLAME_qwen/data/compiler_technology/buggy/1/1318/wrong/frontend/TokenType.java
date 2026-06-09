package frontend;

import java.util.HashMap;
import java.util.Map;

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
    private static final Map<String, TokenType> symbolMap = new HashMap<>();

    static {
        for (TokenType tokenType : TokenType.values()) {
            if (tokenType.symbol != null) {
                symbolMap.put(tokenType.symbol, tokenType);
            }
        }
    }

    @Override
    public String toString() {
        if (this.symbol != null) {
            return this.name() + " " + this.symbol;
        }
        return this.name();
    }

    TokenType(String symbol) {
        this.symbol = symbol;
    }

    TokenType() {
        this.symbol = null;
    }

    public static TokenType getBySymbol(String symbol) {
        return symbolMap.get(symbol);
    }

    public String getSymbol() {
        return this.symbol;
    }
}