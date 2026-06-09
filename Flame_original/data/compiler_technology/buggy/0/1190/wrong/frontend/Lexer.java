package frontend;

import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Lexer {
    private final String text;
    private int pos;
    private static int line;
    private char currentChar;
    private final List<Token> tokens = new ArrayList<>();

    public Lexer(String text) {
        this.text = text;
        this.pos = 0;
        line = 1;
        this.currentChar = text.charAt(pos);

        Token token;
        while (currentChar != '\0') {
            token = getOneToken();
            tokens.add(token);
        }
    }

    public List<Token> getTokens() {
        return tokens;
    }

    private void advance() {
        if (currentChar == '\n') {
            line++;
        }
        pos++;
        if (pos >= text.length()) {
            currentChar = '\0';
        } else {
            currentChar = text.charAt(pos);
        }
    }

    public void printTokens() throws Exception {
        OutputStreamWriter writer1 = new OutputStreamWriter(new FileOutputStream("lexer.txt"));
        OutputStreamWriter writer2 = new OutputStreamWriter(new FileOutputStream("error.txt"));
        for (Token token : tokens) {
            if (token == null) {
                continue;
            }
            if (token.getErrorCode() != 0) {
                writer2.write(token.error());
            } else {
                writer1.write(token.toString());
            }
        }
        writer1.close();
        writer2.close();
    }

    private char peekNextChar() {
        if (pos >= text.length()) {
            return '\0';
        }
        return text.charAt(pos + 1);
    }

    private char peekPrevChar() {
        if (pos == 0) {
            return '\0';
        }
        return text.charAt(pos - 1);
    }

    private boolean handleComment() {
        if (currentChar == '/') { // 去除注释
            if (peekNextChar() == '/') {
                advance();
                advance();
                while (currentChar != '\0' && currentChar != '\n') {
                    advance();
                }
                return true;
            } else if (peekNextChar() == '*') {
                advance();
                advance();
                advance();
                while (currentChar != '\0' && !(peekPrevChar() == '*' && currentChar == '/')) {
                    advance();
                }
                advance();
                return true;
            }
        }
        return false;
    }

    private Token handleNumber() {
        StringBuilder sb = new StringBuilder();
        while (Character.isDigit(currentChar)) {
            sb.append(currentChar);
            advance();
        }
        return new NumberToken(sb.toString());
    }

    private Token handleIdentifier() {
        StringBuilder sb = new StringBuilder();
        while (currentChar == '_' || Character.isLetter(currentChar) || Character.isDigit(currentChar)) {
            sb.append(currentChar);
            advance();
        }
        return new IdentToken(sb.toString());
    }

    private Token handleStringOrChar() {
        StringBuilder sb = new StringBuilder();
        char quoteType = currentChar;
        sb.append(currentChar);
        advance();
        while (currentChar != '\0' && currentChar != quoteType) {
            if (currentChar == '\\') {
                // TODO: 处理转义字符
                sb.append(currentChar);
                advance();
            }
            sb.append(currentChar);
            advance();
        }
        sb.append(currentChar);
        advance();
        return new SymbolToken(sb.toString());
    }

    private Token handleSymbol() {
        StringBuilder sb = new StringBuilder();
        String tmp = String.format("%c%c", currentChar, peekNextChar());
        if (!Character.isWhitespace(currentChar) && !Character.isLetter(currentChar) && !Character.isDigit(currentChar)) {
            sb.append(currentChar);
            advance();
        }
        if (tmp.equals("!=") || tmp.equals("&&") || tmp.equals("||") || tmp.equals("==") || tmp.equals(">=") || tmp.equals("<=")) {
            sb.append(currentChar);
            advance();
        }
        try {
            return new SymbolToken(sb.toString());
        } catch (RuntimeException e) {
            System.err.println(e.getMessage());
            return null;
        }
    }

    private Token getOneToken() {
        while (true) { // 去除空格和注释
            if (currentChar == '\0') {
                break;
            } else if (Character.isWhitespace(currentChar)) {
                advance();
            } else if (currentChar == '/') {
                if (!handleComment()) {
                    break;
                }
            } else {
                break;
            }
        }
        if (currentChar == '\0') {
            return null;
        } else if (Character.isDigit(currentChar)) {
            return handleNumber();
        } else if (Character.isLetter(currentChar)) {
            return handleIdentifier();
        } else {
            if (currentChar == '"' || currentChar == '\'') {
                return handleStringOrChar();
            } else {
                return handleSymbol();
            }
        }
    }

    interface Token {
        String toString();

        String error();

        char getErrorCode();
    }

    static class IdentToken implements Token {
        enum Type {
            IDENFR,
            CONSTTK, INTTK, CHARTK, VOIDTK,
            IFTK, ELSETK, BREAKTK, CONTINUETK, FORTK, RETURNTK,
            MAINTK, GETINTTK, GETCHARTK, PRINTFTK,
            ERROR
        }

        private final Type type;
        private final String value;
        private final int ln;

        private char errorCode = 0;

        IdentToken(String value) {
            this.ln = line;
            this.value = value;
            switch (value) {
                case "int":
                    this.type = Type.INTTK;
                    break;
                case "char":
                    this.type = Type.CHARTK;
                    break;
                case "void":
                    this.type = Type.VOIDTK;
                    break;
                case "const":
                    this.type = Type.CONSTTK;
                    break;
                case "if":
                    this.type = Type.IFTK;
                    break;
                case "else":
                    this.type = Type.ELSETK;
                    break;
                case "break":
                    this.type = Type.BREAKTK;
                    break;
                case "continue":
                    this.type = Type.CONTINUETK;
                    break;
                case "for":
                    this.type = Type.FORTK;
                    break;
                case "return":
                    this.type = Type.RETURNTK;
                    break;
                case "main":
                    this.type = Type.MAINTK;
                    break;
                case "printf":
                    this.type = Type.PRINTFTK;
                    break;
                case "getint":
                    this.type = Type.GETINTTK;
                    break;
                case "getchar":
                    this.type = Type.GETCHARTK;
                    break;
                default:
                    this.type = Type.IDENFR;
                    break;
            }
        }

        @Override
        public String toString() {
            return String.format("%s %s\n", type, value);
        }

        @Override
        public String error() {
            return String.format("%d %c\n", ln, errorCode);
        }

        @Override
        public char getErrorCode() {
            return this.errorCode;
        }
    }

    static class NumberToken implements Token {
        enum Type {
            INTCON,
            ERROR
        }

        private final Type type;
        private final String value;
        private final int ln;
        private char errorCode = 0;

        NumberToken(String value) {
            this.ln = line;
            this.value = value;
            this.type = Type.INTCON;
        }

        @Override
        public String toString() {
            return String.format("%s %s\n", type, value);
        }

        @Override
        public String error() {
            return String.format("%d %c\n", ln, errorCode);
        }

        @Override
        public char getErrorCode() {
            return this.errorCode;
        }
    }

    static class SymbolToken implements Token {
        enum Type {
            STRCON, CHRCON, COMMA, SEMICN,
            LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
            NOT, OR, AND, EQL, NEQ, GRE, GEQ, LSS, LEQ,
            PLUS, MINU, MULT, DIV, MOD, ASSIGN,
            ERROR
        }

        private final Type type;
        private final String value;
        private final int ln;
        private char errorCode = 0;

        SymbolToken(String value) {
            this.ln = line;
            this.value = value;
            switch (value) {
                case ",":
                    this.type = Type.COMMA;
                    break;
                case ";":
                    this.type = Type.SEMICN;
                    break;
                case "(":
                    this.type = Type.LPARENT;
                    break;
                case ")":
                    this.type = Type.RPARENT;
                    break;
                case "[":
                    this.type = Type.LBRACK;
                    break;
                case "]":
                    this.type = Type.RBRACK;
                    break;
                case "{":
                    this.type = Type.LBRACE;
                    break;
                case "}":
                    this.type = Type.RBRACE;
                    break;
                case "!":
                    this.type = Type.NOT;
                    break;
                case "||":
                    this.type = Type.OR;
                    break;
                case "&&":
                    this.type = Type.AND;
                    break;
                case "==":
                    this.type = Type.EQL;
                    break;
                case "!=":
                    this.type = Type.NEQ;
                    break;
                case ">":
                    this.type = Type.GRE;
                    break;
                case ">=":
                    this.type = Type.GEQ;
                    break;
                case "<":
                    this.type = Type.LSS;
                    break;
                case "<=":
                    this.type = Type.LEQ;
                    break;
                case "+":
                    this.type = Type.PLUS;
                    break;
                case "-":
                    this.type = Type.MINU;
                    break;
                case "*":
                    this.type = Type.MULT;
                    break;
                case "/":
                    this.type = Type.DIV;
                    break;
                case "%":
                    this.type = Type.MOD;
                    break;
                case "=":
                    this.type = Type.ASSIGN;
                    break;
                default:
                    if (value.charAt(0) == '"' && value.charAt(value.length() - 1) == '"') {
                        //TODO: "he says, \"Hello!\".\n"
                        this.type = Type.STRCON;
                    } else if (value.charAt(0) == '\'' && value.charAt(value.length() - 1) == '\'') {
                        //TODO: 其他的CHAR_CONTENT的格式：'\'', '\n', '\32', '\126', ...
                        this.type = Type.CHRCON;
                    } else {
                        assert value.equals("|") || value.equals("&");
                        this.type = Type.ERROR;
                        this.errorCode = 'a';
                    }
            }
        }

        @Override
        public String toString() {
            return String.format("%s %s\n", type, value);
        }

        @Override
        public String error() {
            return String.format("%d %c\n", ln, errorCode);
        }

        @Override
        public char getErrorCode() {
            return this.errorCode;
        }
    }

}
