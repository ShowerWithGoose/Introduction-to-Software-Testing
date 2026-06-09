package frontend;

import frontend.Error.ErrorItem;
import util.Logger;

import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;

public class Lexer {
    private int lineNum;
    private char curChar;
    private TokenList tokenList;
    private Token token;
    private String sym;
    private final String code;
    private final int len;
    private int pos = 0;
    private static final HashMap<String, TokenType> reserve = new HashMap<String, TokenType>();

    static {
        reserve.put("if", TokenType.IFTK);
        reserve.put("else", TokenType.ELSETK);
        reserve.put("for", TokenType.FORTK);
        reserve.put("return", TokenType.RETURNTK);
        reserve.put("break", TokenType.BREAKTK);
        reserve.put("continue", TokenType.CONTINUETK);
        reserve.put("int", TokenType.INTTK);
        reserve.put("char", TokenType.CHARTK);
        reserve.put("void", TokenType.VOIDTK);
        reserve.put("getint", TokenType.GETINTTK);
        reserve.put("getchar", TokenType.GETCHARTK);
        reserve.put("printf", TokenType.PRINTFTK);
        reserve.put("main", TokenType.MAINTK);
        reserve.put("const", TokenType.CONSTTK);
    }

    public Lexer(InputStream inputStream) throws IOException {
        code = new String(inputStream.readAllBytes(), StandardCharsets.UTF_8);
        len = code.length();
        this.lineNum = 1;
        this.tokenList = new TokenList();
        run();
    }

    public void run() {
        while (pos < len) {
            int ret = getSym();
            if (ret == -1) {
                continue;
            }
            tokenList.append(token);
        }
    }

    public TokenList getTokenList() {
        return tokenList;
    }

    public void getChar() {
        curChar = code.charAt(pos++);
    }

    public void retract() {
        pos--;
    }

    public boolean isSpace() {
        return Character.isWhitespace(curChar);
    }

    public boolean isDigit() {
        return Character.isDigit(curChar);
    }

    public boolean isLetter() {
        return Character.isLetter(curChar) || curChar == '_';
    }

    public boolean isReserve(String str) {
        return reserve.containsKey(str);
    }

    public int getSym() {
        sym = "";
        getChar();
        while (pos < len && isSpace()) {
            if (curChar == '\n') {
                lineNum++;
            }
            getChar();
        }
        if (isLetter()) {
            while (pos < len && (isLetter() || isDigit())) {
                sym += curChar;
                getChar();
            }
            retract();
            if (isReserve(sym)) {
                token = new Token(reserve.get(sym), sym, lineNum);
            } else {
                token = new Token(TokenType.IDENFR, sym, lineNum);
            }
        } else if (isDigit()) {
            while (pos < len && isDigit()) {
                sym += curChar;
                getChar();
            }
            retract();
            token = new Token(TokenType.INTCON, sym, lineNum);
        } else {
            switch (curChar) {
                case '"':
                    sym += curChar;
                    getChar();
                    while (pos < len && curChar != '"') {
                        sym += curChar;
                        getChar();
                    }
                    if (curChar == '"') {
                        sym += curChar;
                        token = new Token(TokenType.STRCON, sym, lineNum);
                    } else {
                        System.err.println("双引号未结束 Expected \" but got " + curChar);
                    }
                    break;
                case '\'':
                    sym += curChar;
                    getChar();
                    if (curChar == '\\') {
                        sym += curChar;
                        getChar();
                        sym += curChar;
                        getChar();
                    } else {
                        sym += curChar;
                        getChar();
                    }
                    if (curChar == '\'') {
                        sym += curChar;
                        token = new Token(TokenType.CHRCON, sym, lineNum);
                    } else {
                        System.err.println("单引号未结束 Expected ' but got " + curChar);
                    }
                    break;
                case '+':
                    token = new Token(TokenType.PLUS, "+", lineNum);
                    break;
                case '-':
                    token = new Token(TokenType.MINU, "-", lineNum);
                    break;
                case '*':
                    token = new Token(TokenType.MULT, "*", lineNum);
                    break;
                case '/':
                    // div or // or /* */
                    getChar();
                    if (curChar == '/') {
                        while (pos < len && curChar != '\n') {
                            getChar();
                        }
                        lineNum++;
                        return -1;
                    } else if (curChar == '*') {
                        getChar();
                        while (pos < len) {
                            if (curChar == '\n') {
                                lineNum++;
                            } else if (curChar == '*') {
                                getChar();
                                if (curChar == '/') {
                                    break;
                                } else {
                                    retract();
                                }
                            }
                            getChar();
                        }
                        return -1;
                    } else {
                        retract();
                        token = new Token(TokenType.DIV, "/", lineNum);
                    }
                    break;
                case '%':
                    token = new Token(TokenType.MOD, "%", lineNum);
                    break;
                case '=':
                    getChar();
                    if (curChar == '=') {
                        token = new Token(TokenType.EQL, "==", lineNum);
                    } else {
                        retract();
                        token = new Token(TokenType.ASSIGN, "=", lineNum);
                    }
                    break;
                case '!':
                    getChar();
                    if (curChar == '=') {
                        token = new Token(TokenType.NEQ, "!=", lineNum);
                    } else {
                        retract();
                        token = new Token(TokenType.NOT, "!", lineNum);
                    }
                    break;
                case '<':
                    getChar();
                    if (curChar == '=') {
                        token = new Token(TokenType.LEQ, "<=", lineNum);
                    } else {
                        retract();
                        token = new Token(TokenType.LSS, "<", lineNum);
                    }
                    break;
                case '>':
                    getChar();
                    if (curChar == '=') {
                        token = new Token(TokenType.GEQ, ">=", lineNum);
                    } else {
                        retract();
                        token = new Token(TokenType.GRE, ">", lineNum);
                    }
                    break;
                case '&':
                    getChar();
                    token = new Token(TokenType.AND, "&&", lineNum);
                    if (curChar != '&') {
                        ErrorItem error = new ErrorItem(lineNum, "a", "Expected && but got &");
                        Logger.logger.error(error);
//                        throw new RuntimeException("Expected && but got &");
                    }
                    break;
                case '|':
                    getChar();
                    token = new Token(TokenType.OR, "||", lineNum);
                    if (curChar != '|') {
                        ErrorItem error = new ErrorItem(lineNum, "a", "Expected || but got |");
                        Logger.logger.error(error);
//                        throw new RuntimeException("Expected || but got |");
                    }
                    break;
                case '(':
                    token = new Token(TokenType.LPARENT, "(", lineNum);
                    break;
                case ')':
                    token = new Token(TokenType.RPARENT, ")", lineNum);
                    break;
                case '{':
                    token = new Token(TokenType.LBRACE, "{", lineNum);
                    break;
                case '}':
                    token = new Token(TokenType.RBRACE, "}", lineNum);
                    break;
                case '[':
                    token = new Token(TokenType.LBRACK, "[", lineNum);
                    break;
                case ']':
                    token = new Token(TokenType.RBRACK, "]", lineNum);
                    break;
                case ',':
                    token = new Token(TokenType.COMMA, ",", lineNum);
                    break;
                case ';':
                    token = new Token(TokenType.SEMICN, ";", lineNum);
                    break;
                default:
                    token = new Token(TokenType.EOF, "", lineNum);
//                    System.err.println("Unexpected character {" + curChar + "} : " + (int) curChar);
            }
        }
        return 0;
    }
}
