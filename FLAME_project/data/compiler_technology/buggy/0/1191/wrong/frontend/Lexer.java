package frontend;

import java.util.HashMap;

public class Lexer {
    private String input;
    private int line;
    private int pos;
    private Character curChar;
    private String curToken;
    private String curType;

    private HashMap<String, String> type;
    private HashMap<Integer, Character> error;

    public enum type {
        IDENFR, INTCON, STRCON, CHRCON,
        MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK,
        FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, VOIDTK,
        NOT, AND, OR, PLUS, MINU, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
        SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE
    }

    public Lexer(String input) {
        this.input = input;
        this.line = 1;
        this.pos = 0;
        this.type = new HashMap<>();
        this.type.put("main", "MAINTK");
        this.type.put("const", "CONSTTK");
        this.type.put("int", "INTTK");
        this.type.put("char", "CHARTK");
        this.type.put("break", "BREAKTK");
        this.type.put("continue", "CONTINUETK");
        this.type.put("if", "IFTK");
        this.type.put("else", "ELSETK");
        this.type.put("for", "FORTK");
        this.type.put("getInt", "GETINTTK");
        this.type.put("getChar", "GETCHARTK");
        this.type.put("printf", "PRINTFTK");
        this.type.put("return", "RETURNTK");
        this.type.put("void", "VOIDTK");
        this.error = new HashMap<>();
    }

    public String getCurToken() {
        return curToken;
    }

    public String getCurType() {
        return curType;
    }

    public HashMap<Integer, Character> getError() {
        return error;
    }

    public void getChar() {
        if (curChar == '\n') {
            line++;
        }
        if (pos < input.length() - 1) {
            curChar = input.charAt(++pos);
        } else if (pos == input.length() - 1) {
            curChar = '\0';
            ++pos;
        }
    }

    public void retract() {
        if (input.charAt(pos - 1) == '\n') {
            line--;
        }
        if (pos > 0) {
            curChar = input.charAt(--pos);
        } else if (pos == 0) {
            curChar = '\0';
            --pos;
        }
    }

    public int getSymbol() {

        StringBuilder sb = new StringBuilder();

        curChar = input.charAt(pos);

        while (curChar == ' ' || curChar == '\n' || curChar == '\t') {
            getChar();
        }

        if (pos == input.length()) {
            return 1;
        }

        if (isLetter(curChar)) {
            while (isLetter(curChar) || isDigit(curChar)) {
                sb.append(curChar);
                getChar();
            }
            curToken = sb.toString();
            curType = findReserved(curToken);
            if (pos == input.length()) {
                return 1;
            }
        } else if (isDigit(curChar)) {
            while (isDigit(curChar)) {
                sb.append(curChar);
                getChar();
            }
            curToken = sb.toString();
            curType = "INTCON";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '\'') {
            sb.append(curChar);
            getChar();
            if (curChar == '\\') {
                sb.append(curChar);
                getChar();
                sb.append(curChar);
                getChar();
                sb.append(curChar);
                getChar();
            } else {
                sb.append(curChar);
                getChar();
                sb.append(curChar);
                getChar();
            }
            curToken = sb.toString();
            curType = "CHRCON";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '\"') {
            sb.append(curChar);
            getChar();
            while (!(curChar == '\"' && (input.charAt(pos - 1) != '\\'
                    || (input.charAt(pos - 1) == '\\' && input.charAt(pos - 2) == '\\')))) {
                sb.append(curChar);
                getChar();
            }
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "STRCON";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '!') {
            sb.append(curChar);
            getChar();
            if (curChar == '=') {
                sb.append(curChar);
                getChar();
                curToken = sb.toString();
                curType = "NEQ";
            } else {
                curToken = sb.toString();
                curType = "NOT";
            }
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '<') {
            sb.append(curChar);
            getChar();
            if (curChar == '=') {
                sb.append(curChar);
                getChar();
                curToken = sb.toString();
                curType = "LEQ";
            } else {
                curToken = sb.toString();
                curType = "LSS";
            }
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '>') {
            sb.append(curChar);
            getChar();
            if (curChar == '=') {
                sb.append(curChar);
                getChar();
                curToken = sb.toString();
                curType = "GEQ";
            } else {
                curToken = sb.toString();
                curType = "GRE";
            }
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '=') {
            sb.append(curChar);
            getChar();
            if (curChar == '=') {
                sb.append(curChar);
                getChar();
                curToken = sb.toString();
                curType = "EQL";
            } else {
                curToken = sb.toString();
                curType = "ASSIGN";
            }
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '&') {
            sb.append(curChar);
            getChar();
            if (curChar == '&') {
                sb.append(curChar);
                getChar();
                curToken = sb.toString();
                curType = "AND";
            } else {
                curToken = "";
                error.put(line, 'a');
            }
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '|') {
            sb.append(curChar);
            getChar();
            if (curChar == '|') {
                sb.append(curChar);
                getChar();
                curToken = sb.toString();
                curType = "OR";
            } else {
                curToken = "";
                error.put(line, 'a');
            }
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '+') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "PLUS";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '-') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "MINU";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '*') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "MULT";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '%') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "MOD";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == ';') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "SEMICN";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == ',') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "COMMA";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '(') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "LPARENT";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == ')') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "RPARENT";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '[') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "LBRACK";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == ']') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "RBRACK";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '{') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "LBRACE";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '}') {
            sb.append(curChar);
            getChar();
            curToken = sb.toString();
            curType = "RBRACE";
            if (pos == input.length()) {
                return 1;
            }
        } else if (curChar == '/') {
            sb.append(curChar);
            getChar();
            if (curChar != '/' && curChar != '*') {
                curToken = sb.toString();
                curType = "DIV";
                if (pos == input.length()) {
                    return 1;
                }
            } else if (curChar == '/') {
                getChar();
                while (curChar != '\n' && pos < input.length()) {
                    getChar();
                }
                curToken = "";
                if (pos == input.length()) {
                    return 1;
                }
            } else {
                getChar();
                while (!(curChar == '/' && input.charAt(pos - 1) == '*')) {
                    getChar();
                }
                getChar();
                curToken = "";
                if (pos == input.length()) {
                    return 1;
                }
            }
        } else {
            curToken = "";
        }

        return 0;

    }

    public String findReserved(String s) {
        return type.getOrDefault(s, "IDENFR");
    }

    public boolean isLetter(Character ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_';
    }

    public boolean isDigit(Character ch) {
        return ch >= '0' && ch <= '9';
    }
}



