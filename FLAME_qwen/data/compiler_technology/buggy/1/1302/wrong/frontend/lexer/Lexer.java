package frontend.lexer;

import frontend.error.ErrorList;

import java.io.IOException;
import java.io.PushbackInputStream;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private PushbackInputStream source;
    private int curLine = 1;
    private char curChar;
    private Token curToken;
    private final HashMap<String, LexType> reservedWords = new HashMap<>();
    private ArrayList<Token> tokens;


    public  Lexer(PushbackInputStream source) throws IOException {
        this.source = source;
        tokens = null;
        curChar = (char) source.read();
        reservedWords.put("main", LexType.MAINTK);
        reservedWords.put("const", LexType.CONSTTK);
        reservedWords.put("int", LexType.INTTK);
        reservedWords.put("char", LexType.CHARTK);
        reservedWords.put("void", LexType.VOIDTK);
        reservedWords.put("break", LexType.BREAKTK);
        reservedWords.put("continue", LexType.CONTINUETK);
        reservedWords.put("if", LexType.IFTK);
        reservedWords.put("else", LexType.ELSETK);
        reservedWords.put("for", LexType.FORTK);
        reservedWords.put("getint", LexType.GETINTTK);
        reservedWords.put("getchar", LexType.GETCHARTK);
        reservedWords.put("printf", LexType.PRINTFTK);
        reservedWords.put("return", LexType.RETURNTK);
    }

    // 处理下一个字符
    public void next() throws IOException {
        curChar = (char) source.read();
    }

    public ArrayList<Token> getTokens() {
        if (tokens != null) {
            return tokens;
        }
        tokens = new ArrayList<>();
        try {
            while (true) {
                Token token = getToken();
                // System.out.println(token);
                if (token.getLexType() == LexType.EOF) {
                    break;
                } else {
                    tokens.add(token);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return tokens;
    }

    public Token getToken() throws IOException {
        while (Character.isWhitespace(curChar)) {
            if (curChar == '\n') {
                curLine++;
            }
            next();
        }
        if (curChar == '\uFFFF') {
            return new Token(LexType.EOF, "EOF", curLine);
        } else if (curChar == '+') {
            next();
            return new Token(LexType.PLUS, "+", curLine);
        } else if (curChar == '-') {
            next();
            return new Token(LexType.MINU, "-", curLine);
        } else if (curChar == '*') {
            next();
            return new Token(LexType.MULT, "*", curLine);
        } else if (curChar == '/') {
            next();
            if (curChar == '/') {
                // 单行注释
                while (curChar!= '\n' && curChar!= '\uffff') {
                    next();
                }
                if (curChar == '\uffff') {
                    return new Token(LexType.EOF, "EOF", curLine);
                } else {
                    curLine++;
                    next();
                    return getToken();
                }
            } else if (curChar == '*') {
                // 多行注释
                next();
                while (true) {
                    if (curChar == '\uffff') {
                        throw new IOException("Unexpected EOF in comment");
                    }
                    if (curChar == '\n') {
                        curLine++;
                    }
                    if (curChar == '*') {
                        next();
                        if (curChar == '/') {
                            next();
                            break;
                        } else {
                            source.unread(curChar);
                        }
                    }
                    next();
                }
                return getToken();
            } else {
                return new Token(LexType.DIV, "/", curLine);
            }
        } else if (curChar == '%') {
            next();
            return new Token(LexType.MOD, "%", curLine);
        } else if (curChar == ';') {
            next();
            return new Token(LexType.SEMICN, ";", curLine);
        } else if (curChar == ',') {
            next();
            return new Token(LexType.COMMA, ",", curLine);
        } else if (curChar == '(') {
            next();
            return new Token(LexType.LPARENT, "(", curLine);
        } else if (curChar == ')') {
            next();
            return new Token(LexType.RPARENT, ")", curLine);
        } else if (curChar == '[') {
            next();
            return new Token(LexType.LBRACK, "[", curLine);
        } else if (curChar == ']') {
            next();
            return new Token(LexType.RBRACK, "]", curLine);
        } else if (curChar == '{') {
            next();
            return new Token(LexType.LBRACE, "{", curLine);
        } else if (curChar == '}') {
            next();
            return new Token(LexType.RBRACE, "}", curLine);
        } else if (curChar == '\"') {
            StringBuilder sb = new StringBuilder();
            sb.append(curChar);
            next();
            while (curChar != '\"') {
                sb.append(curChar);
                next();
            }
            sb.append(curChar);
            next();
            return new Token(LexType.STRCON, sb.toString(), curLine);
        } else if (curChar == '\'') {
            StringBuilder sb = new StringBuilder();
            sb.append(curChar); // '
            next();
            if (curChar == '\\') {
                sb.append(curChar);
                next();
            }
            sb.append(curChar); // 字符
            next();
            sb.append(curChar); // '
            next();
            return new Token(LexType.CHRCON, sb.toString(), curLine);
        } else if (Character.isDigit(curChar)) {
            StringBuilder sb = new StringBuilder();
            while (Character.isDigit(curChar)) {
                sb.append(curChar);
                next();
            }
            return new Token(LexType.INTCON, sb.toString(), curLine);
        } else if (Character.isLetter(curChar) || curChar == '_') {
            StringBuilder sb = new StringBuilder();
            while (Character.isLetter(curChar) || Character.isDigit(curChar) || curChar == '_') {
                sb.append(curChar);
                next();
            }
            String word = sb.toString();
            if (reservedWords.containsKey(word)) {
                return new Token(reservedWords.get(word), word, curLine);
            } else {
                return new Token(LexType.IDENFR, word, curLine);
            }
        } else if (curChar == '!') {
            next();
            if (curChar == '=') {
                next();
                return new Token(LexType.NEQ, "!=", curLine);
            } else {
                return new Token(LexType.NOT, "!", curLine);
            }
        } else if (curChar == '<') {
            next();
            if (curChar == '=') {
                next();
                return new Token(LexType.LEQ, "<=", curLine);
            } else {
                return new Token(LexType.LSS, "<", curLine);
            }
        } else if (curChar == '>') {
            next();
            if (curChar == '=') {
                next();
                return new Token(LexType.GEQ, ">=", curLine);
            } else {
                return new Token(LexType.GRE, ">", curLine);
            }
        } else if (curChar == '=') {
            next();
            if (curChar == '=') {
                next();
                return new Token(LexType.EQL, "==", curLine);
            } else {
                return new Token(LexType.ASSIGN, "=", curLine);
            }
        } else if (curChar == '&') {
            next();
            if (curChar == '&') {
                next();
                return new Token(LexType.AND, "&&", curLine);
            } else {
                ErrorList.getInstance().addError("a", curLine);
                return new Token(LexType.AND, "&", curLine);
            }
        } else if (curChar == '|') {
            next();
            if (curChar == '|') {
                next();
                return new Token(LexType.OR, "||", curLine);
            } else {
                ErrorList.getInstance().addError("a", curLine);
                return new Token(LexType.OR, "|", curLine);
            }
        } else {
            next();
            ErrorList.getInstance().addError("Unknown token " + curChar, curLine);
            return new Token(LexType.ERROR, "Unknown token " + curChar, curLine);
        }
    }
}
