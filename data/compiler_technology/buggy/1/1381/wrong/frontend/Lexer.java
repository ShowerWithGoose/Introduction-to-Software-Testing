package frontend;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import error.Error;

public class Lexer {
    public static final boolean DEBUG_MODE = true;
    private final Scanner scanner;
    private String curLine;
    private int pos;
    private int lineCount;
    private HashMap<Integer, ArrayList<Token>> lexerTokens;
    private ArrayList<Error> errorList;
    private HashMap<String, Token.TokenType> reservedWords;

    public Lexer(Scanner scanner) {
        this.scanner = scanner;
        this.curLine = "";
        this.lineCount = 0;
        this.pos = 0;
        lexerTokens = new HashMap<>();
        errorList = new ArrayList<>();
        initReservedWords();
    }

    private void initReservedWords() {
        reservedWords = new HashMap<>();
        reservedWords.put("main", Token.TokenType.MAINTK);
        reservedWords.put("const", Token.TokenType.CONSTTK);
        reservedWords.put("break", Token.TokenType.BREAKTK);
        reservedWords.put("continue", Token.TokenType.CONTINUETK);
        reservedWords.put("if", Token.TokenType.IFTK);
        reservedWords.put("else", Token.TokenType.ELSETK);
        reservedWords.put("for", Token.TokenType.FORTK);
        reservedWords.put("return", Token.TokenType.RETURNTK);
        reservedWords.put("int", Token.TokenType.INTTK);
        reservedWords.put("char", Token.TokenType.CHARTK);
        reservedWords.put("void", Token.TokenType.VOIDTK);
        reservedWords.put("getint", Token.TokenType.GETINTTK);
        reservedWords.put("getchar", Token.TokenType.GETCHARTK);
        reservedWords.put("printf", Token.TokenType.PRINTFTK);
    }

    public char getCurChar() {
        return curLine.charAt(pos);
    }

    public ArrayList<Error> getErrorList() {
        return errorList;
    }

    public HashMap<Integer, ArrayList<Token>> getTokens() {
        if (!lexerTokens.isEmpty()) { return lexerTokens; }
        lexerTokens.put(0, new ArrayList<>());
        while (scanner.hasNextLine()) {
            lineCount++;
            // System.out.println("line " + lineCount + ": ");
            curLine = scanner.nextLine();
            ArrayList<Token> tokens = new ArrayList<>();
            lexerTokens.put(lineCount, tokens);
            pos = 0;
            while (pos < curLine.length()) {
                int line = lineCount;
                Token token = getNextToken();
                if (token.getType() == Token.TokenType.COMMENT
                        || token.getType() == Token.TokenType.ERROR
                        || token.getType() == Token.TokenType.EOF) {
                    // if (DEBUG_MODE) { tokens.add(token); }
                } else {
                    tokens.add(token);
                }
                if (line != lineCount && !lexerTokens.containsKey(lineCount)) { // 针对多行跨行注释
                    tokens = new ArrayList<>();
                    lexerTokens.put(lineCount, tokens);
                }

            }
        }
        for (int i = 1; i <= lineCount; i++) {
            if (!lexerTokens.containsKey(i)) {
                lexerTokens.put(i, new ArrayList<>());
            }
        }
        return lexerTokens;
    }

    public void printTokens() {
        for (int i = 1; i <= lineCount; i++) {
            System.out.println("line " + i + ": ");
            if (lexerTokens.containsKey(i)) {
                ArrayList<Token> tokens = lexerTokens.get(i);
                for (Token token : tokens) {
                    System.out.println(token.getType() + " " + token.getValue());
                }
            }
        }
    }

    public Token getNextToken() {
        while (pos < curLine.length() && isWhitespace(getCurChar())) { pos++; }
        if (pos >= curLine.length()) { return new Token(Token.TokenType.EOF); }
        char c = getCurChar();
        // System.out.println("FIRST: " + c);
        if (c == '_' || Character.isLetter(c)) { // Ident / ReservedWord
            return handleIdentOrKeyword();
        } else if (Character.isDigit(c)) { // IntConst
            return handleIntConst();
        } else if (c == '\'') { // CharConst
            return handleCharConst();
        } else if (c == '\"') { // StringConst
            return handleStringConst();
        } else if (isOperator(c)) {
            return handleOperator();
        } else if (isDelimiter(c)) {
            return handleDelimiter();
        } else {
            pos++;
            if (DEBUG_MODE) { System.out.println("ERROR: get unknown character"); }
            return new Token(Token.TokenType.ERROR);
        }
    }

    public Token handleIdentOrKeyword() {
        StringBuilder sb = new StringBuilder();
        while (pos < curLine.length()
                && (Character.isLetterOrDigit(getCurChar()) || getCurChar() == '_')) {
            sb.append(getCurChar());
            pos++;
        }
        String value = sb.toString();
        return reservedWords.containsKey(value) ?
                new Token(reservedWords.get(value), value) :
                new Token(Token.TokenType.IDENFR, value);
    }

    public Token handleIntConst() { // TODO：需注意 前导0 以及 int越界 问题
        StringBuilder sb = new StringBuilder();
        while (pos < curLine.length() && isDigit(getCurChar())) {
            sb.append(getCurChar());
            pos++;
        }
        return new Token(Token.TokenType.INTCON, sb.toString());
    }

    public Token handleCharConst() {
        pos++;
        char ch = getCurChar();
        if (ch == '\\') { // 转义字符
            pos++;
            ch = getCurChar();
            pos += 2;
            if (isEscapeChar(ch)) {
                return new Token(Token.TokenType.CHRCON, "'\\" + ch + "'");
            } else {
                if (DEBUG_MODE) System.out.println("ERROR: get unknown escape character");
                return new Token(Token.TokenType.ERROR);
            }
        } else if (ch == '\'') {
            pos += 2;
            if (DEBUG_MODE) System.out.println("ERROR: get ''' ");
            return new Token(Token.TokenType.ERROR);
        } else if (ch == '\"') {
            pos += 2;
            if (DEBUG_MODE) System.out.println("ERROR: get '\"' ");
            return new Token(Token.TokenType.ERROR);
        } else if (ch >= 32 && ch <= 126) {
            pos += 2;
            return new Token(Token.TokenType.CHRCON, "'" + ch + "'");
        } else {
            if (DEBUG_MODE) System.out.println("ERROR: get unknown character");
            pos += 2;
            return new Token(Token.TokenType.ERROR);
        }
    }

    public Token handleStringConst() {
        pos++;
        StringBuilder sb = new StringBuilder();
        while (pos < curLine.length()) {
            char c = getCurChar();
            if (c == '\\') {
                sb.append(c);
                pos++;
                if (isEscapeChar(getCurChar())) {
                    sb.append(getCurChar());
                }
                pos++;
            } else if (c == '\"') {
                pos++;
                break;
            } else {
                sb.append(c);
                pos++;
            }
        }
        return new Token(Token.TokenType.STRCON, "\"" + sb + "\"");
    }

    public Token handleOperator() {
        char c = getCurChar();
        switch (c) {
            case '!' -> {
                pos++;
                if (getCurChar() == '=') {
                    pos++;
                    return new Token(Token.TokenType.NEQ, "!=");
                } else {
                    return new Token(Token.TokenType.NOT, "!");
                }
            }
            case '&' -> {
                pos++;
                if (getCurChar() == '&') {
                    pos++;
                    return new Token(Token.TokenType.AND, "&&");
                } else {
                    if (DEBUG_MODE) System.out.println("ERROR: get & when we expect &&");
                    // return new Token(Token.TokenType.ERROR);
                    addError(lineCount, "a");
                    return new Token(Token.TokenType.AND, "&");
                }
            }
            case '|' -> {
                pos++;
                if (getCurChar() == '|') {
                    pos++;
                    return new Token(Token.TokenType.OR, "||");
                } else {
                    if (DEBUG_MODE) System.out.println("ERROR: get | when we expect ||");
                    // return new Token(Token.TokenType.ERROR);
                    addError(lineCount, "a");
                    return new Token(Token.TokenType.OR, "|");
                }
            }
            case '=' -> {
                pos++;
                if (getCurChar() == '=') {
                    pos++;
                    return new Token(Token.TokenType.EQL, "==");
                } else {
                    return new Token(Token.TokenType.ASSIGN, "=");
                }
            }
            case '<' -> {
                pos++;
                if (getCurChar() == '=') {
                    pos++;
                    return new Token(Token.TokenType.LEQ, "<=");
                } else {
                    return new Token(Token.TokenType.LSS, "<");
                }
            }
            case '>' -> {
                pos++;
                if (getCurChar() == '=') {
                    pos++;
                    return new Token(Token.TokenType.GEQ, ">=");
                } else {
                    return new Token(Token.TokenType.GRE, ">");
                }
            }
            case '/' -> {
                pos++;
                if (getCurChar() == '/') {
                    return handleSingleLineComment();
                } else if (getCurChar() == '*') {
                    return handleMultiLineComment();
                } else {
                    return new Token(Token.TokenType.DIV, "/");
                }
            }
            case '+' -> {
                pos++;
                return new Token(Token.TokenType.PLUS, "+");
            }
            case '-' -> {
                pos++;
                return new Token(Token.TokenType.MINU, "-");
            }
            case '*' -> {
                pos++;
                return new Token(Token.TokenType.MULT, "*");
            }
            case '%' -> {
                pos++;
                return new Token(Token.TokenType.MOD, "%");
            }
            default -> {
                pos++;
                if (DEBUG_MODE) System.out.println("ERROR: get unknown operator");
                return new Token(Token.TokenType.ERROR);
            }
        }
    }

    public Token handleSingleLineComment() {
        pos = curLine.length();
        return new Token(Token.TokenType.COMMENT);
    }

    public Token handleMultiLineComment() { /*abc*/
        pos++;
        int index = curLine.indexOf("*/", pos);
        if (index != -1) {
            pos = index + 2;
            return new Token(Token.TokenType.COMMENT);
        }
        while (scanner.hasNextLine()) {
            curLine = scanner.nextLine();
            pos = 0;
            lineCount++;
            if (curLine.contains("*/")) {
                pos = curLine.indexOf("*/") + 2;
                return new Token(Token.TokenType.COMMENT);
            }
        }
        return new Token(Token.TokenType.ERROR);
    }

    public Token handleDelimiter() {
        char c = getCurChar();
        Token token;
        switch (c) {
            case ';' -> token = new Token(Token.TokenType.SEMICN, String.valueOf(c));
            case ',' -> token = new Token(Token.TokenType.COMMA, String.valueOf(c));
            case '(' -> token = new Token(Token.TokenType.LPARENT, String.valueOf(c));
            case ')' -> token = new Token(Token.TokenType.RPARENT, String.valueOf(c));
            case '[' -> token = new Token(Token.TokenType.LBRACK, String.valueOf(c));
            case ']' -> token = new Token(Token.TokenType.RBRACK, String.valueOf(c));
            case '{' -> token = new Token(Token.TokenType.LBRACE, String.valueOf(c));
            case '}' -> token = new Token(Token.TokenType.RBRACE, String.valueOf(c));
            default -> {
                if (DEBUG_MODE) System.out.println("ERROR: get unknown delimiter");
                token = new Token(Token.TokenType.ERROR);
            }
        }
        pos++;
        return token;
    }

    public boolean isEscapeChar(char ch) {
        return ch == 'a' || ch == 'b' || ch == 't' || ch == 'n' || ch == 'v' || ch == 'f'
                || ch == '\"' || ch == '\'' || ch == '\\' || ch == '0';
    }

    public boolean isDelimiter(char ch) {
        return ch == ';' || ch == ',' || ch == '(' || ch == ')'
                || ch == '[' || ch == ']' || ch == '{' || ch == '}';
    }

    public boolean isOperator(char ch) {
        return ch == '!' || ch == '&' || ch == '|' || ch == '=' || ch == '<' || ch == '>'
                || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
    }

    public boolean isWhitespace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == 11;
    }

    public boolean isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    public int getLineCount() {
        return lineCount;
    }

    public void addError(int line, String errorType) {
        Error error = new Error(line, errorType);
        errorList.add(error);
    }
}
