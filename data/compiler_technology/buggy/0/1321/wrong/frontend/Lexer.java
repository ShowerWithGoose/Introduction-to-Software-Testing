package frontend;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Lexer {
    private static final Lexer instance = new Lexer();
    public static Lexer getInstace() {
        return instance;
    }

    private int lineNum = 1;
    private int curPos = 0;
    private int maxPos;
    private String source;
    private ArrayList<Token> tokens = new ArrayList<>();
    private boolean parseActivate = true;
    private boolean errorState = false;
    private ArrayList<Error> errors = new ArrayList<>();

    public void printTokens() {
        for (Token token : tokens) {
            System.out.println(token.toString());
        }
    }

    public void printErrors() {
        for (Error error : errors) {
            System.out.println(error.toString());
        }
    }

    public enum TokenType {
        IDENFR,
        INTCON,
        STRCON,
        CHRCON,
        MAINTK,
        CONSTTK,
        INTTK,
        CHARTK,
        VOIDTK,
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
        BOIDTK,
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
    }
    //stolen from üå∏üçÉ
    private final Map<String, TokenType> reserveWords = new HashMap<String, TokenType>() {{
        put("main", TokenType.MAINTK);
        put("const", TokenType.CONSTTK);
        put("int", TokenType.INTTK);
        put("char", TokenType.CHARTK);
        put("void", TokenType.VOIDTK);
        put("break", TokenType.BREAKTK);
        put("continue", TokenType.CONTINUETK);
        put("if", TokenType.IFTK);
        put("else", TokenType.ELSETK);
        put("for", TokenType.FORTK);
        put("getint", TokenType.GETINTTK);
        put("getchar", TokenType.GETCHARTK);
        put("printf", TokenType.PRINTFTK);
        put("return", TokenType.RETURNTK);
    }};
    private final Map<String, TokenType> independentTokens = new HashMap<String, TokenType>() {{
        put("+", TokenType.PLUS);
        put("-", TokenType.MINU);
        put("*", TokenType.MULT);
        put("%", TokenType.MOD);
        put(";", TokenType.SEMICN);
        put(",", TokenType.COMMA);
        put("(", TokenType.LPARENT);
        put(")", TokenType.RPARENT);
        put("[", TokenType.LBRACK);
        put("]", TokenType.RBRACK);
        put("{", TokenType.LBRACE);
        put("}", TokenType.RBRACE);
    }};
    //coupleTokensÊúâÁÇπÂ∞ëÔºåÂêéÁª≠Â¶ÇÊûúÈúÄË¶ÅÂèØ‰ª•ËøõË°åÊãìÂ±ï
    private final Map<String, TokenType> indOrCouTokens = new HashMap<String, TokenType>() {{
        put("<", TokenType.LSS);
        put(">", TokenType.GRE);
        put("=", TokenType.ASSIGN);
        put("!", TokenType.NOT);
    }};
    private Map<String, TokenType> equalTokens = new HashMap<String, TokenType>() {{
        put("<", TokenType.LEQ);
        put(">", TokenType.GEQ);
        put("=", TokenType.EQL);
        put("!", TokenType.NEQ);
    }};

    public boolean parse(String source) {
        this.source = source;
        this.source += ' ';
        this.parseActivate = true;
        this.maxPos = source.length();
        while(this.parseActivate) {
            //getNextToken
            Token token = getNextToken();
            if(token != null) {
                tokens.add(token);
                // System.out.println(token.toString());
            }
            //ÈîôËØØÂ§ÑÁêÜ
        }
        return this.errorState;
    }

    /**
     * 
     * @return true: ËØªÂà∞ÊúÄÂêé‰∏Ä‰∏™Â≠óÁ¨¶
     */
    private boolean ignoreNextChar() {
        if(peekNextChar() == '\n') {
            lineNum++;
        }
        curPos++;
        if(curPos >= maxPos) {
            parseActivate = false;
        }
        return curPos >= maxPos;
    }

    private char peekNextChar() {
        return source.charAt(curPos);
    }

    private Token getNextToken() {
        Token token;
        StringBuilder word = new StringBuilder();
        TokenType type = null;
        int state = 0;
        //Êª§ÂéªÁ©∫Ê†º‰∏éÂõûËΩ¶
        while(peekNextChar() == ' ' || peekNextChar() == '\n') {
            if(ignoreNextChar()) {
                return null;
            }
        }
        boolean finish = false;
        while(!finish && parseActivate) {
            char curChar = peekNextChar();
            switch (state) {
                case 0://ÂàùÂßãÁä∂ÊÄÅ
                    if(isIdentifierNondigit(curChar)) {
                        state = 1;
                    }
                    else if(isNonZeroDigit(curChar)) {
                        state = 2;
                    }
                    else if(curChar == '0') {//Êï∞Â≠ó0
                        type = TokenType.INTCON;
                        finish = true;
                    }
                    else if(curChar == '\"') {
                        state = 3;
                    }
                    else if(curChar == '\'') {
                        state = 5;
                    }
                    else if(isIndependentToken(curChar)) {//‰∏Ä‰∫õÁã¨Á´ãÁ¨¶Âè∑
                        finish = true;
                        for (Map.Entry<String, TokenType> independentToken : independentTokens.entrySet()) {
                            if(independentToken.getKey().equals(Character.toString(curChar))) {
                                type = independentToken.getValue();
                                break;
                            }
                        }
                        if(type == null) {
                            //ÈîôËØØËæìÂá∫
                        }
                    }
                    else if(curChar == '|') {
                        state = 9;
                    }
                    else if(curChar == '&') {
                        state = 10;
                    }
                    else if(isIndOrCouToken(curChar)) {
                        state = 11;
                    }
                    else if(curChar == '/') {
                        state = 13;
                    }
                    else {
                        state = 18;
                    }
                    ignoreNextChar();
                    word.append(curChar);
                    break;
                case 1://Ê†áËØÜÁ¨¶ or ÂÖ≥ÈîÆÂ≠ó
                    if(isIdentifierNondigit(curChar) || Character.isDigit(curChar)) {
                        word.append(curChar);
                        ignoreNextChar();
                    }
                    else {
                        finish = true;
                        //ÂØªÊâæÂÖ≥ÈîÆÂ≠ó
                        for (Map.Entry<String, TokenType> reserveWord : reserveWords.entrySet()) {
                            if(reserveWord.getKey().equals(word.toString())) {
                                type = reserveWord.getValue();
                                break;
                            }
                        }
                        if(type == null) {
                            type = TokenType.IDENFR;
                        }
                    }
                    break;
                case 2://INT Â∏∏Èáè
                    if(Character.isDigit(curChar)) {
                        word.append(curChar);
                        finish = ignoreNextChar();
                    }
                    else {
                        finish = true;
                        type = TokenType.INTCON;
                    }
                    break;
                case 3://STRING Â∏∏Èáè
                    if(curChar == '\"') {
                        word.append(curChar);
                        finish = true;
                        type = TokenType.STRCON;
                        ignoreNextChar();
                    }
                    else {
                        word.append(curChar);
                        finish = ignoreNextChar();
                    }
                    break;
                case 5://CHAR Â∏∏Èáè
                    if(curChar == '\'') {
                        word.append(curChar);
                        finish = true;
                        type = TokenType.CHRCON;
                        ignoreNextChar();
                    }
                    else if(curChar == '\\') {
                        word.append(curChar);
                        ignoreNextChar();
                        word.append(peekNextChar());
                        ignoreNextChar();
                    }
                    else {
                        word.append(curChar);
                        ignoreNextChar();
                    }
                    break;
                case 9:// ||
                    if(curChar == '|') {
                        word.append(curChar);
                        finish = true;
                        type = TokenType.OR;
                        ignoreNextChar();
                    }
                    else {
                        //ÈîôËØØÂ§ÑÁêÜ
                        errors.add(new Error("LEX", lineNum, 'a'));
                        this.errorState = true;
                        return null;
                    }
                    break;
                case 10:// &&
                    if(curChar == '&') {
                        word.append(curChar);
                        finish = true;
                        type = TokenType.AND;
                        ignoreNextChar();
                    }
                    else {
                        //ÈîôËØØÂ§ÑÁêÜ
                        errors.add(new Error("LEX", lineNum, 'a'));
                        this.errorState = true;
                        return null;
                    }
                    break;
                case 11:// <>=!‰∏é=
                    if(curChar == '=') {
                        for(Map.Entry<String, TokenType> equalToken: equalTokens.entrySet()) {
                            if(word.toString().equals(equalToken.getKey())) {
                                word.append(curChar);
                                type = equalToken.getValue();
                                finish = true;
                                ignoreNextChar();
                            }
                        }
                        if(type == null) {
                            //ÈîôËØØÂ§ÑÁêÜ
                            System.out.println("ERROR in case 11");
                        }
                    }
                    else {
                        for(Map.Entry<String, TokenType> indOrCouToken: indOrCouTokens.entrySet()) {
                            if(word.toString().equals(indOrCouToken.getKey())) {
                                type = indOrCouToken.getValue();
                                finish = true;
                            }
                        }
                        if(type == null) {
                            //ÈîôËØØÂ§ÑÁêÜ
                            System.out.println("ERROR in case 11");
                        }
                    }
                    break;
                case 13:// Êî∂Âà∞"/"
                    if(curChar == '/') {
                        state = 14;
                        ignoreNextChar();
                    }
                    else if(curChar == '*') {
                        state = 15;
                        ignoreNextChar();
                    }
                    else {
                        type = TokenType.DIV;
                        finish = true;
                    }
                    break;
                case 14:// Êî∂Âà∞"//"
                    if(curChar == '\n') {
                        ignoreNextChar();
                        return null;
                    }
                    else {
                        finish = ignoreNextChar();
                    }
                    break;
                case 15:// Êî∂Âà∞"/*"
                    if(curChar == '*') {
                        state = 16;
                        ignoreNextChar();
                    }
                    else{
                        ignoreNextChar();
                    }
                    break;
                case 16:// Êî∂Âà∞"/*XX*"
                    if(curChar == '*') {
                        ignoreNextChar();
                    }
                    else if(curChar == '/') {
                        state = 17;
                        ignoreNextChar();
                    }
                    else {
                        state = 15;
                        ignoreNextChar();
                    }
                    break;
                case 17:// Êî∂Âà∞"/*XX*/"
                    return null;
                case 18://ÈîôËØØÂ§ÑÁêÜ
                    return null;
                default:
                    break;
            }
        }
        token = new Token(type, word.toString());
        return token;
    }

    private boolean isIdentifierNondigit(char c) {
        return c == '_' || Character.isLetter(c);
    }

    private boolean isIndependentToken(char c) {
        return c == '+' || c == '-' || c == '*' || c == '%' || c == ';' || c == ',' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
    }

    /**"<>=!" Âõõ‰∏™Êó¢ÂèØÁã¨Á´ãÂá∫Áé∞ÂèàÂèØ‰ª•‰∏é'='Áõ∏ËøûÁöÑÁ¨¶Âè∑ */
    private boolean isIndOrCouToken(char c) {
        return c == '<' || c == '>' || c == '=' || c == '!';
    }

    private boolean isNonZeroDigit(char c) {
        return Character.isDigit(c) && c != '0';
    }

    public int getLineNum() {
        return lineNum;
    }
}
