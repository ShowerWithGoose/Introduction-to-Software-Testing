package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class Lexer {
    private final BufferedReader in;
    private int lineNumber;
    private String line;
    private int index;
    private char charNow;
    private Token token;
    private final ArrayList<Error> errors;
    private static final HashSet<String> keywords = new HashSet<>(Arrays.asList(
            "main", "const", "int", "char", "void", "break", "continue",
            "if", "else", "for", "getint", "getchar", "printf", "return"));

    public Lexer(BufferedReader in) {
        this.in = in;
        lineNumber = 0;
        line = "";
        errors = new ArrayList<>();
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }

    public Token getNextToken() throws IOException {
        while (true) {
            if (index == line.length()) {
                if (!nextLine()) {
                    return new Token(TokenType.EOF, "EOF");
                }
            }
            while (index < line.length()) {
                token = new Token();
                do {
                    getCharNow();
                } while (Character.isWhitespace(charNow));
                if (Character.isLetter(charNow) || charNow == '_') {
                    do {
                        token.catChar(charNow);
                        getCharNow();
                    } while (Character.isLetterOrDigit(charNow) || charNow == '_');
                    retract();
                    if (keywords.contains(token.getString())) {
                        token.setType(TokenType.fromString(token.getString()));
                    } else {
                        token.setType(TokenType.IDENFR);
                    }
                    return token;
                } else if (Character.isDigit(charNow)) {
                    do {
                        token.catChar(charNow);
                        getCharNow();
                    } while (Character.isDigit(charNow));
                    retract();
                    token.setType(TokenType.INTCON);
                    return token;
                } else if (charNow == '\"') {
                    do {
                        if (charNow == '\\') {
                            token.catChar(charNow);
                            getCharNow();
                        }
                        token.catChar(charNow);
                        getCharNow();
                    } while (charNow != '\"');
                    token.catChar(charNow);
                    token.setType(TokenType.STRCON);
                    return token;
                } else if (charNow == '\'') {
                    do {
                        if (charNow == '\\') {
                            token.catChar(charNow);
                            getCharNow();
                        }
                        token.catChar(charNow);
                        getCharNow();
                    } while (charNow != '\'');
                    token.catChar(charNow);
                    token.setType(TokenType.CHRCON);
                    return token;
                } else if (charNow == '!') {
                    token.catChar(charNow);
                    getCharNow();
                    if (charNow == '=') {
                        token.catChar(charNow);
                        token.setType(TokenType.NEQ);
                    } else {
                        retract();
                        token.setType(TokenType.NOT);
                    }
                    return token;
                } else if (charNow == '&') {
                    token.catChar(charNow);
                    getCharNow();
                    if (charNow == '&') {
                        token.catChar(charNow);
                        token.setType(TokenType.AND);
                        return token;
                    } else {
                        retract();
                        errors.add(new Error(lineNumber, 'a'));
                    }
                } else if (charNow == '|') {
                    token.catChar(charNow);
                    getCharNow();
                    if (charNow == '|') {
                        token.catChar(charNow);
                        token.setType(TokenType.OR);
                        return token;
                    } else {
                        retract();
                        errors.add(new Error(lineNumber, 'a'));
                    }
                } else if (charNow == '+') {
                    token.catChar(charNow);
                    token.setType(TokenType.PLUS);
                    return token;
                } else if (charNow == '-') {
                    token.catChar(charNow);
                    token.setType(TokenType.MINU);
                    return token;
                } else if (charNow == '*') {
                    token.catChar(charNow);
                    token.setType(TokenType.MULT);
                    return token;
                } else if (charNow == '/') {
                    getCharNow();
                    if (charNow == '*') {
                        do {
                            do {
                                getCharNowThroughLines();
                            } while (charNow != '*');
                            getCharNow();
                        } while (charNow != '/');
                    } else if (charNow == '/') {
                        index = line.length();
                    } else {
                        retract();
                        token.catChar('/');
                        token.setType(TokenType.DIV);
                        return token;
                    }
                } else if (charNow == '%') {
                    token.catChar(charNow);
                    token.setType(TokenType.MOD);
                    return token;
                } else if (charNow == '<') {
                    token.catChar(charNow);
                    getCharNow();
                    if (charNow == '=') {
                        token.catChar(charNow);
                        token.setType(TokenType.LEQ);
                    } else {
                        retract();
                        token.setType(TokenType.LSS);
                    }
                    return token;
                } else if (charNow == '>') {
                    token.catChar(charNow);
                    getCharNow();
                    if (charNow == '=') {
                        token.catChar(charNow);
                        token.setType(TokenType.GEQ);
                    } else {
                        retract();
                        token.setType(TokenType.GRE);
                    }
                    return token;
                } else if (charNow == '=') {
                    token.catChar(charNow);
                    getCharNow();
                    if (charNow == '=') {
                        token.catChar(charNow);
                        token.setType(TokenType.EQL);
                    } else {
                        retract();
                        token.setType(TokenType.ASSIGN);
                    }
                    return token;
                } else if (charNow == ';') {
                    token.catChar(charNow);
                    token.setType(TokenType.SEMICN);
                    return token;
                } else if (charNow == ',') {
                    token.catChar(charNow);
                    token.setType(TokenType.COMMA);
                    return token;
                } else if (charNow == '(') {
                    token.catChar(charNow);
                    token.setType(TokenType.LPARENT);
                    return token;
                } else if (charNow == ')') {
                    token.catChar(charNow);
                    token.setType(TokenType.RPARENT);
                    return token;
                } else if (charNow == '[') {
                    token.catChar(charNow);
                    token.setType(TokenType.LBRACK);
                    return token;
                } else if (charNow == ']') {
                    token.catChar(charNow);
                    token.setType(TokenType.RBRACK);
                    return token;
                } else if (charNow == '{') {
                    token.catChar(charNow);
                    token.setType(TokenType.LBRACE);
                    return token;
                } else if (charNow == '}') {
                    token.catChar(charNow);
                    token.setType(TokenType.RBRACE);
                    return token;
                }
            }
        }
    }

    private void getCharNow() {
        if (index > line.length()) {
            System.err.println("Line ended! Line: " + lineNumber + " Index: " + index);
        } else if (index == line.length()) {
            charNow = (char) -1;
            index++;
        } else {
            charNow = line.charAt(index);
            index++;
        }
    }

    private void getCharNowThroughLines() throws IOException {
        if (index == line.length()) {
            if (nextLine()) {
                charNow = line.charAt(index);
                index++;
            } else {
                System.err.println("Text ended!");
            }
        } else {
            charNow = line.charAt(index);
            index++;
        }
    }

    private void retract() {
        if (index == 0) {
            System.err.println("Retract at the first char!");
        }
        index--;
    }

    private boolean nextLine() throws IOException {
        if ((line = in.readLine()) != null) {
            lineNumber++;
            index = 0;
            return true;
        } else {
            return false;
        }
    }
}
