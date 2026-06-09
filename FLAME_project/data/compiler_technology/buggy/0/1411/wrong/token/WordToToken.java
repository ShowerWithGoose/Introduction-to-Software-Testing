package token;

import token.TokenName;

import java.util.HashMap;
import java.util.Map;

public class WordToToken {
    private static final Map<String, TokenName> map = new HashMap<>() {{
        put("main", TokenName.MAINTK);
        put("const", TokenName.CONSTTK);
        put("int", TokenName.INTTK);
        put("char", TokenName.CHARTK);
        put("break", TokenName.BREAKTK);
        put("continue", TokenName.CONTINUETK);
        put("if", TokenName.IFTK);
        put("else", TokenName.ELSETK);
        put("!", TokenName.NOT);
        put("&&", TokenName.AND);
        put("||", TokenName.OR);
        put("for", TokenName.FORTK);
        put("getint", TokenName.GETINTTK);
        put("getchar", TokenName.GETCHARTK);
        put("printf", TokenName.PRINTFTK);
        put("return", TokenName.RETURNTK);
        put("+", TokenName.PLUS);
        put("-", TokenName.MINU);
        put("void", TokenName.VOIDTK);
        put("*", TokenName.MULT);
        put("/", TokenName.DIV);
        put("%", TokenName.MOD);
        put("<", TokenName.LSS);
        put("<=", TokenName.LEQ);
        put(">", TokenName.GRE);
        put(">=", TokenName.GEQ);
        put("==", TokenName.EQL);
        put("!=", TokenName.NEQ);
        put("=", TokenName.ASSIGN);
        put(";", TokenName.SEMICN);
        put(",", TokenName.COMMA);
        put("(", TokenName.LPARENT);
        put(")", TokenName.RPARENT);
        put("[", TokenName.LBRACK);
        put("]", TokenName.RBRACK);
        put("{", TokenName.LBRACE);
        put("}", TokenName.RBRACE);
    }};
    public static TokenName word2token(String code) {
        return map.get(code);
    }
}
