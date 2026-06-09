package frontend;

import java.util.HashMap;

public class ReservedWords {
    private static ReservedWords instance = new ReservedWords();
    HashMap<String, LexType> reWords = new HashMap<>();


    private ReservedWords() {
        this.initReWords();

    }

    public static ReservedWords getInstance() {
        return instance;
    }

    public LexType isReserve(String word) {
        return this.reWords.getOrDefault(word, LexType.IDENFR);
    }

    public LexType isOtherReserve(String word) {
        return this.reWords.getOrDefault(word, LexType.AERROR);
    }

    private void initReWords() {
        this.reWords.put("main", LexType.MAINTK);
        this.reWords.put("const", LexType.CONSTTK);
        this.reWords.put("int", LexType.INTTK);
        this.reWords.put("char", LexType.CHARTK);
        this.reWords.put("break", LexType.BREAKTK);
        this.reWords.put("continue", LexType.CONTINUETK);
        this.reWords.put("if", LexType.IFTK);
        this.reWords.put("else", LexType.ELSETK);
        this.reWords.put("!", LexType.NOT);
        this.reWords.put("&&", LexType.AND);
        this.reWords.put("||", LexType.OR);
        this.reWords.put("for", LexType.FORTK);
        this.reWords.put("getint", LexType.GETINTTK);
        this.reWords.put("getchar", LexType.GETCHARTK);
        this.reWords.put("printf", LexType.PRINTFTK);
        this.reWords.put("return", LexType.RETURNTK);
        this.reWords.put("+", LexType.PLUS);
        this.reWords.put("-", LexType.MINU);
        this.reWords.put("void", LexType.VOIDTK);
        this.reWords.put("*", LexType.MULT);
        this.reWords.put("/", LexType.DIV);
        this.reWords.put("%", LexType.MOD);
        this.reWords.put("<", LexType.LSS);
        this.reWords.put("<=", LexType.LEQ);
        this.reWords.put(">", LexType.GRE);
        this.reWords.put(">=", LexType.GEQ);
        this.reWords.put("==", LexType.EQL);
        this.reWords.put("!=", LexType.NEQ);
        this.reWords.put("=", LexType.ASSIGN);
        this.reWords.put(";", LexType.SEMICN);
        this.reWords.put(",", LexType.COMMA);
        this.reWords.put("(", LexType.LPARENT);
        this.reWords.put(")", LexType.RPARENT);
        this.reWords.put("[", LexType.LBRACK);
        this.reWords.put("]", LexType.RBRACK);
        this.reWords.put("{", LexType.LBRACE);
        this.reWords.put("}", LexType.RBRACE);
    }
}
