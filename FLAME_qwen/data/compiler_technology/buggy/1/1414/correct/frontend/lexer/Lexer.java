package frontend.lexer;

import error.ErrorType;
import error.Mistake;
import utils.OutputTool;

import java.io.*;
import java.util.ArrayList;
import java.util.Map;

import static java.util.Map.entry;

public class Lexer {
    public PushbackReader file;
    private int line = 1;
    private final ArrayList<Token> tokens = new ArrayList<>();

    private final static Map<String, TokenType> keywords = Map.ofEntries(
            Map.entry("main", TokenType.MAINTK), Map.entry("const", TokenType.CONSTTK),
            Map.entry("int", TokenType.INTTK), Map.entry("char", TokenType.CHARTK),
            Map.entry("break", TokenType.BREAKTK), Map.entry("if", TokenType.IFTK),
            Map.entry("else", TokenType.ELSETK), Map.entry("continue", TokenType.CONTINUETK),
            Map.entry("for", TokenType.FORTK), Map.entry("getint", TokenType.GETINTTK),
            Map.entry("getchar", TokenType.GETCHARTK), Map.entry("printf", TokenType.PRINTFTK),
            Map.entry("return", TokenType.RETURNTK), Map.entry("void", TokenType.VOIDTK)
    );

    private final static Map<Character, TokenType> symbols = Map.ofEntries(
            entry('+', TokenType.PLUS), entry('-', TokenType.MINU), entry('*', TokenType.MULT),
            entry('/', TokenType.DIV), entry('%', TokenType.MOD), entry('{', TokenType.LBRACE),
            entry('}', TokenType.RBRACE), entry('[', TokenType.LBRACK),
            entry(']', TokenType.RBRACK), entry('(', TokenType.LPARENT),
            entry(')', TokenType.RPARENT), entry(';', TokenType.SEMICN),
            entry(',', TokenType.COMMA), entry('!', TokenType.NOT)
    );

    public Lexer(String input) throws FileNotFoundException {
        file = new PushbackReader(new FileReader(input));
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public void scan() throws IOException {
        int c;
        while((c = file.read()) != -1) {
            if (c == '\n') {
                this.line++;
                continue;
            } else if (c == '\r' || c == '\t' || c == ' ') {
                continue;
            }
            file.unread(c);
            if (Character.isDigit(c)) {
                scanNumber();
            } else if (c == '\'') {
                scanChar();
            } else if (c == '\"') {
                scanString();
            } else if (Character.isLetter(c) || c == '_') {
                scanIdent();
            } else {
                scanSymbol();
            }
        }
    }

    public void scanNumber() throws IOException {
        int c = file.read();
        StringBuilder sb = new StringBuilder();
        while (Character.isDigit(c)) {
            sb.append((char) c);
            c = file.read();
        }
        file.unread(c);
        this.tokens.add(new Token(TokenType.INTCON, sb.toString(), this.line));
    }

    public void scanChar() throws IOException {
        int c = file.read();
        c = file.read();
        if (c == '\\') {
            c = file.read();
            tokens.add(new Token(TokenType.CHRCON, (char) c, this.line, true));
        } else {
            tokens.add(new Token(TokenType.CHRCON, (char) c, this.line));
        }
        c = file.read();
    }

    public void scanString() throws IOException {
        int c = file.read();
        StringBuilder sb = new StringBuilder();
        sb.append((char) c);
        c = file.read();
        while (c != '\"') {
            sb.append((char) c);
            c = file.read();
        }
        sb.append((char) c);
        tokens.add(new Token(TokenType.STRCON, sb.toString(), this.line));
    }

    public void scanIdent() throws IOException {
        int c = file.read();
        StringBuilder sb = new StringBuilder();
        while (Character.isLetter(c) || c == '_' || Character.isDigit(c)) {
            sb.append((char) c);
            c = file.read();
        }
        file.unread(c);
        tokens.add(new Token(keywords.getOrDefault(sb.toString(), TokenType.IDENFR), sb.toString(), this.line));
    }

    public void scanSymbol() throws IOException {
        int c = file.read();
        switch (c) {
            case '&':
                c = file.read();
                if (c == '&') {
                    tokens.add(new Token(TokenType.AND, "&&", this.line));
                } else {
                    file.unread(c);
                    tokens.add(new Token(TokenType.AND, "&&", this.line));
                    OutputTool.mistakeList.add(new Mistake(ErrorType.a, this.line));
                }
                break;
            case '|':
                c = file.read();
                if (c == '|') {
                    tokens.add(new Token(TokenType.OR, "||", this.line));
                } else {
                    file.unread(c);
                    tokens.add(new Token(TokenType.OR, "||", this.line));
                    OutputTool.mistakeList.add(new Mistake(ErrorType.a, this.line));
                }
                break;
            case '>':
                c = file.read();
                if (c == '=') {
                    tokens.add(new Token(TokenType.GEQ, ">=", this.line));
                } else {
                    file.unread(c);
                    tokens.add(new Token(TokenType.GRE, ">", this.line));
                }
                break;
            case '<':
                c = file.read();
                if (c == '=') {
                    tokens.add(new Token(TokenType.LEQ, "<=", this.line));
                } else {
                    file.unread(c);
                    tokens.add(new Token(TokenType.LSS, "<", this.line));
                }
                break;
            case '=':
                c = file.read();
                if (c == '=') {
                    tokens.add(new Token(TokenType.EQL, "==", this.line));
                } else {
                    file.unread(c);
                    tokens.add(new Token(TokenType.ASSIGN, "=", this.line));
                }
                break;
            case '!':
                c = file.read();
                if (c == '=') {
                    tokens.add(new Token(TokenType.NEQ, "!=", this.line));
                } else {
                    file.unread(c);
                    tokens.add(new Token(TokenType.NOT, "!", this.line));
                }
                break;
            case '/':
                c = file.read();
                if (c == '/') {
                    while ((c = file.read()) != -1) {
                        if (c == '\n') {
                            this.line++;
                            break;
                        }
                    }
                } else if (c == '*') {
                    c = file.read();
                    while (true) {
                        if (c == '\n') {
                            this.line++;
                        }
                        if (c == '*') {
                            c = file.read();
                            if (c == '/') {
                                break;
                            }
                            file.unread(c);
                        }
                        c = file.read();
                    }
                } else {
                    file.unread(c);
                    tokens.add(new Token(TokenType.DIV, "/", this.line));
                }
                break;
            default:
                tokens.add(new Token(symbols.get((char) c), (char) c, this.line));
        }
    }
}
