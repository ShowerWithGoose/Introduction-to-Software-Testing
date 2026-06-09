package frontend.Lexer;

import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private String source;
    private int curPos;
    private String token;
    private LexType lexType;
    private HashMap<String, LexType> reserveWords;
    private HashMap<String, LexType> delimiter;
    private int lineNum = 1;
    private boolean error;

    public Lexer(String source) {
        this.source = source;
        this.reserveWords = new HashMap<String, LexType>() {
            {
                put("main", LexType.MAINTK);
                put("const", LexType.CONSTTK);
                put("int", LexType.INTTK);
                put("char", LexType.CHARTK);
                put("break", LexType.BREAKTK);
                put("continue", LexType.CONTINUETK);
                put("if", LexType.IFTK);
                put("else", LexType.ELSETK);
                put("for", LexType.FORTK);
                put("getint", LexType.GETINTTK);
                put("getchar", LexType.GETCHARTK);
                put("printf", LexType.PRINTFTK);
                put("return", LexType.RETURNTK);
                put("void", LexType.VOIDTK);
            }
        };
        this.delimiter = new HashMap<String, LexType>() {
            {
                put("+", LexType.PLUS);
                put("-", LexType.MINU);
                put("*", LexType.MULT);
                put("!", LexType.NOT);
                put("/", LexType.DIV);
                put("%", LexType.MOD);
                put("<", LexType.LSS);
                put(">", LexType.GRE);
                put("=", LexType.ASSIGN);
                put(";", LexType.SEMICN);
                put(",", LexType.COMMA);
                put("(", LexType.LPARENT);
                put(")", LexType.RPARENT);
                put("[", LexType.LBRACK);
                put("]", LexType.RBRACK);
                put("{", LexType.LBRACE);
                put("}", LexType.RBRACE);
                put("&&", LexType.AND);
                put("||", LexType.OR);
                put("<=", LexType.LEQ);
                put(">=", LexType.GEQ);
                put("==", LexType.EQL);
                put("!=", LexType.NEQ);
            }
        };
    }

    public String getToken() {
        return token;
    }

    public LexType getLexType() {
        return lexType;
    }

    public ArrayList<LexType> preRead(int num) {
        ArrayList<LexType> lexTypes = new ArrayList<>();
        int curPos1 = curPos;
        String token1 = token;
        LexType lexType1 = lexType;
        int lineNum1 = lineNum;
        boolean error1 = error;
        for (int i = 0; i < num; i++) {
            next();
            lexTypes.add(lexType);
        }
        curPos = curPos1;
        token = token1;
        lexType = lexType1;
        lineNum = lineNum1;
        error = error1;
        return lexTypes;
    }

    public Boolean preReadCompare(LexType type) {
        boolean flag = false;
        int curPos1 = curPos;
        String token1 = token;
        LexType lexType1 = lexType;
        int lineNum1 = lineNum;
        boolean error1 = error;
        for (; ; ) {
            if (lexType == type) {
                flag = true;
                break;
            } else if (lexType == LexType.SEMICN) {
                break;
            }next();
        }
        curPos = curPos1;
        token = token1;
        lexType = lexType1;
        lineNum = lineNum1;
        error = error1;
        return flag;
    }

    public boolean next() {
        if (!posIsValid()) {
            return false;
        } else {
            token = "";
            error = false;
            if (posIsValid()) {
                while (isTab() || isSpace() || isEnter()) {
                    curPos++;
                }
            }
            if (!posIsValid()) {
                return false;
            }
            if (isIdentifier()) {
                while (isIdentifier() || isDigit()) {
                    token = token + source.charAt(curPos);
                    curPos++;
                }
                lexType = reserveWords.getOrDefault(token, LexType.IDENFR);
            } else if (isDigit()) {
                while (isDigit()) {
                    token = token + source.charAt(curPos);
                    curPos++;
                }
                lexType = LexType.INTCON;
            } else if (isSingleDelimiter()) {
                token = token + source.charAt(curPos);
                curPos++;
                lexType = delimiter.get(token);
            } else {
                char a = source.charAt(curPos);
                if (a == '!' || a == '>' || a == '<' || a == '=') {
                    token = token + source.charAt(curPos);
                    curPos++;
                    if (posIsValid() && source.charAt(curPos) == '=') {
                        token = token + source.charAt(curPos);
                        curPos++;
                    }
                    lexType = delimiter.get(token);
                } else if (a == '&' || a == '|') {
                    token = token + source.charAt(curPos);
                    curPos++;
                    if (posIsValid() && source.charAt(curPos) == a) {
                        token = token + source.charAt(curPos);
                        curPos++;
                    } else if (posIsValid()) {
                        error = true;
                    }
                    lexType = delimiter.get(token);
                } else if (a == '"') {
                    token = token + source.charAt(curPos);
                    curPos++;
                    while (source.charAt(curPos) != '"'||source.charAt(curPos-1)=='\\') {
                        token = token + source.charAt(curPos);
                        curPos++;
                    }
                    token = token + source.charAt(curPos);
                    curPos++;
                    lexType = LexType.STRCON;
                } else if (a == '\'') {
                    token = token + source.charAt(curPos);
                    curPos++;
                    while (source.charAt(curPos) != '\''||source.charAt(curPos-1)=='\\') {
                        token = token + source.charAt(curPos);
                        curPos++;
                    }
                    token = token + source.charAt(curPos);
                    curPos++;
                    lexType = LexType.CHRCON;
                } else if (a == '/') {
                    token = token + source.charAt(curPos);
                    curPos++;
                    if (posIsValid() && source.charAt(curPos) == '/') {
                        token = token + source.charAt(curPos);
                        curPos++;
                        while (posIsValid() && !isEnter()) {
                            token = token + source.charAt(curPos);
                            curPos++;
                        }
                        if (posIsValid()) {
                            token = token + source.charAt(curPos);
                            curPos++;
                        }
                        lexType = LexType.NOTE;
                    } else if (posIsValid() && source.charAt(curPos) == '*') {
                        token = token + source.charAt(curPos);
                        curPos++;
                        if (posIsValid()) {
                            while (posIsValid() && source.charAt(curPos) != '*') {
                                token = token + source.charAt(curPos);
                                curPos++;
                                isEnter();
                            }
                            while (posIsValid() && source.charAt(curPos) == '*') {
                                token = token + source.charAt(curPos);
                                curPos++;
                            }
                            if (posIsValid() && source.charAt(curPos) == '/') {
                                token = token + source.charAt(curPos);
                                curPos++;
                                lexType = LexType.NOTE;
                            }
                        }
                    } else {
                        lexType = LexType.DIV;
                    }
                }
            }
            return true;
        }
    }

    private boolean posIsValid() {
        return curPos < source.length();
    }

    private boolean isTab() {
        return posIsValid() && source.charAt(curPos) == '\t';
    }

    private boolean isSpace() {
        return posIsValid() && source.charAt(curPos) == ' ';
    }

    private boolean isEnter() {
        if (posIsValid() && source.charAt(curPos) == '\n') {
            lineNum++;
            return true;
        } else if (curPos < source.length() - 1 && source.charAt(curPos) == '\r' &&
                source.charAt(curPos + 1) == '\n') {
            lineNum++;
            curPos++;
            return true;
        }
        return false;
    }

    private boolean isDigit() {
        return posIsValid() && Character.isDigit(source.charAt(curPos));
    }

    private boolean isIdentifier() {
        return posIsValid() && (Character.isLetter(source.charAt(curPos)) ||
                source.charAt(curPos) == '_');
    }

    private boolean isSingleDelimiter() {
        if (!posIsValid()) {
            return false;
        }
        char curChar = source.charAt(curPos);
        return "+-*%,;()[]{}".indexOf(curChar) != -1;
    }

    public int getLineNum() {
        return lineNum;
    }

    public boolean isError() {
        return error;
    }
}
