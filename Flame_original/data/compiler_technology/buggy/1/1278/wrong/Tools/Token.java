package Tools;

import java.util.HashMap;

public class Token {

    private static final HashMap <String, TokenType> matchListLetter = new HashMap<String, TokenType>() {
        {   put("if", Token.TokenType.IFTK);
            put("else", Token.TokenType.ELSETK);
            put("for", Token.TokenType.FORTK);
            put("const", Token.TokenType.CONSTTK);
            put("int", Token.TokenType.INTTK);
            put("char", Token.TokenType.CHARTK);
            put("void", Token.TokenType.VOIDTK);
            put("return", Token.TokenType.RETURNTK);
            put("printf", Token.TokenType.PRINTFTK);
            put("main", Token.TokenType.MAINTK);
            put("break", Token.TokenType.BREAKTK);
            put("continue", Token.TokenType.CONTINUETK);
            put("getint", Token.TokenType.GETINTTK);
            put("getchar", Token.TokenType.GETCHARTK);
        }
    };

    private static final HashMap <String, TokenType> matchListSign = new HashMap<String, TokenType>() {
        {
            put("=", Token.TokenType.ASSIGN);
            put("<", Token.TokenType.LSS);
            put("<=", Token.TokenType.LEQ);
            put(">", Token.TokenType.GRE);
            put(">=", Token.TokenType.GEQ);
            put("==", Token.TokenType.EQL);
            put("!=", Token.TokenType.NEQ);
            put("+", Token.TokenType.PLUS);
            put("-", Token.TokenType.MINU);
            put("*", Token.TokenType.MULT);
            put("/", Token.TokenType.DIV);
            put("%", Token.TokenType.MOD);
            put(";", Token.TokenType.SEMICN);
            put(",", Token.TokenType.COMMA);
            put("(", Token.TokenType.LPARENT);
            put(")", Token.TokenType.RPARENT);
            put("[", Token.TokenType.LBRACK);
            put("]", Token.TokenType.RBRACK);
            put("{", Token.TokenType.LBRACE);
            put("}", Token.TokenType.RBRACE);
            put("||", Token.TokenType.OR);
            put("&&", Token.TokenType.AND);
            put("!", Token.TokenType.NOT);
        }
    };

    public enum TokenType {
        IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK,
        CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK, NOT, AND, OR,
        FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS, MINU,
        VOIDTK, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
        SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
        UNKNOW
    }

    private TokenType type;
    private String value;
    private int lineno;

    public Token(TokenType type, String value, int lineno) {
        this.type = type;
        this.value = value;
        this.lineno = lineno;
    }

    public TokenType getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public int getLineno() {
        return lineno;
    }

    public static TokenType getMatchListLetter(String str) {
        return (matchListLetter.getOrDefault(str, TokenType.IDENFR));
    }

    public static TokenType getMatchListSign(String str) {
        return (matchListSign.getOrDefault(str, TokenType.UNKNOW));
    }

    @Override
    public String toString() {
        return type + " " + value;
    }


}