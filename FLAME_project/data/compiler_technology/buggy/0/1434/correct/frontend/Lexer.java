package frontend;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Lexer {
    private final ArrayList<Token> tokenList = new ArrayList<>();
    private final BufferedInputStream in = new BufferedInputStream(new FileInputStream("testfile.txt"));
    private int lineno = 1;
    private int ch;
    private TokenType type;
    private String content;
    private Map<String, TokenType> reservedList = new HashMap<String, TokenType>() {{
        put("main", TokenType.MAINTK);
        put("const", TokenType.CONSTTK);
        put("int", TokenType.INTTK);
        put("char", TokenType.CHARTK);
        put("break", TokenType.BREAKTK);
        put("continue", TokenType.CONTINUETK);
        put("if", TokenType.IFTK);
        put("else", TokenType.ELSETK);
        put("for", TokenType.FORTK);
        put("getint", TokenType.GETINTTK);
        put("getchar", TokenType.GETCHARTK);
        put("printf", TokenType.PRINTFTK);
        put("return", TokenType.RETURNTK);
        put("void", TokenType.VOIDTK);
    }};
    public Lexer() throws FileNotFoundException {
    }
    public void getTokenList() throws IOException {
        while ((ch = in.read()) != -1) {
            content = null;
            if (ch == '\n') {
                lineno++;
                continue;
            } else if (isBlank(ch)) {
                continue;
            }  else if (ch == '!') { // ! !=
                in.mark(0);
                if (in.available() >= 1 && in.read() == '=') {
                    type = TokenType.NEQ;
                } else {
                    in.reset();
                    type = TokenType.NOT;
                }
            } else if (ch == '&') { // &&
                if (in.available() >= 1 && in.read() == '&') {
                    type = TokenType.AND;
                } else {
                    OutputInfo.error(lineno + " a");
                    continue;
                }
            } else if (ch == '|') { // ||
                if (in.available() >= 1 && in.read() == '|') {
                    type = TokenType.OR;
                } else {
                    OutputInfo.error(lineno + " a");
                    continue;
                }
            } else if (ch == '+') {
                type = TokenType.PLUS;
            } else if (ch == '-') {
                type = TokenType.MINU;
            } else if (ch == '*') {
                type = TokenType.MULT;
            } else if (ch == '/') { // / // /*
                in.mark(0);
                ch = in.read();
                if (ch == '/') {
                    while ((ch = in.read()) != -1 && ch != '\n');
                    if (ch == '\n') lineno++;
                    continue;
                } else if (ch == '*') {
                    do {
                        while ((ch = in.read()) != -1 && ch != '*');
                    } while (in.read() != '/');
                    continue;
                } else {
                    in.reset();
                    type = TokenType.DIV;
                }
            } else if (ch == '%') {
                type = TokenType.MOD;
            } else if (ch == '<') { // < <=
                in.mark(0);
                if (in.read() == '=') {
                    type = TokenType.LEQ;
                } else {
                    in.reset();
                    type = TokenType.LSS;
                }
            } else if (ch == '>') { // > >=
                in.mark(0);
                if (in.read() == '=') {
                    type = TokenType.GEQ;
                } else {
                    in.reset();
                    type = TokenType.GRE;
                }
            } else if (ch == '=') { // = ==
                in.mark(0);
                if (in.read() == '=') {
                    type = TokenType.EQL;
                } else {
                    in.reset();
                    type = TokenType.ASSIGN;
                }
            } else if (ch == ';') {
                type = TokenType.SEMICN;
            } else if (ch == ',') {
                type = TokenType.COMMA;
            } else if (ch == '(') {
                type = TokenType.LPARENT;
            } else if (ch == ')') {
                type = TokenType.RPARENT;
            } else if (ch == '[') {
                type = TokenType.LBRACK;
            } else if (ch == ']') {
                type = TokenType.RBRACK;
            } else if (ch == '{') {
                type = TokenType.LBRACE;
            } else if (ch == '}') {
                type = TokenType.RBRACE;
            } else if (ch == '"') { // StringConst
                type = TokenType.STRCON;
                String s = new String();
                s += (char) ch;
                ch = in.read();
                while (ch != '"') {
                    s += (char) ch;
                    ch = in.read();
                }
                s += (char) ch;
                content = s;
            } else if (ch == '\'') { // CharConst
                type = TokenType.CHRCON;
                content = "\'" + (char)in.read();
                ch = in.read();
                if (ch != '\'') {
                    content += (char)ch;
                    in.read();
                } else {
                    in.mark(1);
                    if (in.read() == '\'') {
                        content += '\'';
                    } else {
                        in.reset();
                    }
                }
                content += "\'";
            } else if (isDigit(ch)) { // IntConst
                type = TokenType.INTCON;
                String s = new String();
                while (ch >= '0' && ch <= '9') {
                    s += (char) ch;
                    in.mark(0);
                    ch = in.read();
                }
                in.reset(); // return the first non_digit character
                content = s;
            } else { // Ident
                getIdent();
            }
            if (content == null) {
                content = type.toString();
            }
            tokenList.add(new Token(type, content, lineno));
            OutputInfo.print(type.name() + " " + content);
        }
        in.close();
    }

    public boolean isBlank(Integer c) {
        return (c == ' ' || c == '\t' || c == '\r');
    }

    public boolean getIdent() throws IOException {
        String s = new String();
        while (isIdent(ch)) {
            s += (char)ch;
            in.mark(0);
            ch = in.read();
        }
        in.reset();
        content = s;
        type = reservedList.getOrDefault(s, TokenType.IDENFR);
        return false;
    }


    public boolean isIdent(int ch) {
        return (ch == '_' || (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }

    public boolean isDigit(int ch) {
        return (ch >= '0' && ch <= '9');
    }

}

