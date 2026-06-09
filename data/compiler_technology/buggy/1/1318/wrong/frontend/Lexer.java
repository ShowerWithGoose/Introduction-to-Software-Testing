package frontend;

import utils.Logger;

import java.io.*;
import java.util.Objects;

public class Lexer {
    private final BufferedInputStream bis;
    private int line = 1;
    private char curChar;
    private boolean end = false;

    public Lexer(BufferedInputStream bis) {
        this.bis = bis;
    }

    private boolean isLetter(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_';
    }

    private boolean isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    private boolean isAscii(char c) {
        return c >= 32 && c <= 126;
    }

    private char escapeChar(char c) {
        return switch (c) {
            case 'a' -> 7;
            case 'b' -> 8;
            case 't' -> 9;
            case 'n' -> 10;
            case 'v' -> 11;
            case 'f' -> 12;
            case '\"' -> 34;
            case '\'' -> 39;
            case '\\' -> 92;
            case '0' -> 0;
            default -> throw new RuntimeException("illegal escape char!");
        };
    }

    private boolean nextChar() {
        try {
            int ch = bis.read();
            if (ch == -1) {
                end = true;
                return false;
            }
            curChar = (char) ch;
            if (curChar == '\n') {
                line++;
            }
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

    private Token nextString(TokenType tokenType, char endChar) {
        StringBuilder sb = new StringBuilder();
        sb.append(curChar);
        while (nextChar() && curChar != endChar && isAscii(curChar)) {
            if (curChar == '\\') {
                sb.append(curChar);
                nextChar();
            }
            sb.append(curChar);
        }
        sb.append(curChar);
        nextChar();
        return new Token(tokenType, sb.toString(), line);
    }

    private Token nextChrcon() {
        return nextString(TokenType.CHRCON, '\'');
    }

    private Token nextStrcon() {
        return nextString(TokenType.STRCON, '\"');
    }

    private Token nextIdent() {
        StringBuilder sb = new StringBuilder();
        while (!end && (isLetter(curChar) || isDigit(curChar))) {
            sb.append(curChar);
            nextChar();
        }
        String text = sb.toString();
        TokenType tokenType = TokenType.getBySymbol(text);
        return new Token(Objects.requireNonNullElse(tokenType, TokenType.IDENFR), text, line);
    }

    private Token nextIntcon() {
        StringBuilder sb = new StringBuilder();
        while (!end && isDigit(curChar)) {
            sb.append(curChar);
            nextChar();
        }
        return new Token(TokenType.INTCON, sb.toString(), line);
    }

private Token nextOperate() {
    char op = curChar;
    nextChar();
    switch (op) {
        case '/':
            if (curChar == '/') {
                while (nextChar() && curChar != '\n' && curChar != '\r');
                nextChar();
                return null;
            } else if (curChar == '*') {
                nextChar();
                while (!end) {
                    if (curChar == '*') {
                        nextChar();
                        if (curChar == '/') {
                            nextChar();
                            return null;
                        }
                    } else {
                        nextChar();
                    }
                }
                return null;
            } else {
                return new Token(TokenType.DIV, "/", line);
            }
        case '!':
            if (curChar == '=') {
                nextChar();
                return new Token(TokenType.NEQ, "!=", line);
            } else {
                return new Token(TokenType.NOT, "!", line);
            }
        case '&':
            if (curChar == '&') {
                nextChar();
                return new Token(TokenType.AND, "&&", line);
            } else {
                Logger.logger.error(line + " " + "a");
                return null;
            }
        case '|':
            if (curChar == '|') {
                nextChar();
                return new Token(TokenType.OR, "||", line);
            } else {
                Logger.logger.error(line + " " + "a");
                return null;
            }
        case '<':
            if (curChar == '=') {
                nextChar();
                return new Token(TokenType.LEQ, "<=", line);
            } else {
                return new Token(TokenType.LSS, "<", line);
            }
        case '>':
            if (curChar == '=') {
                nextChar();
                return new Token(TokenType.GEQ, ">=", line);
            } else {
                return new Token(TokenType.GRE, ">", line);
            }
        case '=':
            if (curChar == '=') {
                nextChar();
                return new Token(TokenType.EQL, "==", line);
            } else {
                return new Token(TokenType.ASSIGN, "=", line);
            }
        default:
            TokenType tokenType = TokenType.getBySymbol(String.valueOf(op));
            if (tokenType != null) {
                return new Token(tokenType, String.valueOf(op), line);
            }
            throw new RuntimeException(op + " illegal op!");
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
                case '\'':
                    tokens.add(nextChrcon());
                    break;
                case '\"':
                    tokens.add(nextStrcon());
                    break;
                default:
                    if (isLetter(curChar)) {
                        tokens.add(nextIdent());
                    } else if (isDigit(curChar)) {
                        tokens.add(nextIntcon());
                    } else {
                        Token token = nextOperate();
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

