package token;

import config.Config;

import java.util.HashMap;
import java.util.Map;

public class Token {
    public enum TokenType {
        IDENFR,
        INTCON,
        STRCON,
        CHRCON,
        MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, RETURNTK, VOIDTK,
        IFTK, ELSETK,
        NOT, AND, OR,
        FORTK,
        GETINTTK, GETCHARTK, PRINTFTK,
        PLUS, MINU, MULT, DIV, MOD,
        LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
        SEMICN, COMMA,
        LPARENT, RPARENT,
        LBRACK, RBRACK,
        LBRACE, RBRACE
    }

    public static Map<String, TokenType> TK = new HashMap<>() {{
        put("main", TokenType.MAINTK);
        put("const", TokenType.CONSTTK);
        put("int", TokenType.INTTK);
        put("char", TokenType.CHARTK);
        put("break", TokenType.BREAKTK);
        put("continue", TokenType.CONTINUETK);
        put("return", TokenType.RETURNTK);
        put("void", TokenType.VOIDTK);
        put("if", TokenType.IFTK);
        put("else", TokenType.ELSETK);
        put("getint", TokenType.GETINTTK);
        put("getchar", TokenType.GETCHARTK);
        put("printf", TokenType.PRINTFTK);
    }};

    public static Map<Character, TokenType> SINGLE = new HashMap<>() {{
        put('+', TokenType.PLUS);
        put('-', TokenType.MINU);
        put('*', TokenType.MULT);
        put('%', TokenType.MOD);
        put(';', TokenType.SEMICN);
        put(',', TokenType.COMMA);
        put('(', TokenType.LPARENT);
        put(')', TokenType.RPARENT);
        put('[', TokenType.LBRACK);
        put(']', TokenType.RBRACK);
        put('{', TokenType.LBRACE);
        put('}', TokenType.RBRACE);
    }};

    TokenType type;
    String value;
    int line;

    public Token(TokenType type, String value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(type);
        sb.append(" ");
        sb.append(value);
        if (Config.TOKEN_FULL_DESC){
            sb.append(" ");
            sb.append(line);
        }
        return sb.toString();
    }
}
