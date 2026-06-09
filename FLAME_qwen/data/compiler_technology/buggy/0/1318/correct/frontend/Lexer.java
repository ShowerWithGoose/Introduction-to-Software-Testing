package frontend;

import utils.Logger;

import java.io.*;
import java.util.Objects;

public class Lexer {
    private final BufferedInputStream bis;
    private char curChar;
    private boolean end = false;
    private int line = 1;

    public Lexer(BufferedInputStream bis) {
        this.bis = bis;
    }

    private boolean nextChar() {
        int ch = -1;
        try {
            ch = bis.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (ch == -1) {
            end = true;
            return false;
        }
        curChar = (char) ch;
        if (curChar == '\n') {
            line++;
        }
        return true;
    }

    private boolean isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    private boolean isLetter(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_';
    }

    private boolean isAscii(char c) {
        return c >= 32 && c <= 126;
    }

//    private char escapeChar(char c) {
//        return switch (c) {
//            case 'a' -> 7;
//            case 'b' -> 8;
//            case 't' -> 9;
//            case 'n' -> 10;
//            case 'v' -> 11;
//            case 'f' -> 12;
//            case '\"' -> 34;
//            case '\'' -> 39;
//            case '\\' -> 92;
//            case '0' -> 0;
//            default -> throw new RuntimeException("illegal escape char!");
//        };
//    }

    private Token nextIdent() {
        StringBuilder sb = new StringBuilder();
        while (!end && (isLetter(curChar) || isDigit(curChar))) {
            sb.append(curChar);
            nextChar();
        }
        String text = sb.toString();
        TokenType tokenType = TokenType.getBySymbol(text);
        return new Token(Objects.requireNonNullElse(tokenType, TokenType.IDENFR), text);
    }

    private Token nextIntcon() {
        StringBuilder sb = new StringBuilder();
        while (!end && isDigit(curChar)) {
            sb.append(curChar);
            nextChar();
        }
        return new Token(TokenType.INTCON, sb.toString());
    }

    private Token nextStrcon() {
        StringBuilder sb = new StringBuilder();
        do {
            if (curChar == '\\') {
                sb.append(curChar);
                nextChar();
                sb.append(curChar);
//              sb.append(escapeChar(curChar));
            } else {
                sb.append(curChar);
            }
        } while (nextChar() && curChar != '\"' && isAscii(curChar));
        sb.append(curChar);
        nextChar();
        return new Token(TokenType.STRCON, sb.toString());
    }

    private Token nextChrcon() {
        StringBuilder sb = new StringBuilder();
        sb.append(curChar);
        nextChar();
        if (isAscii(curChar)) {
            if (curChar == '\\') {
                sb.append(curChar);
                nextChar();
                sb.append(curChar);
            } else {
                sb.append(curChar);
            }
        } else {
            throw new RuntimeException("illegal char!");
        }
        nextChar();
        sb.append(curChar);
        nextChar();
        return new Token(TokenType.CHRCON, sb.toString());
    }

    private Token nextOp() {
        char op = curChar;
        nextChar();
        switch (op) {
            case '/': {
                if (curChar == '/') {
                    while (nextChar()) {
                        if (curChar == '\n' || curChar == '\r') {
                            break;
                        }
                    }
                    nextChar();
                    return null;
                } else if (curChar == '*') {
                    nextChar();
                    while (!end) {
                        op = curChar;
                        nextChar();
                        if (op == '*' && curChar == '/') {
                            break;
                        }
                    }
                    nextChar();
                    return null;
                } else {
                    return new Token(TokenType.DIV, "/");
                }
            }
            case '!': {
                if (curChar == '=') {
                    nextChar();
                    return new Token(TokenType.NEQ, "!=");
                } else {
                    return new Token(TokenType.NOT, "!");
                }
            }
            case '&': {
                if (curChar == '&') {
                    nextChar();
                } else {
                    Logger.logger.error(line + " " + "a");
                }
                return new Token(TokenType.AND, "&&");
            }
            case '|': {
                if (curChar == '|') {
                    nextChar();
                } else {
                    Logger.logger.error(line + " " + "a");
                }
                return new Token(TokenType.OR, "||");
            }
            case '<': {
                if (curChar == '=') {
                    nextChar();
                    return new Token(TokenType.LEQ, "<=");
                } else {
                    return new Token(TokenType.LSS, "<");
                }
            }
            case '>': {
                if (curChar == '=') {
                    nextChar();
                    return new Token(TokenType.GEQ, ">=");
                } else {
                    return new Token(TokenType.GRE, ">");
                }
            }
            case '=': {
                if (curChar == '=') {
                    nextChar();
                    return new Token(TokenType.EQL, "==");
                } else {
                    return new Token(TokenType.ASSIGN, "=");
                }
            }
            default: {
                TokenType tokenType = TokenType.getBySymbol(String.valueOf(op));
                if (tokenType != null) {
                    return new Token(tokenType, String.valueOf(op));
                }
                throw new RuntimeException(op + " illegal op!");
            }
        }
    }


    public TokenList lexer() {
        TokenList tokens = new TokenList();
        nextChar();
        while (!end) {
            switch (curChar) {
                case ' ':
                case '\t':
                case '\n':
                case '\r':
                    nextChar();
                    break;
                case '\"':
                    tokens.add(nextStrcon());
                    break;
                case '\'':
                    tokens.add(nextChrcon());
                    break;
                default:
                    if (isLetter(curChar)) {
                        tokens.add(nextIdent());
                    } else if (isDigit(curChar)) {
                        tokens.add(nextIntcon());
                    } else {
                        Token token = nextOp();
                        if (token != null) {
                            tokens.add(token);
                        }
                    }
                    break;
            }
        }
        return tokens;
    }
}

