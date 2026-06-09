package frontend.lex;

import java.io.BufferedInputStream;
import java.io.BufferedWriter;
import java.io.IOException;

public class Lexer {
    public static final TokenList tokenList = new TokenList();
    private static int lineno = 1;

    public static void lex(BufferedInputStream src, BufferedWriter errOut) throws IOException {
        int c = src.read();
        //read读到结尾时返回-1
        while (c != -1) {
            c = skipWhiteSpace(src, c);
            if (c == -1) {
                break;
            } else if (c == '/') {
                c = dealComment(src);
            } else if (isLetter(c)) {
                c = dealIdentifier(src, c);
            } else if (Character.isDigit(c)) {
                c = dealNumber(src, c);
            } else if (c == '\'') {
                c = dealChar(src, c);
            } else if (c == '\"') {
                c = dealString(src, c);
            } else {
                c = dealOthers(src, c, errOut);
            }
        }
    }

    private static int skipWhiteSpace(BufferedInputStream src, int c) throws IOException {
        while (Character.isWhitespace(c) || c == '\n') {
            if (c == '\n') {
                lineno++;
            }
            c = src.read();
        }
        return c;
    }

    private static boolean isLetter(int c) {
        return Character.isLetter(c) || c == '_';
    }

    private static int dealComment(BufferedInputStream src) throws IOException {
        int c = src.read();
        if (c == '/') {
            c = src.read();
            while (c != -1) {
                if (c == '\n') {
                    lineno++;
                    c = src.read();
                    break;
                }
                c = src.read();
            }
        } else if (c == '*') {
            c = src.read();
            while (c != -1) {
                if (c == '*') {
                    c = src.read();
                    if (c == '/') {
                        c = src.read();
                        break;
                    } else {
                        continue;
                    }
                }
                c = src.read();
            }
        } else {
            Token token = new Token(TokenType.DIV, "/");
            tokenList.addToken(token);
        }
        return c;
    }

    private static int dealIdentifier(BufferedInputStream src, int c) throws IOException {
        StringBuilder sb = new StringBuilder();
        sb.append((char) c);
        c = src.read();
        if (c == -1) {
            dealKeyword(sb.toString());
            return c;
        }
        while (isLetter(c) || Character.isDigit(c)) {
            sb.append((char) c);
            c = src.read();
            if (c == -1) {
                break;
            }
        }
        dealKeyword(sb.toString());
        return c;
    }

    private static void dealKeyword(String str) {
        switch (str) {
            case "main":
                tokenList.addToken(new Token(TokenType.MAINTK, str));
                break;
            case "const":
                tokenList.addToken(new Token(TokenType.CONSTTK, str));
                break;
            case "void":
                tokenList.addToken(new Token(TokenType.VOIDTK, str));
                break;
            case "int":
                tokenList.addToken(new Token(TokenType.INTTK, str));
                break;
            case "char":
                tokenList.addToken(new Token(TokenType.CHARTK, str));
                break;
            case "if":
                tokenList.addToken(new Token(TokenType.IFTK, str));
                break;
            case "else":
                tokenList.addToken(new Token(TokenType.ELSETK, str));
                break;
            case "break":
                tokenList.addToken(new Token(TokenType.BREAKTK, str));
                break;
            case "continue":
                tokenList.addToken(new Token(TokenType.CONTINUETK, str));
                break;
            case "for":
                tokenList.addToken(new Token(TokenType.FORTK, str));
                break;
            case "return":
                tokenList.addToken(new Token(TokenType.RETURNTK, str));
                break;
            case "getint":
                tokenList.addToken(new Token(TokenType.GETINTTK, str));
                break;
            case "getchar":
                tokenList.addToken(new Token(TokenType.GETCHARTK, str));
                break;
            case "printf":
                tokenList.addToken(new Token(TokenType.PRINTFTK, str));
                break;
            default:
                tokenList.addToken(new Token(TokenType.IDENFR, str));
        }
    }

    private static int dealNumber(BufferedInputStream src, int c) throws IOException {
        StringBuilder sb = new StringBuilder();
        sb.append((char) c);
        c = src.read();
        while (Character.isDigit(c)) {
            sb.append((char) c);
            c = src.read();
            if (c == -1) {
                break;
            }
        }
        tokenList.addToken(new Token(TokenType.INTCON, sb.toString()));
        return c;
    }

    private static int dealChar(BufferedInputStream src, int c) throws IOException {
        StringBuilder sb = new StringBuilder();
        sb.append((char) c);
        c = src.read();
        if (c == -1) {
            return c;
        }
        if (c == '\'') {
            Token token = new Token(TokenType.CHRCON, "");
            tokenList.addToken(token);
            return src.read();
        }
        if (c == '\\') {
            sb.append((char) c);
            c = src.read();
            sb.append((char) c);
            c = src.read();
            sb.append((char) c);
            tokenList.addToken(new Token(TokenType.CHRCON, sb.toString()));
        } else {
            sb.append((char) c);
            c = src.read();
            sb.append((char) c);
            tokenList.addToken(new Token(TokenType.CHRCON, sb.toString()));
        }
        return src.read();
    }

    private static int dealString(BufferedInputStream src, int c) throws IOException {
        StringBuilder sb = new StringBuilder();
        sb.append((char) c);
        c = src.read();
        if (c == -1) {
            return c;
        }
        if (c == '\"') {
            Token token = new Token(TokenType.STRCON, "");
            tokenList.addToken(token);
            return src.read();
        }
        while (c != '\"') {
            if(c == '\\'){
                sb.append((char) c);
                c = src.read();
            }
            sb.append((char) c);
            c = src.read();
            if (c == -1) {
                break;
            }
        }
        if (c == -1) {
            return c;
        }
        sb.append((char) c);
        Token token = new Token(TokenType.STRCON, sb.toString());
        tokenList.addToken(token);
        return src.read();
    }

    private static int dealOthers(BufferedInputStream src, int c, BufferedWriter errOut) throws IOException {
        switch (c) {
            case '+':
                tokenList.addToken(new Token(TokenType.PLUS, "+"));
                c = src.read();
                break;
            case '-':
                tokenList.addToken(new Token(TokenType.MINU, "-"));
                c = src.read();
                break;
            case '*':
                tokenList.addToken(new Token(TokenType.MULT, "*"));
                c = src.read();
                break;
            case '/':
                tokenList.addToken(new Token(TokenType.DIV, "/"));
                c = src.read();
                break;
            case '%':
                tokenList.addToken(new Token(TokenType.MOD, "%"));
                c = src.read();
                break;
            case '=':
                c = src.read();
                if (c == '=') {
                    tokenList.addToken(new Token(TokenType.EQL, "=="));
                    c = src.read();
                } else {
                    tokenList.addToken(new Token(TokenType.ASSIGN, "="));
                }
                break;
            case '!':
                c = src.read();
                if (c == '=') {
                    tokenList.addToken(new Token(TokenType.NEQ, "!="));
                    c = src.read();
                } else {
                    tokenList.addToken(new Token(TokenType.NOT, "!"));
                }
                break;
            case '<':
                c = src.read();
                if (c == '=') {
                    tokenList.addToken(new Token(TokenType.LEQ, "<="));
                    c = src.read();
                } else {
                    tokenList.addToken(new Token(TokenType.LSS, "<"));
                }
                break;
            case '>':
                c = src.read();
                if (c == '=') {
                    tokenList.addToken(new Token(TokenType.GEQ, ">="));
                    c = src.read();
                } else {
                    tokenList.addToken(new Token(TokenType.GRE, ">"));
                }
                break;
            case '&':
                c = src.read();
                if (c == '&') {
                    tokenList.addToken(new Token(TokenType.AND, "&&"));
                    c = src.read();
                } else {
                    errOut.write(lineno + " " + "a");
                    errOut.newLine();
                }
                break;
            case '|':
                c = src.read();
                if (c == '|') {
                    tokenList.addToken(new Token(TokenType.OR, "||"));
                    c = src.read();
                } else {
                    errOut.write(lineno + " " + "a");
                    errOut.newLine();
                }
                break;
            case ';':
                tokenList.addToken(new Token(TokenType.SEMICN, ";"));
                c = src.read();
                break;
            case ',':
                tokenList.addToken(new Token(TokenType.COMMA, ","));
                c = src.read();
                break;
            case '(':
                tokenList.addToken(new Token(TokenType.LPARENT, "("));
                c = src.read();
                break;
            case ')':
                tokenList.addToken(new Token(TokenType.RPARENT, ")"));
                c = src.read();
                break;
            case '[':
                tokenList.addToken(new Token(TokenType.LBRACK, "["));
                c = src.read();
                break;
            case ']':
                tokenList.addToken(new Token(TokenType.RBRACK, "]"));
                c = src.read();
                break;
            case '{':
                tokenList.addToken(new Token(TokenType.LBRACE, "{"));
                c = src.read();
                break;
            case '}':
                tokenList.addToken(new Token(TokenType.RBRACE, "}"));
                c = src.read();
                break;
            default:
                throw new RuntimeException("不应该出现的字符");
        }
        return c;
    }
}
