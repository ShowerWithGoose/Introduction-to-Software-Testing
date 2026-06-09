package frontend.lexer;

import frontend.Category;
import frontend.Error;
import frontend.FileReadIn;

import java.util.ArrayList;

public class Lexer {
    private final FileReadIn reader;
    private final ArrayList<Token> tokens;
    public Error error;

    public Lexer(String filePath, Error error) {
        this.reader = new FileReadIn(filePath);
        this.tokens = new ArrayList<>();
        this.error = error;
    }

    public ArrayList<Token> lexer() {
        while (true) {
            reader.clearToken();

            char c = skipWhitespace();

            if (c == 0) {
                break;
            }

            if (isLetter(c) || c == '_') {
                handleIdentifierOrKeyword();
            } else if (isDigit(c)) {
                handleNumber();
            } else if (c == '\"') {
                handleString();
            } else if (c == '\'') {
                handleChar();
            } else if (c == '&') {
                handleLogicalOperator('&', Category.AND);
            } else if (c == '|') {
                handleLogicalOperator('|', Category.OR);
            } else if (c == '<') {
                handleRelationalOperator(Category.LSS, Category.LEQ);
            } else if (c == '>') {
                handleRelationalOperator(Category.GRE, Category.GEQ);
            } else if (c == '=') {
                handleEqualityOperator();
            } else if (c == '!') {
                handleNegationOrNotEqual();
            } else if (c == '/') {
                handleSlash();
            } else {
                reader.catToken();
                handleSymbol(c);
            }

            reader.nextChar();
        }
        return this.tokens;
    }

    private char skipWhitespace() {
        char c = reader.getChar();
        while (Character.isWhitespace(c) || (c <= 15 && c >= 11)) {
            if (c == '\n') reader.pushLine();
            reader.nextChar();
            c = reader.getChar();
        }
        return c;
    }

    private boolean isLetter(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    private boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    private void handleIdentifierOrKeyword() {
        char c;
        do {
            reader.catToken();
            reader.nextChar();
            c = reader.getChar();
        } while (isLetter(c) || c == '_' || isDigit(c));

        reader.preChar();
        Category category = reserve(reader.getToken().toString());
        tokens.add(new Token(category == Category.UNKNOWN ? Category.IDENFR : category, reader.getToken().toString(), reader.getCurLine()));
    }

    private void handleNumber() {
        char c;
        do {
            reader.catToken();
            reader.nextChar();
            c = reader.getChar();
        } while (isDigit(c));

        reader.preChar();
        tokens.add(new Token(Category.INTCON, reader.getToken().toString(), reader.getCurLine()));
    }

    private void handleString() {
        reader.catToken();
        reader.nextChar();
        char c = reader.getChar();
        while (c != '\"') {
            reader.catToken();
            reader.nextChar();
            c = reader.getChar();
        }
        reader.catToken();
        tokens.add(new Token(Category.STRCON, reader.getToken().toString(), reader.getCurLine()));
    }

    private void handleChar() {
        reader.catToken();
        reader.nextChar();
        char c = reader.getChar();
        if (c == '\\') {
            reader.catToken();
            reader.nextChar();
        }
        reader.catToken();
        reader.nextChar();  // 跳过结束的'
        reader.catToken();
        tokens.add(new Token(Category.CHRCON, reader.getToken().toString(), reader.getCurLine()));
    }

    private void handleLogicalOperator(char expected, Category category) {
        reader.catToken();
        reader.nextChar();
        char c = reader.getChar();
        if (c == expected) {
            reader.catToken();
            tokens.add(new Token(category, reader.getToken().toString(), reader.getCurLine()));
        } else {
            error.lexError(reader.getCurLine(), "a");
        }
    }

    private void handleRelationalOperator(Category simpleCategory, Category complexCategory) {
        reader.catToken();
        reader.nextChar();
        char c = reader.getChar();
        if (c == '=') {
            reader.catToken();
            tokens.add(new Token(complexCategory, reader.getToken().toString(), reader.getCurLine()));
        } else {
            reader.preChar();
            tokens.add(new Token(simpleCategory, reader.getToken().toString(), reader.getCurLine()));
        }
    }

    private void handleEqualityOperator() {
        reader.catToken();
        reader.nextChar();
        char c = reader.getChar();
        if (c == '=') {
            reader.catToken();
            tokens.add(new Token(Category.EQL, reader.getToken().toString(), reader.getCurLine()));
        } else {
            reader.preChar();
            tokens.add(new Token(Category.ASSIGN, reader.getToken().toString(), reader.getCurLine()));
        }
    }

    private void handleNegationOrNotEqual() {
        reader.catToken();
        reader.nextChar();
        char c = reader.getChar();
        if (c == '=') {
            reader.catToken();
            tokens.add(new Token(Category.NEQ, reader.getToken().toString(), reader.getCurLine()));
        } else {
            reader.preChar();
            tokens.add(new Token(Category.NOT, reader.getToken().toString(), reader.getCurLine()));
        }
    }

    private void handleSymbol(char c) {
        switch (c) {
            case '+': tokens.add(new Token(Category.PLUS, reader.getToken().toString(), reader.getCurLine())); break;
            case '-': tokens.add(new Token(Category.MINU, reader.getToken().toString(), reader.getCurLine())); break;
            case '*': tokens.add(new Token(Category.MULT, reader.getToken().toString(), reader.getCurLine())); break;
            case '%': tokens.add(new Token(Category.MOD, reader.getToken().toString(), reader.getCurLine())); break;
            case ';': tokens.add(new Token(Category.SEMICN, reader.getToken().toString(), reader.getCurLine())); break;
            case ',': tokens.add(new Token(Category.COMMA, reader.getToken().toString(), reader.getCurLine())); break;
            case '(': tokens.add(new Token(Category.LPARENT, reader.getToken().toString(), reader.getCurLine())); break;
            case ')': tokens.add(new Token(Category.RPARENT, reader.getToken().toString(), reader.getCurLine())); break;
            case '[': tokens.add(new Token(Category.LBRACK, reader.getToken().toString(), reader.getCurLine())); break;
            case ']': tokens.add(new Token(Category.RBRACK, reader.getToken().toString(), reader.getCurLine())); break;
            case '{': tokens.add(new Token(Category.LBRACE, reader.getToken().toString(), reader.getCurLine())); break;
            case '}': tokens.add(new Token(Category.RBRACE, reader.getToken().toString(), reader.getCurLine())); break;
        }
    }

    private void handleSlash() {
        reader.catToken();
        reader.nextChar();
        char c = reader.getChar();
        if (c == '/') {
            // 单行注释
            while (c != '\n') {
                reader.nextChar();
                c = reader.getChar();
            }
            reader.pushLine();
        } else if (c == '*') {
            // 多行注释
            reader.nextChar();
            do {
                c = reader.getChar();
                while (c != '*') {
                    if (c == '\n') reader.pushLine();
                    reader.nextChar();
                    c = reader.getChar();
                }
                reader.nextChar();
            } while (reader.getChar() != '/');
        } else {
            reader.preChar();
            tokens.add(new Token(Category.DIV, reader.getToken().toString(), reader.getCurLine()));
        }
    }

    public Category reserve(String value) {
        return switch (value) {
            case "main" -> Category.MAINTK;
            case "const" -> Category.CONSTTK;
            case "int" -> Category.INTTK;
            case "char" -> Category.CHARTK;
            case "break" -> Category.BREAKTK;
            case "continue" -> Category.CONTINUETK;
            case "if" -> Category.IFTK;
            case "else" -> Category.ELSETK;
            case "for" -> Category.FORTK;
            case "getint" -> Category.GETINTTK;
            case "getchar" -> Category.GETCHARTK;
            case "printf" -> Category.PRINTFTK;
            case "return" -> Category.RETURNTK;
            case "void" -> Category.VOIDTK;
            default -> Category.UNKNOWN;
        };
    }
}