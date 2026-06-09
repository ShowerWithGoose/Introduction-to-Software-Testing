package frontend;

import static frontend.TypeCode.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;

public class Lexer {
    private BufferedReader in;

    private int column = 0;

    private int line = 1;

    private int len;

    private Token curToken;

    private  String curLine;

    private boolean lineCmt = false;

    private boolean blockCmt = false;

    private static final HashMap<String, TypeCode> tk2type = new HashMap<>();

    static {
        tk2type.put("!", NOT);
        tk2type.put("+", PLUS);
        tk2type.put("-", MINU);
        tk2type.put("*", MULT);
        tk2type.put("/", DIV);
        tk2type.put("%", MOD);
        tk2type.put("<", LSS);
        tk2type.put(">", GRE);
        tk2type.put("=", ASSIGN);
        tk2type.put(";", SEMICN);
        tk2type.put(",", COMMA);
        tk2type.put("(", LPARENT);
        tk2type.put(")", RPARENT);
        tk2type.put("[", LBRACK);
        tk2type.put("]", RBRACK);
        tk2type.put("{", LBRACE);
        tk2type.put("}", RBRACE);

        tk2type.put("&&", AND);
        tk2type.put("||", OR);
        tk2type.put("<=", LEQ);
        tk2type.put(">=", GEQ);
        tk2type.put("==", EQL);
        tk2type.put("!=", NEQ);

        tk2type.put("main", MAINTK);
        tk2type.put("const", CONSTTK);
        tk2type.put("int", INTTK);
        tk2type.put("char", CHARTK);
        tk2type.put("break", BREAKTK);
        tk2type.put("continue", CONTINUETK);
        tk2type.put("if", IFTK);
        tk2type.put("else", ELSETK);
        tk2type.put("for", FORTK);
        tk2type.put("getint", GETINTTK);
        tk2type.put("getchar", GETCHARTK);
        tk2type.put("printf", PRINTFTK);
        tk2type.put("return", RETURNTK);
        tk2type.put("void", VOIDTK);
    }

    public Lexer(BufferedReader in) throws IOException {
        this.in = in;
        curLine = in.readLine();
        getLen();
    }

    private void nextLine() throws IOException {
        column = 0;
        curLine = in.readLine();
        lineCmt = false;
        line++;
        getLen();
    }

    public void getLen() {
        if (curLine == null) {
            len = 0;
        } else {
            len = curLine.length();
        }
    }

    private boolean isIdent(char ch) {
        return Character.isLowerCase(ch) || Character.isUpperCase(ch) || ch == '_';
    }

    public Token getToken() throws IOException {
        if (curLine == null) {
            return new Token(EOF, line);
        } else {
            while (column < len) {
                if (blockCmt) {
                    int end = curLine.indexOf("*/", column);
                    if (end == -1) {
                        nextLine();
                    } else {
                        column = end + 2;
                        blockCmt = false;
                        if (column >= len) {
                            nextLine();
                        }
                    }
                    return getToken();
                } else if (lineCmt) {
                    nextLine();
                    return getToken();
                }
                char ch = curLine.charAt(column);
                if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') {
                    column++;
                } else if (Character.isDigit(ch)) {
                    return parseInt();
                } else if (Character.isLowerCase(ch) || Character.isUpperCase(ch) || ch == '_') {
                    return parseIdentOrReserve();
                } else if (ch == '\"') {
                    return parseStr();
                } else if (ch == '\'') {
                    return parseChr();
                } else if (ch == '/'){
                    parseCmt();
                } else {
                    return parseOthers();
                }
            }
            nextLine();
            return getToken();
        }
    }

    private Token parseInt() {
        char ch = curLine.charAt(column);
        int value = ch - '0';
        while (++column < len) {
            ch = curLine.charAt(column);
            if (Character.isDigit(ch)) {
                value *= 10;
                value += ch - '0';
            } else {
                break;
            }
        }
        return new Token(INTCON, line, value);
    }

    private Token parseIdentOrReserve() {
        char ch = curLine.charAt(column);
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(ch);
        while (++column < len) {
            ch = curLine.charAt(column);
            if (Character.isDigit(ch) || isIdent(ch)) {
                stringBuilder.append(ch);
            } else {
                break;
            }
        }
        String tkStr = stringBuilder.toString();
        return new Token(tk2type.getOrDefault(tkStr, IDENFR), line, tkStr);
    }

    private Token parseStr() {
        char ch = curLine.charAt(column);
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(ch);
        while (++column < len) {
            ch = curLine.charAt(column);
            if (ch == '\\') {
                stringBuilder.append(ch);
                column++;
                ch = curLine.charAt(column);
                if (ch == '\"' || ch == '\'' || ch == '\\') {
                    stringBuilder.append(ch);
                } else {
                    column--;
                }
            } else if (ch == '\"') {
                stringBuilder.append(ch);
                column++;
                break;
            } else {
                stringBuilder.append(ch);
            }
        }
        return new Token(STRCON, line, stringBuilder.toString());
    }

    private Token parseChr() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(peekChr());
        char ch = curLine.charAt(column);
        if (ch == '\\') {
            stringBuilder.append(peekChr());
            stringBuilder.append(peekChr());
            stringBuilder.append(peekChr());
        } else {
            stringBuilder.append(peekChr());
            stringBuilder.append(peekChr());
        }
        return new Token(CHRCON, line, stringBuilder.toString());
    }

    private void parseCmt() {
        column++;
        char ch = curLine.charAt(column);
        if (ch == '/') {
            lineCmt = true;
            column++;
        } else if (ch == '*') {
            blockCmt = true;
            column++;
        } else {
            System.err.println("Undefined suffix of /");
        }
    }

    private Token parseOthers() {
        char ch = curLine.charAt(column);
        switch(ch) {
            case '|':
            case '&':
                if (++column < len && curLine.charAt(column) == ch) {
                    column++;
                    return new Token(tk2type.get(String.valueOf(ch) + ch), line);
                } else {
                    return new Token(ERR, line, "a");
                }
            case '!':
            case '=':
            case '<':
            case '>':
                if (++column < len && curLine.charAt(column) == '=') {
                    column++;
                    return new Token(tk2type.get(ch + "="), line);
                } else {
                    return new Token(tk2type.get(String.valueOf(ch)), line);
                }
            default:
                column++;
                return new Token(tk2type.getOrDefault(String.valueOf(ch), UNDEFINED), line);
        }
    }

    private char peekChr() {
        char ch = curLine.charAt(column);
        column++;
        return ch;
    }
}
