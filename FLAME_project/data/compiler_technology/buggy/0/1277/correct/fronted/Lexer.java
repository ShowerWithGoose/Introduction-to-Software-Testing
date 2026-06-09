package fronted;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Lexer {
    private Processor processor;
    private ArrayList<Token> tokens = new ArrayList<>();
    private boolean error = false;
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

    public boolean isError() {
        return error;
    }

    public int getCurLine() {
        return curLine;
    }

    public Token nextToken() {
        if (curIdx >= tokens.size()) {
            return null;
        } else {
            Token token = tokens.get(curIdx);
            curIdx++;
            return token;
        }
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
            } else if (c == '/') {
                tokenizeDash();
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
                System.out.println(sb.toString());
                if (c == '\'') {
                    tokens.add(new Token(TokenType.CHRCON, sb.toString()));
                } else {
                    tokens.add(new Token(TokenType.STRCON, sb.toString()));
                }
            } else { // special !, &&, ||, +, -, *, %, <, <=, >, >=, ==, =, !=, =, ;, ,, ...
                int r = tokenizeSeparator(c);
                if (r < 0) {
                    break;
                }
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
        tokens.add(new Token(TokenType.INTCON, sb.toString()));
    }

    private void tokenizeDash() {
        char c;
        if (processor.hasNext()) {
            processor.forward();
            c = processor.getChar();
        } else {
            processor.forward();
            c = ' ';
        }

        if (c == '/') { // single line
            int line = curLine;
            while(processor.hasNext()) {
                processor.forward();
                if (processor.getChar() == '\n') {
                    break;
                }
            }
            if (processor.hasNext()) {
                processor.backward();
            }
        } else if (c == '*') { // multiline
            // go until meet '*/'
            int flag = 0;
            while (processor.hasNext()) {
                processor.forward();
                char tar = processor.getChar();
                if (tar == '*') {
                    flag = 1;
                } else if (flag == 1 && tar == '/') {
                    processor.forward();
                    break;
                } else {
                    flag = 0;
                }
            }
            if (processor.hasNext()) {
                processor.backward();
            }
        } else {
            tokens.add(new Token(TokenType.DIV, "/"));
            processor.backward();
            // point at c after '/'
        }
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
        tokens.add(new Token(classify(sb.toString()), sb.toString()));
    }

    private int tokenizeSeparator(char c) {
        if (c == '+') {
            tokens.add(new Token(TokenType.PLUS, "+"));
            return 0;
        } else if (c == '-') {
            tokens.add(new Token(TokenType.MINU, "-"));
            return 0;
        } else if (c == '*') {
            tokens.add(new Token(TokenType.MULT, "*"));
            return 0;
        } else if (c == '%') {
            tokens.add(new Token(TokenType.MOD, "%"));
            return 0;
        } else if (c == ';') {
            tokens.add(new Token(TokenType.SEMICN, ";"));
            return 0;
        } else if (c == ',') {
            tokens.add(new Token(TokenType.COMMA, ","));
            return 0;
        } else if (c == '(') {
            tokens.add(new Token(TokenType.LPARENT, "("));
            return 0;
        } else if (c == ')') {
            tokens.add(new Token(TokenType.RPARENT, ")"));
            return 0;
        } else if (c == '[') {
            tokens.add(new Token(TokenType.LBRACK, "["));
            return 0;
        } else if (c == ']') {
            tokens.add(new Token(TokenType.RBRACK, "]"));
            return 0;
        } else if (c == '{') {
            tokens.add(new Token(TokenType.LBRACE, "{"));
            return 0;
        } else if (c == '}') {
            tokens.add(new Token(TokenType.RBRACE, "}"));
            return 0;
        } else if (c == '\n') {
            curLine++;
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
                tokens.add(new Token(TokenType.NEQ, "!="));
            } else {
                tokens.add(new Token(TokenType.NOT, "!"));
                processor.backward();
            }
        }
        if (c == '&') {
            if (next == '&') {
                tokens.add(new Token(TokenType.AND, "&&"));
            } else {
                error = true;
                return -1;
            }
        }
        if (c == '|') {
            if (next == '|') {
                tokens.add(new Token(TokenType.OR, "||"));
            } else {
                error = true;
                return -1;
            }
        }
        if (c == '<') {
            if (next == '=') {
                tokens.add(new Token(TokenType.LEQ, "<="));
            } else {
                tokens.add(new Token(TokenType.LSS, "<"));
                processor.backward();
            }
        }
        if (c == '>') {
            if (next == '=') {
                tokens.add(new Token(TokenType.GEQ, ">="));
            } else {
                tokens.add(new Token(TokenType.GRE, ">"));
                processor.backward();
            }
        }
        if (c == '=') {
            if (next == '=') {
                tokens.add(new Token(TokenType.EQL, "=="));
            } else {
                tokens.add(new Token(TokenType.ASSIGN, "="));
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
