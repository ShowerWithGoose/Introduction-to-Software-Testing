package frontend;

import java.util.HashMap;

public class KeywordsMap {
    private static final HashMap<String, String> KEYWORDS = new HashMap<>();
    static {
        KEYWORDS.put("main", "MAINTK");
        KEYWORDS.put("const", "CONSTTK");
        KEYWORDS.put("int", "INTTK");
        KEYWORDS.put("char", "CHARTK");
        KEYWORDS.put("break", "BREAKTK");
        KEYWORDS.put("continue", "CONTINUETK");
        KEYWORDS.put("if", "IFTK");
        KEYWORDS.put("else", "ELSETK");
        KEYWORDS.put("for", "FORTK");
        KEYWORDS.put("getint", "GETINTTK");
        KEYWORDS.put("getchar", "GETCHARTK");
        KEYWORDS.put("printf", "PRINTFTK");
        KEYWORDS.put("return", "RETURNTK");
        KEYWORDS.put("void", "VOIDTK");
    }
    public KeywordsMap(){
    }

    public String getKeywordType(String keyword){
        return KEYWORDS.get(keyword);
    }

    public boolean isKeyword(String word){
        return KEYWORDS.containsKey(word);
    }
}
