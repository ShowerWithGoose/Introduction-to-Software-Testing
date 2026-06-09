package lexical;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.TreeMap;

public class Lexer {
    private Read reader;
    private TokenList tokenList = new TokenList();
    char ch;
    private BufferedWriter lexerWriter;
    private BufferedWriter errorWriter;
    private TreeMap<Integer, String> errors;

    public Lexer(Read reader) {
        this.reader = reader;
    }

    public void run() throws IOException {
        while (true) {
            Token token = getToken();
            if (token == null) {
                break;
            } else {
                tokenList.add(token);
            }
        }
    }

    private Token getToken() throws IOException {
        while (true) {
            read();
            while (Character.isWhitespace(ch)) {
                read();
            }
            if (ch == (char) -1) {
                break;
            }
            if (Character.isLetter(ch) || ch == '_') {
                return parseIdent();
            } else if (Character.isDigit(ch)) {
                return parseInt();
            } else if (ch == '\'') {
                return parseChar();
            } else if (ch == '\"') {
                return parseString();
            } else if (ch == '/') {
                read();
                if (ch == '/') {
                    while (ch != '\n' && ch != (char) -1) {
                        read();
                    }
                } else if (ch == '*') {
                    while (ch != (char) -1) {
                        read();
                        if (ch == '*') {
                            read();
                            if (ch == '/') {
                                read();
                                break;
                            } else {
                                unread();
                            }
                        }
                    }
                } else {
                    unread();
                    return newToken(TokenType.DIV, "/");
                }
            } else if (ch == '!') {
                read();
                if (ch == '=') {
                    return newToken(TokenType.NEQ, "!=");
                } else {
                    unread();
                    return newToken(TokenType.NOT, "!");
                }
            } else if (ch == '&') {
                read();
                if (ch == '&') {
                    return newToken(TokenType.AND, "&&");
                } else {
                    unread();
                    printError("a");
                    return newToken(TokenType.AND, "&");
                }
            } else if (ch == '|') {
                read();
                if (ch == '|') {
                    return newToken(TokenType.OR, "||");
                } else {
                    unread();
                    printError("a");
                    return newToken(TokenType.OR, "|");
                }
            } else if (ch == '+') {
                return newToken(TokenType.PLUS, "+");
            } else if (ch == '-') {
                return newToken(TokenType.MINU, "-");
            } else if (ch == '*') {
                return newToken(TokenType.MULT, "*");
            } else if (ch == '%') {
                return newToken(TokenType.MOD, "%");
            } else if (ch == '<') {
                read();
                if (ch == '=') {
                    return newToken(TokenType.LEQ, "<=");
                } else {
                    unread();
                    return newToken(TokenType.LSS, "<");
                }
            } else if (ch == '>') {
                read();
                if (ch == '=') {
                    return newToken(TokenType.GEQ, ">=");
                } else {
                    unread();
                    return newToken(TokenType.GRE, ">");
                }
            } else if (ch == '=') {
                read();
                if (ch == '=') {
                    return newToken(TokenType.EQL, "==");
                } else {
                    unread();
                    return newToken(TokenType.ASSIGN, "=");
                }
            } else if (ch == ';') {
                return newToken(TokenType.SEMICN, ";");
            } else if (ch == ',') {
                return newToken(TokenType.COMMA, ",");
            } else if (ch == '(') {
                return newToken(TokenType.LPARENT, "(");
            } else if (ch == ')') {
                return newToken(TokenType.RPARENT, ")");
            } else if (ch == '[') {
                return newToken(TokenType.LBRACK, "[");
            } else if (ch == ']') {
                return newToken(TokenType.RBRACK, "]");
            } else if (ch == '{') {
                return newToken(TokenType.LBRACE, "{");
            } else if (ch == '}') {
                return newToken(TokenType.RBRACE, "}");
            }
        }
        return null;
    }

    private Token parseIdent() throws IOException {
        StringBuilder buf = new StringBuilder();
        buf.append(ch);
        read();
        while (ch == '_' || Character.isLetter(ch) || Character.isDigit(ch)) {
            buf.append(ch);
            read();
        }
        unread();
        String ident = buf.toString();
        if (ident.equals("main")) {
            return newToken(TokenType.MAINTK, ident);
        } else if (ident.equals("const")) {
            return newToken(TokenType.CONSTTK, ident);
        } else if (ident.equals("int")) {
            return newToken(TokenType.INTTK, ident);
        } else if (ident.equals("char")) {
            return newToken(TokenType.CHARTK, ident);
        } else if (ident.equals("break")) {
            return newToken(TokenType.BREAKTK, ident);
        } else if (ident.equals("continue")) {
            return newToken(TokenType.CONTINUETK, ident);
        } else if (ident.equals("if")) {
            return newToken(TokenType.IFTK, ident);
        } else if (ident.equals("else")) {
            return newToken(TokenType.ELSETK, ident);
        } else if (ident.equals("for")) {
            return newToken(TokenType.FORTK, ident);
        } else if (ident.equals("getint")) {
            return newToken(TokenType.GETINTTK, ident);
        } else if (ident.equals("getchar")) {
            return newToken(TokenType.GETCHARTK, ident);
        } else if (ident.equals("printf")) {
            return newToken(TokenType.PRINTFTK, ident);
        } else if (ident.equals("return")) {
            return newToken(TokenType.RETURNTK, ident);
        } else if (ident.equals("void")) {
            return newToken(TokenType.VOIDTK, ident);
        } else {
            return newToken(TokenType.IDENFR, ident);
        }
    }

    private Token parseInt() throws IOException {
        if (ch == '0') {
            return newToken(TokenType.INTCON, "0");
        }
        StringBuilder buf = new StringBuilder();
        while (Character.isDigit(ch)) {
            buf.append(ch);
            read();
        }
        unread();
        return newToken(TokenType.INTCON, buf.toString());
    }

    private Token parseChar() throws IOException {
        StringBuilder buf = new StringBuilder();
        buf.append(ch);
        while (true) {
            read();
            if (ch == '\\') {
                buf.append(ch);
                read();
                buf.append(ch);
            } else if (ch == '\'') {
                buf.append(ch);
                break;
            } else {
                buf.append(ch);
            }
        }
        return newToken(TokenType.CHRCON, buf.toString());
    }

    private Token parseString() throws IOException {
        StringBuilder buf = new StringBuilder();
        buf.append(ch);
        while (true) {
            read();
            if (ch == '\\') {
                buf.append(ch);
                read();
                buf.append(ch);
            } else if (ch == '\"') {
                buf.append(ch);
                break;
            } else {
                buf.append(ch);
            }
        }
        return newToken(TokenType.STRCON, buf.toString());
    }

    private void read() throws IOException {
        ch = reader.read();
    }

    private void unread() throws IOException {
        reader.unread();
    }

    public TokenList getTokenlist() {
        return tokenList;
    }

    public void serLexerWriter(BufferedWriter lexerWriter) {
        this.lexerWriter = lexerWriter;
    }

    public void serErrorWriter(BufferedWriter errorWriter) {
        this.errorWriter = errorWriter;
    }

    public void setErrorBuffer(TreeMap<Integer, String> errors) {
        this.errors = errors;
    }

    public void printError(String s) throws IOException {
//        errorWriter.write(s);
//        errorWriter.newLine();
        errors.put(reader.getCurrentLine(), s);
    }

    public Token newToken(TokenType type, String rawString) {
        return new Token(type, rawString, reader.getCurrentLine());
    }
}
