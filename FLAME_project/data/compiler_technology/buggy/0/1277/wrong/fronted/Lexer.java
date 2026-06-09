package fronted;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Lexer {
    private Processor processor;
    private ArrayList<Token> tokens = new ArrayList<>();
    private boolean error = false;
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
        return processor.getCurLine();
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
        while(isValid()) {
            skip();
            char c;
            if (isValid()) {
                c = processor.getChar();
            } else {
                break;
            }
            System.out.println("NOW: " + c);
            if (Character.isDigit(c)) {
                tokenizeDigit(c);
            } else if (c == '/') {
                tokenizeDash();
            } else if (Character.isAlphabetic(c) || c == '_') { // non-blank
                tokenizeAlphabet(c);
            } else if (c == '\'' || c == '\"') {
                StringBuilder sb = new StringBuilder();
                int f = 0;
                do {
                    sb.append(c);
                    move();
                    if (!isValid()) {
                        break;
                    }
                    c = processor.getChar();
                    if (f == 0 && (c == '\'' || c == '\"')) {
                        break;
                    }
                    if (f == 0 && c == '\\') {
                        f = 1;
                    } else {
                        f = 0;
                    }
                } while (true);
                sb.append(c);
                System.out.println(sb.toString());
                if (c == '\'') {
                    tokens.add(new Token(TokenType.CHRCON, sb.toString()));
                } else {
                    tokens.add(new Token(TokenType.STRCON, sb.toString()));
                }
                move();
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
        do {
            sb.append(c);
            move();
            if (!isValid()) {
                break;
            }
            c = processor.getChar();
        }
        while (Character.isDigit(c)); // out when not digit

        tokens.add(new Token(TokenType.INTCON, sb.toString()));
    }

    private void tokenizeDash() {
        // check next
        move();
        char c = processor.getChar();
        if (c == '/') { // single line
            int line = processor.getCurLine();
            while (line == processor.getCurLine()) {
                move();
            } // out when nextLine
        } else if (c == '*') { // multiline
            // go until meet '*/'
            int flag = 0;
            move();
            while(isValid()) {
                char tar = processor.getChar();
                if (tar == '*') {
                    flag = 1;
                } else if (flag == 1 && tar == '/'){
                    move(); // move to c after /
                    break;
                } else {
                    flag = 0;
                }
                move();
            }
        } else {
            tokens.add(new Token(TokenType.DIV, "/"));
            // point at c after '/'
        }
    }

    private void tokenizeAlphabet(char c) {
        StringBuilder sb = new StringBuilder();
        do {
            sb.append(c);
            move();
            if (!isValid()) {
                break;
            }
            c = processor.getChar();
        }
        while (Character.isAlphabetic(c) || c == '_' || Character.isDigit(c));
        // out when not alphabetic
        tokens.add(new Token(classify(sb.toString()), sb.toString()));
    }

    private int tokenizeSeparator(char c) {
        if (c == '+') {
            tokens.add(new Token(TokenType.PLUS, "+"));
            move();
            return 0;
        } else if (c == '-') {
            tokens.add(new Token(TokenType.MINU, "-"));
            move();
            return 0;
        } else if (c == '*') {
            tokens.add(new Token(TokenType.MULT, "*"));
            move();
            return 0;
        } else if (c == '%') {
            tokens.add(new Token(TokenType.MOD, "%"));
            move();
            return 0;
        } else if (c == ';') {
            tokens.add(new Token(TokenType.SEMICN, ";"));
            move();
            return 0;
        } else if (c == ',') {
            tokens.add(new Token(TokenType.COMMA, ","));
            move();
            return 0;
        } else if (c == '(') {
            tokens.add(new Token(TokenType.LPARENT, "("));
            move();
            return 0;
        } else if (c == ')') {
            tokens.add(new Token(TokenType.RPARENT, ")"));
            move();
            return 0;
        } else if (c == '[') {
            tokens.add(new Token(TokenType.LBRACK, "["));
            move();
            return 0;
        } else if (c == ']') {
            tokens.add(new Token(TokenType.RBRACK, "]"));
            move();
            return 0;
        } else if (c == '{') {
            tokens.add(new Token(TokenType.LBRACE, "{"));
            move();
            return 0;
        } else if (c == '}') {
            tokens.add(new Token(TokenType.RBRACE, "}"));
            move();
            return 0;
        }

        // to be handle: !(!=), &(&&), |(||), <(<=), >(>=), =(==)
        move();
        char next;
        if (isValid()) {
            next = processor.getChar();
        } else {
            next = '\0';
        }

        if (c == '!' && next == '=') {
            tokens.add(new Token(TokenType.NEQ, "!="));
            move();
        } else if (c == '!') {
            tokens.add(new Token(TokenType.NOT, "!"));
        }
        if (c == '&') {
            if (next == '&') {
                tokens.add(new Token(TokenType.AND, "&&"));
                move();
            } else {
                error = true;
                return -1;
            }
        }
        if (c == '|') {
            if (next == '|') {
                tokens.add(new Token(TokenType.OR, "||"));
                move();
            } else {
                error = true;
                return -1;
            }
        }
        if (c == '<') {
            if (next == '=') {
                tokens.add(new Token(TokenType.LEQ, "<="));
                move();
            } else {
                tokens.add(new Token(TokenType.LSS, "<"));
            }
        }
        if (c == '>') {
            if (next == '=') {
                tokens.add(new Token(TokenType.GEQ, ">="));
                move();
            } else {
                tokens.add(new Token(TokenType.GRE, ">"));
            }
        }
        if (c == '=') {
            if (next == '=') {
                tokens.add(new Token(TokenType.EQL, "=="));
                move();
            } else {
                tokens.add(new Token(TokenType.ASSIGN, "="));
            }
        }
        return 0;
    }

    // observer
    private boolean isValid() { // check if processor is valid
        return !processor.isFileEnd();
    }

    // modifier
    private void move() {
        processor.move();
    }

    /**
     * this function should skip blanks
     */
    private void skip() {
        while(isValid()) {
            char c = processor.getChar();
            if (Character.isWhitespace(c)) {
                move();
            } else {
                break;
            }
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
