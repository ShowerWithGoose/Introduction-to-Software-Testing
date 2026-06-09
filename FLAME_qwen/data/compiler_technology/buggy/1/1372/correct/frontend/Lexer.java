package frontend;

import frontend.type.LexType;

import java.io.IOException;
import java.io.PushbackInputStream;
import java.util.ArrayList;
import java.util.Map;

import static java.util.Map.entry;

public class Lexer {
    private final PushbackInputStream inputStream;
    private final ArrayList<Token> tokenArrayList = new ArrayList<>();
    private final ErrorList errorArrayList = ErrorList.getErrorList();
    private int lineNumber;
    private char currentChar;

    private static final char EOF = (char) -1;
    private static final Map<String, LexType> reserves = Map.ofEntries(
            entry("main", LexType.MAINTK),
            entry("const", LexType.CONSTTK),
            entry("int", LexType.INTTK),
            entry("char", LexType.CHARTK),
            entry("break", LexType.BREAKTK),
            entry("continue", LexType.CONTINUETK),
            entry("if", LexType.IFTK),
            entry("else", LexType.ELSETK),
            entry("for", LexType.FORTK),
            entry("getint", LexType.GETINTTK),
            entry("getchar", LexType.GETCHARTK),
            entry("printf", LexType.PRINTFTK),
            entry("return", LexType.RETURNTK),
            entry("void", LexType.VOIDTK)
    );

    public Lexer(PushbackInputStream inputStream) throws IOException {
        this.inputStream = inputStream;
        this.lineNumber = 1;
        this.currentChar = (char) inputStream.read();
    }

    public void next() throws IOException {
        currentChar = (char) inputStream.read();
    }

    private static boolean isLetterSt(char c) {
        return Character.isLetter(c)||c=='_';
    }

    private static boolean isLetter(char c) {
        return Character.isLetter(c)||c=='_'||Character.isDigit(c);
    }

    public void skipWhiteSpace() throws IOException {
        while(Character.isWhitespace(currentChar)) {
            if(currentChar == '\n') {lineNumber++;}
            this.next();
        }
    }

    public boolean getToken() throws IOException {
        StringBuilder sb = new StringBuilder();

        skipWhiteSpace();

        if (currentChar == EOF) {return false;}

        if (isLetterSt(currentChar)) {
            sb.append(currentChar);
            next();
            while (isLetter(currentChar)) {
                sb.append(currentChar);
                next();
            }
            String tokenValue = sb.toString();
            tokenArrayList.add(new Token(reserves.getOrDefault(tokenValue, LexType.IDENFR), lineNumber, tokenValue));
        } else if (Character.isDigit(currentChar)) {
            do {
                sb.append(currentChar);
                next();
            } while (Character.isDigit(currentChar));
            tokenArrayList.add(new Token(LexType.INTCON, lineNumber, sb.toString()));
        } else if (currentChar == '\"') {
            char minus1=currentChar, minus2=currentChar;
            sb.append(currentChar);
            next();
            while (currentChar != '\"' || ((minus1 == '\\') && (minus2 != '\\'))) {
                sb.append(currentChar);
                minus2 = minus1;
                minus1=currentChar;
                next();
            }
            sb.append(currentChar);
            next();
            tokenArrayList.add(new Token(LexType.STRCON, lineNumber, sb.toString()));
        } else if (currentChar == '\'') {
            sb.append(currentChar);
            next();
            sb.append(currentChar);
            if (currentChar == '\\') {
                next();
                sb.append(currentChar);
            }
            next();
            sb.append(currentChar);
            next();
            tokenArrayList.add(new Token(LexType.CHRCON, lineNumber, sb.toString()));
        } else if (currentChar == '!') {
            next();
            if (currentChar == '=') {
                next();
                tokenArrayList.add(new Token(LexType.NEQ, lineNumber, "!="));
            } else {
                tokenArrayList.add(new Token(LexType.NOT, lineNumber, "!"));
            }
        } else if (currentChar == '&') {
            next();
            if (currentChar == '&') {
                next();
                tokenArrayList.add(new Token(LexType.AND, lineNumber, "&&"));
            } else {
                errorArrayList.getErrors().add(new Error(lineNumber, "a"));
                tokenArrayList.add(new Token(LexType.AND, lineNumber, "&&"));
            }
        } else if (currentChar == '|') {
            next();
            if (currentChar == '|') {
                next();
                tokenArrayList.add(new Token(LexType.OR, lineNumber, "||"));
            } else {
                errorArrayList.getErrors().add(new Error(lineNumber, "a"));
                tokenArrayList.add(new Token(LexType.OR, lineNumber, "||"));
            }
        } else if (currentChar == '+') {
            next();
            tokenArrayList.add(new Token(LexType.PLUS, lineNumber, "+"));
        } else if (currentChar == '-') {
            next();
            tokenArrayList.add(new Token(LexType.MINU, lineNumber, "-"));
        } else if (currentChar == '*') {
            next();
            tokenArrayList.add(new Token(LexType.MULT, lineNumber, "*"));
        } else if (currentChar == '/') {
            next();
            if (currentChar == '/') {
                next();
                while(currentChar != '\n' && currentChar != EOF) {next();}
                //inputStream.unread(currentChar);
                return getToken();
            } else if (currentChar == '*') {
                next();
                while (true) {
                    while (currentChar != '*') {
                        if (currentChar == '\n') {lineNumber++;}
                        next();
                    }
                    while (currentChar == '*') {next();}
                    if (currentChar == '/') {
                        next();
                        break;
                    }
                }
            } else {
                tokenArrayList.add(new Token(LexType.DIV, lineNumber, "/"));
            }
        } else if (currentChar == '%') {
            next();
            tokenArrayList.add(new Token(LexType.MOD, lineNumber, "%"));
        } else if (currentChar == '<') {
            next();
            if (currentChar == '=') {
                next();
                tokenArrayList.add(new Token(LexType.LEQ, lineNumber, "<="));
            } else {
                tokenArrayList.add(new Token(LexType.LSS, lineNumber, "<"));
            }
        } else if (currentChar == '>') {
            next();
            if (currentChar == '=') {
                next();
                tokenArrayList.add(new Token(LexType.GEQ, lineNumber, ">="));
            } else {
                tokenArrayList.add(new Token(LexType.GRE, lineNumber, ">"));
            }
        } else if (currentChar == '=') {
            next();
            if (currentChar == '=') {
                next();
                tokenArrayList.add(new Token(LexType.EQL, lineNumber, "=="));
            } else {
                tokenArrayList.add(new Token(LexType.ASSIGN, lineNumber, "="));
            }
        } else if (currentChar == ';') {
            next();
            tokenArrayList.add(new Token(LexType.SEMICN, lineNumber, ";"));
        } else if (currentChar == ',') {
            next();
            tokenArrayList.add(new Token(LexType.COMMA, lineNumber, ","));
        } else if (currentChar == '(') {
            next();
            tokenArrayList.add(new Token(LexType.LPARENT, lineNumber, "("));
        } else if (currentChar == ')') {
            next();
            tokenArrayList.add(new Token(LexType.RPARENT, lineNumber, ")"));
        } else if (currentChar == '[') {
            next();
            tokenArrayList.add(new Token(LexType.LBRACK, lineNumber, "["));
        } else if (currentChar == ']') {
            next();
            tokenArrayList.add(new Token(LexType.RBRACK, lineNumber, "]"));
        } else if (currentChar == '{') {
            next();
            tokenArrayList.add(new Token(LexType.LBRACE, lineNumber, "{"));
        } else if (currentChar == '}') {
            next();
            tokenArrayList.add(new Token(LexType.RBRACE, lineNumber, "}"));
        }
        return true;
    }

    public ArrayList<Token> getTokenArrayList() throws IOException {
        while (getToken());
        return this.tokenArrayList;
    }
    /*public ErrorList getErrorArrayList() {
        return this.errorArrayList;
    }*/
}
