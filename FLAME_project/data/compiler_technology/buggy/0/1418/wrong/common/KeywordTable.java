package common;

import enums.TokenType;

import java.util.HashMap;
import java.util.Map;

public class KeywordTable {
    private static final KeywordTable instance = new KeywordTable();
    private final Map<String, TokenType> keywords;
    private KeywordTable() {
        keywords = new HashMap<>();
        keywords.put("main", TokenType.MAINTK);
        keywords.put("const", TokenType.CONSTTK);
        keywords.put("int", TokenType.INTTK);
        keywords.put("char", TokenType.CHARTK);
        keywords.put("break", TokenType.BREAKTK);
        keywords.put("continue", TokenType.CONTINUETK);
        keywords.put("if", TokenType.IFTK);
        keywords.put("else", TokenType.ELSETK);
        keywords.put("for", TokenType.FORTK);
        keywords.put("getint", TokenType.GETINTTK);
        keywords.put("getchar", TokenType.GETCHARTK);
        keywords.put("printf", TokenType.PRINTFTK);
        keywords.put("return", TokenType.RETURNTK);
        keywords.put("void", TokenType.VOIDTK);
    }

    public static KeywordTable getInstance() {
        return instance;
    }

    public TokenType getKeywordType(String name) {
        return keywords.get(name);
    }
}
