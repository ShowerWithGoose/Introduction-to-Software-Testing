package frontend.lexer;

import java.util.HashMap;

public class Lexer {
    private final String source;
    private int pos;
    private Token token;
    private int lineno;
    private final HashMap<String, LexType> reservedWords;

    public Lexer(String source) {
        this.source = source;
        this.pos = 0;
        this.token = null;
        this.lineno = 1;
        this.reservedWords = new HashMap<>();
        getReservedWords();
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
            return;
        }
        char c = source.charAt(pos);
        if (c == '\n') {
            pos++;
            lineno++;
            next();
            return;
        }
        if (Character.isDigit(c)) {
            String content = getNumber();
            LexType type = LexType.INTCON;
            int numValue = Integer.parseInt(content);
            token = new Token(type, content, lineno, numValue);
            return;
        }
        if (isNonDigit(c)) {
            String content = getIdent();
            LexType type;
            if (reservedWords.containsKey(content)) {
                type = reservedWords.get(content);
            } else {
                type = LexType.IDENFR;
            }
            token = new Token(type, content, lineno, null);
            return;
        }
        if (c == '\'') {
            String content = getCha();
            LexType type = LexType.CHRCON;
            token = new Token(type, content, lineno, null);
            return;
        }
        if (c == '"') {
            String content = getString();
            LexType type = LexType.STRCON;
            token = new Token(type, content, lineno, null);
            return;
        }
        if (c == '+') {
            String content = "+";
            LexType type = LexType.PLUS;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == '-') {
            String content = "-";
            LexType type = LexType.MINU;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == '*') {
            String content = "*";
            LexType type = LexType.MULT;
            token = new Token(type, content, lineno, null);
            pos++;
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
                String content = "/";
                LexType type = LexType.DIV;
                token = new Token(type, content, lineno, null);
                pos++;
                return;
            }
        }
        if (c == '%') {
            String content = "%";
            LexType type = LexType.MOD;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == ';') {
            String content = ";";
            LexType type = LexType.SEMICN;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == ',') {
            String content = ",";
            LexType type = LexType.COMMA;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == '(') {
            String content = "(";
            LexType type = LexType.LPARENT;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == ')') {
            String content = ")";
            LexType type = LexType.RPARENT;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == '[') {
            String content = "[";
            LexType type = LexType.LBRACK;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == ']') {
            String content = "]";
            LexType type = LexType.RBRACK;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == '{') {
            String content = "{";
            LexType type = LexType.LBRACE;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == '}') {
            String content = "}";
            LexType type = LexType.RBRACE;
            token = new Token(type, content, lineno, null);
            pos++;
            return;
        }
        if (c == '&') {
            String content = "&";
            LexType type = LexType.AND;
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '&') {
                content += "&";
                token = new Token(type, content, lineno, null);
                pos += 2;
            } else {
                token = new Token(type, content, lineno, null);
                pos++;
                tokenError();
            }
            return;
        }
        if (c == '|') {
            String content = "|";
            LexType type = LexType.OR;
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '|') {
                content += "|";
                token = new Token(type, content, lineno, null);
                pos += 2;
            } else {
                token = new Token(type, content, lineno, null);
                pos++;
                tokenError();
            }
            return;
        }
        if (c == '=') {
            String content = "=";
            LexType type;
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '=') {
                content += "=";
                type = LexType.EQL;
                token = new Token(type, content, lineno, null);
                pos += 2;
            } else {
                type = LexType.ASSIGN;
                token = new Token(type, content, lineno, null);
                pos++;
            }
            return;
        }
        if (c == '!') {
            String content = "!";
            LexType type;
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '=') {
                content += "=";
                type = LexType.NEQ;
                token = new Token(type, content, lineno, null);
                pos += 2;
            } else {
                type = LexType.NOT;
                token = new Token(type, content, lineno, null);
                pos++;
            }
            return;
        }
        if (c == '<') {
            String content = "<";
            LexType type;
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '=') {
                content += "=";
                type = LexType.LEQ;
                token = new Token(type, content, lineno, null);
                pos += 2;
            } else {
                type = LexType.LSS;
                token = new Token(type, content, lineno, null);
                pos++;
            }
            return;
        }
        if (c == '>') {
            String content = ">";
            LexType type;
            if (pos + 1 < source.length() && source.charAt(pos + 1) == '=') {
                content += "=";
                type = LexType.GEQ;
                token = new Token(type, content, lineno, null);
                pos += 2;
            } else {
                type = LexType.GRE;
                token = new Token(type, content, lineno, null);
                pos++;
            }
            return;
        }
        pos++;
        next();
    }

    public Token preRead() {
        Token t = token;
        int p = pos;
        int l = lineno;
        next();
        Token ans = token;
        token = t;
        pos = p;
        lineno = l;
        return ans;
    }

    public Token prePreRead() {
        Token t = token;
        int p = pos;
        int l = lineno;
        next();
        next();
        Token ans = token;
        token = t;
        pos = p;
        lineno = l;
        return ans;
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

    public Token getToken() {
        return token;
    }

    public int getPos() {
        return pos;
    }

    public int getLineno() {
        return lineno;
    }

    public void reset(Token token, int pos, int lineno) {
        this.token = token;
        this.pos = pos;
        this.lineno = lineno;
    }
}
