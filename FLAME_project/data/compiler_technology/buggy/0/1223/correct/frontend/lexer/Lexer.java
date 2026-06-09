package frontend.lexer;

import config.Config;
import utils.IOUtil;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private static final Lexer instance = new Lexer();
    public static Lexer getInstance() {
        return instance;
    }
    private String source;
    private int curPos = -1;
    private String token;
    private ArrayList<Token> tokens = new ArrayList<>();
    private TokenType tokenType;
    private static final HashMap<String, TokenType> reservedWords = new HashMap<>();
    private int lineNum = 1;
    private long number;
    private final LexerError lexerError = LexerError.getInstance();

    static {
        // 初始化保留字HashMap
        reservedWords.put("main", TokenType.MAINTK);
        reservedWords.put("const", TokenType.CONSTTK);
        reservedWords.put("int", TokenType.INTTK);
        reservedWords.put("char", TokenType.CHARTK);
        reservedWords.put("break", TokenType.BREAKTK);
        reservedWords.put("continue", TokenType.CONTINUETK);
        reservedWords.put("if", TokenType.IFTK);
        reservedWords.put("else", TokenType.ELSETK);
        reservedWords.put("void", TokenType.VOIDTK);
        reservedWords.put("for", TokenType.FORTK);
        reservedWords.put("getint", TokenType.GETINTTK);
        reservedWords.put("getchar", TokenType.GETCHARTK);
        reservedWords.put("printf", TokenType.PRINTFTK);
        reservedWords.put("return", TokenType.RETURNTK);
    }

    // 判断一个标识符是否是保留字
    private static boolean isReservedWord(String word) {
        return reservedWords.containsKey(word);
    }

    // 获取保留字对应的TokenType
    private static TokenType getReservedWordType(String word) {
        return reservedWords.get(word);
    }

    private Token nextToken(){
        clear();
        curPos++;
        while (curPos < source.length() && (source.charAt(curPos) == ' ' || source.charAt(curPos) == '\n'
                || source.charAt(curPos) == '\t')){
            if (source.charAt(curPos) == '\n') {
                lineNum++;
            }
            curPos++;
        }
        if (curPos >= source.length()){
            return null;
        }
        token += source.charAt(curPos);

        if (Character.isLetter(source.charAt(curPos)) || source.charAt(curPos) == '_') {
            curPos++;
            while (curPos < source.length() && (Character.isLetterOrDigit(source.charAt(curPos))
                    || source.charAt(curPos) == '_') ) {
                token += source.charAt(curPos);
                curPos++;
            }
            curPos--;
            if (isReservedWord(token)) {
                tokenType = getReservedWordType(token);
            } else {
                tokenType = TokenType.IDENFR;
            }
        } else if (Character.isDigit(source.charAt(curPos))) {
            curPos++;
            while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
                token += source.charAt(curPos);
                curPos++;
            }
            curPos--;
            number = Long.parseLong(token);
            tokenType = TokenType.INTCON;
        } else if (source.charAt(curPos) == '\"'){
            curPos++;
            while (curPos < source.length() && source.charAt(curPos) != '\"'){
                if (source.charAt(curPos) == '\\'){
                    token += source.charAt(curPos);
                    curPos++;
                }
                token += source.charAt(curPos);
                curPos++;
            }
            token += source.charAt(curPos);
            tokenType = TokenType.STRCON;
        } else if (source.charAt(curPos) == '\'') {
            curPos++;
            while (curPos < source.length() && source.charAt(curPos) != '\'') {
                if (source.charAt(curPos) == '\\'){
                    token += source.charAt(curPos);
                    curPos++;
                }
                token += source.charAt(curPos);
                curPos++;
            }
            token += source.charAt(curPos);
            tokenType = TokenType.CHRCON;
        } else if (source.charAt(curPos) == '!') {
            if (curPos+1 < source.length() && source.charAt(curPos+1) == '=') {
                token += source.charAt(curPos+1);
                curPos++;
                tokenType = TokenType.NEQ;
            } else {
                tokenType = TokenType.NOT;
            }
        } else if (source.charAt(curPos) == '&') {
            if (curPos+1 < source.length() && source.charAt(curPos+1) == '&') {
                token += source.charAt(curPos+1);
                curPos++;
                tokenType = TokenType.AND;
            } else {
                lexerError.addToken(new Token(null, lineNum, token));
            }
        } else if (source.charAt(curPos) == '|') {
            if (curPos+1 < source.length() && source.charAt(curPos+1) == '|') {
                token += source.charAt(curPos+1);
                curPos++;
                tokenType = TokenType.OR;
            } else {
                lexerError.addToken(new Token(null, lineNum, token));
            }
        } else if (source.charAt(curPos) == '+') {
            tokenType = TokenType.PLUS;
        } else if (source.charAt(curPos) == '-') {
            tokenType = TokenType.MINU;
        } else if (source.charAt(curPos) == '*') {
            tokenType = TokenType.MULT;
        } else if (source.charAt(curPos) == '%') {
            tokenType = TokenType.MOD;
        } else if (source.charAt(curPos) == '<') {
            if (curPos+1 < source.length() && source.charAt(curPos+1) == '=') {
                token += source.charAt(curPos+1);
                curPos++;
                tokenType = TokenType.LEQ;
            } else {
                tokenType = TokenType.LSS;
            }
        } else if (source.charAt(curPos) == '>') {
            if (curPos+1 < source.length() && source.charAt(curPos+1) == '=') {
                token += source.charAt(curPos+1);
                curPos++;
                tokenType = TokenType.GEQ;
            } else {
                tokenType = TokenType.GRE;
            }
        } else if (source.charAt(curPos) == '=') {
            if (curPos+1 < source.length() && source.charAt(curPos+1) == '=') {
                token += source.charAt(curPos+1);
                curPos++;
                tokenType = TokenType.EQL;
            } else {
                tokenType = TokenType.ASSIGN;
            }
        } else if (source.charAt(curPos) == ';') {
            tokenType = TokenType.SEMICN;
        } else if (source.charAt(curPos) == ',') {
            tokenType = TokenType.COMMA;
        } else if (source.charAt(curPos) == '(') {
            tokenType = TokenType.LPARENT;
        } else if (source.charAt(curPos) == ')') {
            tokenType = TokenType.RPARENT;
        } else if (source.charAt(curPos) == '[') {
            tokenType = TokenType.LBRACK;
        } else if (source.charAt(curPos) == ']') {
            tokenType = TokenType.RBRACK;
        } else if (source.charAt(curPos) == '{') {
            tokenType = TokenType.LBRACE;
        } else if (source.charAt(curPos) == '}') {
            tokenType = TokenType.RBRACE;
        } else if (source.charAt(curPos) == '/') {
            curPos++;
            if (curPos < source.length() && source.charAt(curPos) == '/') {
                // 单行注释，跳到行尾
                while (curPos < source.length() && source.charAt(curPos) != '\n') { //注意不包括\n，也没有步过
                    curPos++;
                }
                return null;
            } else if (source.charAt(curPos) == '*') {
                // 多行注释，跳到第一个'*/'结束
                curPos++;
                while (curPos < source.length() - 1 && !(source.charAt(curPos) == '*' && source.charAt(curPos + 1) == '/')) {
                    if (source.charAt(curPos) == '\n') {
                        lineNum++;
                    }
                    curPos++;
                }
                curPos += 1;
                return null;
            } else {
                tokenType = TokenType.DIV;
                curPos--;
            }
        }
        return new Token(tokenType, lineNum, token);
    }
    public void run() throws IOException {
        source = IOUtil.readFileToString(Config.getInputFilePath());
        while (curPos < source.length() - 1) {
            Token tk = nextToken();
            if (tk != null) {
                tokens.add(tk);
            }
        }
        ArrayList<String> result = new ArrayList<>();
        if (lexerError.tokenIsEmpty()) {
            for (Token t : tokens) {
                result.add(String.valueOf(t.getTokenType()) + " " + t.getContent());
            }
            IOUtil.writeToFile(Config.getOutputFilePath(), result);
        } else {
            lexerError.error();
        }
    }
    private void clear(){
        token = "";
        tokenType = null;
        number = 0;
    }
}
