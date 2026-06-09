import java.util.HashMap;

public class Lexer {
    private final String source;
    private int pos;
    private String token;
    private LexType type;
    private final HashMap<String, LexType> reservedWords;
    private int lineno;
    private Integer numValue;

    public Lexer(String source) {
        this.source = source;
        this.pos = 0;
        this.token = "";
        this.type = null;
        this.reservedWords = new HashMap<>();
        getReservedWords();
        this.lineno = 1;
        this.numValue = null;
        next();
    }

    private void getReservedWords() {
        reservedWords.put("main", LexType.MAINTK);
        reservedWords.put("const", LexType.CONSTTK);
        reservedWords.put("int", LexType.INTTK);
        reservedWords.put("char", LexType.CHARTK);
        reservedWords.put("break", LexType.BREAKTK);
        reservedWords.put("continue", LexType.CONTINUETK);
        reservedWords.put("if", LexType.IFTK);
        reservedWords.put("else", LexType.ELSETK);
        reservedWords.put("for", LexType.FORTK);
        reservedWords.put("getint", LexType.GETINTTK);
        reservedWords.put("getchar", LexType.GETCHARTK);
        reservedWords.put("printf", LexType.PRINTFTK);
        reservedWords.put("void", LexType.VOIDTK);
        reservedWords.put("return", LexType.RETURNTK);
    }

    public void next() {
        if (pos >= source.length()) {
            token = null;
            type = null;
            numValue = null;
            return;
        }
        char c = source.charAt(pos);
        if (c == '\n') {
            pos++;
            lineno++;
            token = "";
            return;
        }
        if (Character.isDigit(c)) {
            token = getNumber();
            type = LexType.INTCON;
            // numValue = Integer.valueOf(token);
            return;
        }
        if (isNonDigit(c)) {
            token = getIdent();
            if (reservedWords.containsKey(token)) {
                type = reservedWords.get(token);
            } else {
                type = LexType.IDENFR;
            }
            numValue = null;
            return;
        }
        if (c == '\'') {
            token = getCha();
            type = LexType.CHRCON;
            numValue = null;
            return;
        }
        if (c == '"') {
            token = getString();
            type = LexType.STRCON;
            numValue = null;
            return;
        }
        if (c == '+') {
            token = "+";
            pos++;
            type = LexType.PLUS;
            numValue = null;
            return;
        }
        if (c == '-') {
            token = "-";
            pos++;
            type = LexType.MINU;
            numValue = null;
            return;
        }
        if (c == '*') {
            token = "*";
            pos++;
            type = LexType.MULT;
            numValue = null;
            return;
        }
        if (c == '/') {
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '/') {
                pos += 2;
                while (pos < source.length() && source.charAt(pos) != '\n') {
                    pos++;
                }
                next();
                return;
            } else if (pos + 1 < source.length() && source.charAt(pos + 1) == '*') {
                pos += 2;
                while (pos < source.length()) {
                    while (pos < source.length() && source.charAt(pos) != '*') {
                        if (source.charAt(pos) == '\n') {
                            lineno++;
                        }
                        pos++;
                    }
                    while (pos < source.length() && source.charAt(pos) == '*') {
                        pos++;
                    }
                    if (pos < source.length() && source.charAt(pos) == '/') {
                        pos++;
                        break;
                    }
                }
                next();
                return;
            } else {
                token = "/";
                type = LexType.DIV;
                pos++;
                numValue = null;
                return;
            }
        }
        if (c == '%') {
            token = "%";
            pos++;
            type = LexType.MOD;
            numValue = null;
            return;
        }
        if (c == ';') {
            token = ";";
            pos++;
            type = LexType.SEMICN;
            numValue = null;
            return;
        }
        if (c == ',') {
            token = ",";
            pos++;
            type = LexType.COMMA;
            numValue = null;
            return;
        }
        if (c == '(') {
            token = "(";
            pos++;
            type = LexType.LPARENT;
            numValue = null;
            return;
        }
        if (c == ')') {
            token = ")";
            pos++;
            type = LexType.RPARENT;
            numValue = null;
            return;
        }
        if (c == '[') {
            token = "[";
            pos++;
            type = LexType.LBRACK;
            numValue = null;
            return;
        }
        if (c == ']') {
            token = "]";
            pos++;
            type = LexType.RBRACK;
            numValue = null;
            return;
        }
        if (c == '{') {
            token = "{";
            pos++;
            type = LexType.LBRACE;
            numValue = null;
            return;
        }
        if (c == '}') {
            token = "}";
            pos++;
            type = LexType.RBRACE;
            numValue = null;
            return;
        }
        if (c == '&') {
            token = "&";
            type = LexType.AND;
            numValue = null;
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '&') {
                token += "&";
                pos += 2;
            } else {
                pos++;
                tokenError();
            }
            return;
        }
        if (c == '|') {
            token = "|";
            type = LexType.OR;
            numValue = null;
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '|') {
                token += "|";
                pos += 2;
            } else {
                pos++;
                tokenError();
            }
            return;
        }
        if (c == '=') {
            token = "=";
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '=') {
                token += "=";
                pos += 2;
                type = LexType.EQL;
            } else {
                pos++;
                type = LexType.ASSIGN;
            }
            numValue = null;
            return;
        }
        if (c == '!') {
            token = "!";
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '=') {
                token += "=";
                pos += 2;
                type = LexType.NEQ;
            } else {
                pos++;
                type = LexType.NOT;
            }
            numValue = null;
            return;
        }
        if (c == '<') {
            token = "<";
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '=') {
                token += "=";
                pos += 2;
                type = LexType.LEQ;
            } else {
                pos++;
                type = LexType.LSS;
            }
            numValue = null;
            return;
        }
        if (c == '>') {
            token = ">";
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '=') {
                token += "=";
                pos += 2;
                type = LexType.GEQ;
            } else {
                pos++;
                type = LexType.GRE;
            }
            numValue = null;
            return;
        }
        token = "";
        pos++;
    }

    private void tokenError() {

    }

    private boolean isNonDigit(char c) {
        return Character.isUpperCase(c) || Character.isLowerCase(c) || c == '_';
    }

    private String getNumber() {
        StringBuilder sb = new StringBuilder();
        while (pos < source.length() && Character.isDigit(source.charAt(pos))) {
            sb.append(source.charAt(pos));
            pos++;
        }
        return sb.toString();
    }

    private String getIdent() {
        StringBuilder sb = new StringBuilder();
        while (pos < source.length() &&
                (isNonDigit(source.charAt(pos)) || Character.isDigit(source.charAt(pos)))) {
            sb.append(source.charAt(pos));
            pos++;
        }
        return sb.toString();
    }

    private String getCha() {
        pos++;
        StringBuilder sb = new StringBuilder("'");
        if (pos < source.length() && source.charAt(pos) == '\\') {
            sb.append(source.charAt(pos));
            pos++;
        }
        sb.append(source.charAt(pos));
        pos += 2;
        sb.append('\'');
        return sb.toString();
    }

    private String getString() {
        pos++;
        StringBuilder sb = new StringBuilder("\"");
        while (pos < source.length() && source.charAt(pos) != '"') {
            sb.append(source.charAt(pos));
            pos++;
        }
        sb.append('"');
        pos++;
        return sb.toString();
    }

    public String getToken() {
        return token;
    }

    public LexType getType() {
        return type;
    }

    public int getLineno() {
        return lineno;
    }

    public Integer getNumValue() {
        return numValue;
    }
}
