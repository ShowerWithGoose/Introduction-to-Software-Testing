package frontend.token;

import java.util.HashMap;

public class Token {
    private final int line;
    private final String content;
    private final TokenType type;
    private static final HashMap<String, TokenType> stringToTokenType = new HashMap<>();

    static {
        stringToTokenType.put("main", TokenType.MAINTK);
        stringToTokenType.put("const", TokenType.CONSTTK);
        stringToTokenType.put("int", TokenType.INTTK);
        stringToTokenType.put("char", TokenType.CHARTK);
        stringToTokenType.put("break", TokenType.BREAKTK);
        stringToTokenType.put("continue", TokenType.CONTINUETK);
        stringToTokenType.put("if", TokenType.IFTK);
        stringToTokenType.put("else", TokenType.ELSETK);
        stringToTokenType.put("!", TokenType.NOT);
        stringToTokenType.put("&&", TokenType.AND);
        stringToTokenType.put("||", TokenType.OR);
        stringToTokenType.put("for", TokenType.FORTK);
        stringToTokenType.put("getint", TokenType.GETINTTK);
        stringToTokenType.put("getchar", TokenType.GETCHARTK);
        stringToTokenType.put("printf", TokenType.PRINTFTK);
        stringToTokenType.put("return", TokenType.RETURNTK);
        stringToTokenType.put("+", TokenType.PLUS);
        stringToTokenType.put("-", TokenType.MINU);
        stringToTokenType.put("void", TokenType.VOIDTK);
        stringToTokenType.put("*", TokenType.MULT);
        stringToTokenType.put("/", TokenType.DIV);
        stringToTokenType.put("%", TokenType.MOD);
        stringToTokenType.put("<", TokenType.LSS);
        stringToTokenType.put("<=", TokenType.LEQ);
        stringToTokenType.put(">", TokenType.GRE);
        stringToTokenType.put(">=", TokenType.GEQ);
        stringToTokenType.put("==", TokenType.EQL);
        stringToTokenType.put("!=", TokenType.NEQ);
        stringToTokenType.put("=", TokenType.ASSIGN);
        stringToTokenType.put(";", TokenType.SEMICN);
        stringToTokenType.put(",", TokenType.COMMA);
        stringToTokenType.put("(", TokenType.LPARENT);
        stringToTokenType.put(")", TokenType.RPARENT);
        stringToTokenType.put("[", TokenType.LBRACK);
        stringToTokenType.put("]", TokenType.RBRACK);
        stringToTokenType.put("{", TokenType.LBRACE);
        stringToTokenType.put("}", TokenType.RBRACE);
    }

    public Token(String content, TokenType type, int line) {
        this.content = content;
        this.type = type;
        this.line = line;
    }

    private static TokenType stringToTokenType(String s, TokenType defaultType) {
        return stringToTokenType.getOrDefault(s, defaultType);
    }

    public static TokenType wordToTokenType(String s) {
        return stringToTokenType(s, TokenType.IDENFR);
    }

    public static TokenType symbolToTokenType(String s) {
        return stringToTokenType(s, TokenType.INVALID);
    }

    @Override
    public String toString() {
        return type + " " + content;
    }
}