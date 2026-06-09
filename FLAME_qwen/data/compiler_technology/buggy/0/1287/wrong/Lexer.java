import java.util.ArrayList;

public class Lexer {
    private String string;
    private int pos = 0;
    private int linenum = 1;
    private int errorLinenum = 0;

    public Lexer(String s) {
        this.string = s;
    }

    public boolean isIdentifierNonDigit(char c) {
        return Character.isAlphabetic(c) || c == '_';
    }

    public class Token {
        private LexType lexType;
        private String string;
        private int linenum;

        public Token(LexType lexType, String s, int linenum) {
            this.string = s;
            this.lexType = lexType;
            this.linenum = linenum;
        }

        public String getToken() {
            return lexType.toString() + " " + string + "\n";
        }
    }

    public int getPos() {
        return pos;
    }
    public int getErrorLineNum() {
        return errorLinenum;
    }

    public Token ReservedOrIdent(String s) {
        switch (s) {
            case "main":
                return new Token(LexType.MAINTK, s, linenum);
            case "const":
                return new Token(LexType.CONSTTK, s, linenum);
            case "int":
                return new Token(LexType.INTTK, s, linenum);
            case "char":
                return new Token(LexType.CHARTK, s, linenum);
            case "break":
                return new Token(LexType.BREAKTK, s, linenum);
            case "continue":
                return new Token(LexType.CONTINUETK, s, linenum);
            case "if":
                return new Token(LexType.IFTK, s, linenum);
            case "else":
                return new Token(LexType.ELSETK, s, linenum);
            case "for":
                return new Token(LexType.FORTK, s, linenum);
            case "getint":
                return new Token(LexType.GETINTTK, s, linenum);
            case "getchar":
                return new Token(LexType.GETCHARTK, s, linenum);
            case "printf":
                return new Token(LexType.PRINTFTK, s, linenum);
            case "return":
                return new Token(LexType.RETURNTK, s, linenum);
            case "void":
                return new Token(LexType.VOIDTK, s, linenum);
            default:
                return new Token(LexType.IDENFR, s, linenum);
        }
    }

    public Token move() {
        StringBuilder token = new StringBuilder();
        if (pos == string.length()) {
            return null;
        }
        char c = string.charAt(pos);
        if (isIdentifierNonDigit(c)) {
            token.append(c);
            pos++;
            while (pos < string.length() && (isIdentifierNonDigit(string.charAt(pos))
                    || Character.isDigit(string.charAt(pos)))) {
                token.append(string.charAt(pos++));
            }
            return ReservedOrIdent(token.toString());
        }
        else if (Character.isDigit(c)) {
            token.append(c);
            pos++;
            while (pos < string.length() && Character.isDigit(string.charAt(pos))) {
                token.append(string.charAt(pos++));
            }
            return new Token(LexType.INTCON, token.toString(), linenum);
        }
        else if (c == '/') {
            token.append(c);
            pos++;
            if (pos < string.length() && string.charAt(pos) == '/') {
                pos++;
                while (pos < string.length() && string.charAt(pos) != '\n') {
                    pos++;
                }
                if (pos < string.length()) {
                    linenum++;
                    pos++;
                }
            }
            else if (pos < string.length() && string.charAt(pos) == '*') {
                pos++;
                while (pos < string.length()) {
                    while (pos < string.length() && string.charAt(pos) != '*') {
                        if (string.charAt(pos) == '\n') {
                            linenum++;
                        }
                        pos++;
                    }
                    while (pos < string.length() && string.charAt(pos) == '*') {
                        pos++;
                    }
                    if (pos < string.length() && string.charAt(pos) == '/') {
                        pos++;
                        break;
                    }
                }
            }
            else {
                return new Token(LexType.DIV, token.toString(), linenum);
            }
        }
        else if (c == '\"') {
            token.append(c);
            pos++;
            while (pos < string.length() && string.charAt(pos) != '\"') {
                token.append(string.charAt(pos++));
            }
            token.append(string.charAt(pos++));
            return new Token(LexType.STRCON, token.toString(), linenum);
        }
        else if (c == '\'') {
            token.append(string.charAt(pos++));
            token.append(string.charAt(pos++));
            token.append(string.charAt(pos++));
            return new Token(LexType.CHRCON, token.toString(), linenum);
        }
        else if (c == '&') {
            token.append(string.charAt(pos++));
            if (string.charAt(pos) != '&') {
                errorLinenum = linenum;
                return new Token(LexType.AND, "&&", linenum);
            }
            else {
                pos++;
                return new Token(LexType.AND, "&&", linenum);
            }
        }
        else if (c == '|') {
            token.append(string.charAt(pos++));
            if (string.charAt(pos) != '|') {
                errorLinenum = linenum;
                return new Token(LexType.OR, "||", linenum);
            }
            else {
                pos++;
                return new Token(LexType.OR, "||", linenum);
            }
        }
        else if (c == '>') {
            token.append(string.charAt(pos++));
            if (string.charAt(pos) != '=') {
                return new Token(LexType.GRE, ">", linenum);
            }
            else {
                pos++;
                return new Token(LexType.GEQ, ">=", linenum);
            }
        }
        else if (c == '<') {
            token.append(string.charAt(pos++));
            if (string.charAt(pos) != '=') {
                return new Token(LexType.LSS, "<", linenum);
            }
            else {
                pos++;
                return new Token(LexType.LEQ, "<=", linenum);
            }
        }
        else if (c == '=') {
            token.append(string.charAt(pos++));
            if (string.charAt(pos) != '=') {
                return new Token(LexType.ASSIGN, "=", linenum);
            }
            else {
                pos++;
                return new Token(LexType.EQL, "==", linenum);
            }
        }
        else if (c == '!') {
            token.append(string.charAt(pos++));
            if (string.charAt(pos) != '=') {
                return new Token(LexType.NOT, "!", linenum);
            }
            else {
                pos++;
                return new Token(LexType.NEQ, "!=", linenum);
            }
        }
        else if (c == '\n') {
            linenum++;
            pos++;
        }
        else if (c == ' ' || c == '\t') {
            pos++;
            while (pos < string.length() && (string.charAt(pos) == ' '
                    || string.charAt(pos) == '\t')) {
                pos++;
            }
        }
        else {
            token.append(c);
            pos++;
            switch (c) {
                case '+':
                    return new Token(LexType.PLUS, token.toString(), linenum);
                case '-':
                    return new Token(LexType.MINU, token.toString(), linenum);
                case '*':
                    return new Token(LexType.MULT, token.toString(), linenum);
                case '%':
                    return new Token(LexType.MOD, token.toString(), linenum);
                case ';':
                    return new Token(LexType.SEMICN, token.toString(), linenum);
                case ',':
                    return new Token(LexType.COMMA, token.toString(), linenum);
                case '(':
                    return new Token(LexType.LPARENT, token.toString(), linenum);
                case ')':
                    return new Token(LexType.RPARENT, token.toString(), linenum);
                case '[':
                    return new Token(LexType.LBRACK, token.toString(), linenum);
                case ']':
                    return new Token(LexType.RBRACK, token.toString(), linenum);
                case '{':
                    return new Token(LexType.LBRACE, token.toString(), linenum);
                case '}':
                    return new Token(LexType.RBRACE, token.toString(), linenum);
                default:
                    break;
            }
        }
        return null;
    }
}
