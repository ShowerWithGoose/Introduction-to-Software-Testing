package frontend.Lexer.Token;

import java.util.HashMap;

public enum TokenType {
    IDENFR,
    INTCON,
    STRCON,
    CHRCON,
    MAINTK,
    CONSTTK,
    INTTK,
    CHARTK,
    BREAKTK,
    CONTINUETK,
    IFTK,
    ELSETK,
    NOT,
    AND,
    OR,
    FORTK,
    GETINTTK,
    GETCHARTK,
    PRINTFTK,
    RETURNTK,
    PLUS,
    MINU,
    VOIDTK,
    MULT,
    DIV,
    MOD,
    LSS,
    LEQ,
    GRE,
    GEQ,
    EQL,
    NEQ,
    ASSIGN,
    SEMICN,
    COMMA,
    LPARENT,
    RPARENT,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE,
    ERRORA;

    public static HashMap<String, TokenType> keyWordMap;

    public static void initKeyWordMap() {
        keyWordMap = new HashMap<>();
        keyWordMap.put("main", MAINTK);
        keyWordMap.put("const", CONSTTK);
        keyWordMap.put("int", INTTK);
        keyWordMap.put("char", CHARTK);
        keyWordMap.put("break", BREAKTK);
        keyWordMap.put("continue", CONTINUETK);
        keyWordMap.put("if", IFTK);
        keyWordMap.put("else", ELSETK);
        keyWordMap.put("!", NOT);
        keyWordMap.put("&&", AND);
        keyWordMap.put("||", OR);
        keyWordMap.put("for", FORTK);
        keyWordMap.put("getint", GETINTTK);
        keyWordMap.put("getchar", GETCHARTK);
        keyWordMap.put("printf", PRINTFTK);
        keyWordMap.put("return", RETURNTK);
        keyWordMap.put("+", PLUS);
        keyWordMap.put("-", MINU);
        keyWordMap.put("void", VOIDTK);
        keyWordMap.put("*", MULT);
        keyWordMap.put("/", DIV);
        keyWordMap.put("%", MOD);
        keyWordMap.put("<", LSS);
        keyWordMap.put("<=", LEQ);
        keyWordMap.put(">", GRE);
        keyWordMap.put(">=", GEQ);
        keyWordMap.put("==", EQL);
        keyWordMap.put("!=", NEQ);
        keyWordMap.put("=", ASSIGN);
        keyWordMap.put(";", SEMICN);
        keyWordMap.put(",", COMMA);
        keyWordMap.put("(", LPARENT);
        keyWordMap.put(")", RPARENT);
        keyWordMap.put("[", LBRACK);
        keyWordMap.put("]", RBRACK);
        keyWordMap.put("{", LBRACE);
        keyWordMap.put("}", RBRACE);
    }

    @Override
    public String toString() {
        return this.name();
    }
}
