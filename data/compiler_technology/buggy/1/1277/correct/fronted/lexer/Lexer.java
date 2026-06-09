package fronted.lexer;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Lexer {
    private Processor processor;
    private ArrayList<Token> tokens = new ArrayList<>();
    private Token error = null;
    private int curLine = 1;
    private int curIdx = 0;

    public Lexer(String filename) {
        try {
            Scanner scanner = new Scanner(new FileReader(filename));
            processor = new Processor(scanner);
            tokenize();
        } catch (FileNotFoundException e) {
            System.out.println("ERROR: FILE NOT FOUND");
        }
    }

    public Token getError() {
        return error;
    }

    public void move(int n) {
        curIdx += n;
    }

    public Token get() {
        return tokens.get(curIdx);
    }

    public Token getAndNext() {
        Token res = tokens.get(curIdx);
        curIdx++;
        return res;
    }

    public boolean hasNext() {
        return curIdx < tokens.size() - 1;
    }

    private void tokenize() {
        while(processor.hasNext()) {
            processor.forward();
            char c;
            if (skip() == 1) {
                break;
            } else {
                c = processor.getChar();
            }
            if (Character.isDigit(c)) {
                tokenizeDigit(c);
            } else if (Character.isAlphabetic(c) || c == '_') { // non-blank
                tokenizeAlphabet(c);
            } else if (c == '\'' || c == '\"') {
                StringBuilder sb = new StringBuilder();
                int f = 0;
                sb.append(c);
                while(processor.hasNext()) {
                    processor.forward();
                    c = processor.getChar();
                    if (f == 0 && (c == '\'' || c == '\"')) {
                        break;
                    }
                    if (f == 0 && c == '\\') {
                        f = 1;
                    } else {
                        f = 0;
                    }
                    sb.append(c);
                }
                sb.append(c);
                if (c == '\'') {
                    tokens.add(new Token(TokenType.CHRCON, sb.toString(), curLine));
                } else {
                    tokens.add(new Token(TokenType.STRCON, sb.toString(), curLine));
                }
            } else { // special !, &&, ||, +, -, *, %, <, <=, >, >=, ==, =, !=, =, ;, ,, ...
                tokenizeSeparator(c);
            }
        }
    }

    private void tokenizeDigit(char c) {
        StringBuilder sb = new StringBuilder();
        sb.append(c);
        while(processor.hasNext() && Character.isDigit(c)) {
            processor.forward();
            c = processor.getChar();
            if (Character.isDigit(c)) {
                sb.append(c);
            }
        }
        if (processor.hasNext()) {
            processor.backward();
        }
        tokens.add(new Token(TokenType.INTCON, sb.toString(), curLine));
    }


    private void tokenizeAlphabet(char c) {
        StringBuilder sb = new StringBuilder();
        sb.append(c);
        while(processor.hasNext() && (Character.isAlphabetic(c) || c == '_' || Character.isDigit(c))) {
            processor.forward();
            c = processor.getChar();
            if (Character.isAlphabetic(c) || c == '_' || Character.isDigit(c)) {
                sb.append(c);
            }
        }
        if (processor.hasNext()) {
            processor.backward();
        }
         // out when not alphabetic
        tokens.add(new Token(classify(sb.toString()), sb.toString(), curLine));
    }

    private int tokenizeSeparator(char c) {
        if (c == '+') {
            tokens.add(new Token(TokenType.PLUS, "+", curLine));
            return 0;
        } else if (c == '-') {
            tokens.add(new Token(TokenType.MINU, "-", curLine));
            return 0;
        } else if (c == '*') {
            tokens.add(new Token(TokenType.MULT, "*", curLine));
            return 0;
        } else if (c == '%') {
            tokens.add(new Token(TokenType.MOD, "%", curLine));
            return 0;
        } else if (c == ';') {
            tokens.add(new Token(TokenType.SEMICN, ";", curLine));
            return 0;
        } else if (c == ',') {
            tokens.add(new Token(TokenType.COMMA, ",", curLine));
            return 0;
        } else if (c == '(') {
            tokens.add(new Token(TokenType.LPARENT, "(", curLine));
            return 0;
        } else if (c == ')') {
            tokens.add(new Token(TokenType.RPARENT, ")", curLine));
            return 0;
        } else if (c == '[') {
            tokens.add(new Token(TokenType.LBRACK, "[", curLine));
            return 0;
        } else if (c == ']') {
            tokens.add(new Token(TokenType.RBRACK, "]", curLine));
            return 0;
        } else if (c == '{') {
            tokens.add(new Token(TokenType.LBRACE, "{", curLine));
            return 0;
        } else if (c == '}') {
            tokens.add(new Token(TokenType.RBRACE, "}", curLine));
            return 0;
        } else if (c == '\n') {
            curLine++;
            return 0;
        } else if (c == '/') {
            tokens.add(new Token(TokenType.DIV, "/", curLine));
            return 0;
        }

        // to be handle: !(!=), &(&&), |(||), <(<=), >(>=), =(==)
        char next;
        if (processor.hasNext()) {
            processor.forward();
            next = processor.getChar();
        } else {
            processor.forward();
            next = '\0';
        }

        if (c == '!') {
            if (next == '=') {
                tokens.add(new Token(TokenType.NEQ, "!=", curLine));
            } else {
                tokens.add(new Token(TokenType.NOT, "!", curLine));
                processor.backward();
            }
        }
        if (c == '&') {
            if (next == '&') {
                tokens.add(new Token(TokenType.AND, "&&", curLine));
            } else {
                tokens.add(new Token(TokenType.AND, "&", curLine));
                error = new ErrorToken(TokenType.AND, "&", curLine);
                processor.backward();
            }
        }
        if (c == '|') {
            if (next == '|') {
                tokens.add(new Token(TokenType.OR, "||", curLine));
            } else {
                tokens.add(new Token(TokenType.OR, "|", curLine));
                error = new ErrorToken(TokenType.OR, "|", curLine);
                processor.backward();
            }
        }
        if (c == '<') {
            if (next == '=') {
                tokens.add(new Token(TokenType.LEQ, "<=", curLine));
            } else {
                tokens.add(new Token(TokenType.LSS, "<", curLine));
                processor.backward();
            }
        }
        if (c == '>') {
            if (next == '=') {
                tokens.add(new Token(TokenType.GEQ, ">=", curLine));
            } else {
                tokens.add(new Token(TokenType.GRE, ">", curLine));
                processor.backward();
            }
        }
        if (c == '=') {
            if (next == '=') {
                tokens.add(new Token(TokenType.EQL, "==", curLine));
            } else {
                tokens.add(new Token(TokenType.ASSIGN, "=", curLine));
                processor.backward();
            }
        }
        return 0;
    }

    /**
     * this function should skip blanks
     * post:
     *  point at non-blank or end
     */
    private int skip() {
        char c = processor.getChar();
        if (c == '\n') {
            curLine++;
        }
        while(Character.isWhitespace(c) && processor.hasNext()) {
            processor.forward();
            c = processor.getChar();
            if (c == '\n') {
                curLine++;
            }
        }
        if (!processor.hasNext() && Character.isWhitespace(processor.getChar())) {
            return 1;
        } else {
            return 0;
        }
    }

    /**
     * only cares part of types, specially char-related
     */
    private TokenType classify(String str) {
        if (str.charAt(0) == '+') { // ? careful here
            return TokenType.INTCON;
        }
        if (str.equals("main")) {
            return TokenType.MAINTK;
        }
        if (str.equals("const")) {
            return TokenType.CONSTTK;
        }
        if (str.equals("int")) {
            return TokenType.INTTK;
        }
        if (str.equals("char")) {
            return TokenType.CHARTK;
        }
        if (str.equals("break")) {
            return TokenType.BREAKTK;
        }
        if (str.equals("continue")) {
            return TokenType.CONTINUETK;
        }
        if (str.equals("if")) {
            return TokenType.IFTK;
        }
        if (str.equals("else")) {
            return TokenType.ELSETK;
        }
        if (str.equals("for")) {
            return TokenType.FORTK;
        }
        if (str.equals("getint")) {
            return TokenType.GETINTTK;
        }
        if (str.equals("getchar")) {
            return TokenType.GETCHARTK;
        }
        if (str.equals("printf")) {
            return TokenType.PRINTFTK;
        }
        if (str.equals("return")) {
            return TokenType.RETURNTK;
        }
        if (str.equals("void")) {
            return TokenType.VOIDTK;
        }
        return TokenType.IDENFR;
    }
}
