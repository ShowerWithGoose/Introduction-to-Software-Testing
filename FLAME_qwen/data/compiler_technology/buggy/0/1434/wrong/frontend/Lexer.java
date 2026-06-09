package frontend;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

public class Lexer {
    private final ArrayList<Token> tokenList = new ArrayList<>();
    private final BufferedInputStream in = new BufferedInputStream(new FileInputStream("testfile.txt"));
    private int lineno = 1;
    private int ch;
    private TokenType type;
    private String content;
    public Lexer() throws FileNotFoundException {

    }
    public void getTokenList() throws IOException {
        while ((ch = in.read()) != -1) {
            content = null;
            if (ch == '\n') {
                lineno++;
                continue;
            } else if (ch == ' ' || ch == '\t' || ch == '\r') {
                continue;
            } else if (ch == 'i') { // if int
                in.mark(0);
                if (!getInt() && !getIf()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == 'm') { // main
                in.mark(0);
                if (!getMain()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == 'c') { // const char continue
                in.mark(0);
                if (!getChar() && !getConst() && !getContinue()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == 'b') { // break
                in.mark(0);
                if (!getBreak()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == 'e') { // else
                in.mark(0);
                if (!getElse()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == '!') { // ! !=
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
            } else if (ch == 'f') { // for
                in.mark(0);
                if (!getFor()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == 'g') { // getint getchar
                in.mark(0);
                if (!getGetchar() && !getGetint()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == 'p') { // printf
                in.mark(0);
                if (!getPrintf()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == 'r') { // return
                in.mark(0);
                if (!getReturn()) {
                    in.reset();
                    getIdent();
                }
            } else if (ch == 'v') { // void
                in.mark(0);
                if (!getVoid()) {
                    in.reset();
                    getIdent();
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
                content = String.valueOf((char)in.read());
                if (in.read() != '\'') {
                    OutputInfo.error("charConst error\n");
                }
            } else if (ch >= '0' && ch <= '9') { // IntConst
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

    public boolean getInt() throws IOException {
        in.mark(0);
        if (in.available() >= 2 && in.read() == 'n' && in.read() == 't') {
            type = TokenType.INTTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getChar() throws IOException {
        in.mark(0);
        if (in.available() >= 3 && in.read() == 'h' && in.read() == 'a' && in.read() == 'r') {
            type = TokenType.CHARTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getIf() throws IOException {
        in.mark(0);
        if (in.available() >= 1 && in.read() == 'f') {
            type = TokenType.IFTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getMain() throws IOException {
        in.mark(0);
        if (in.available() >= 3 && in.read() == 'a' && in.read() == 'i' && in.read() == 'n') {
            type = TokenType.MAINTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getVoid() throws IOException {
        in.mark(0);
        if (in.available() >= 3 && in.read() == 'o' && in.read() == 'i' && in.read() == 'd') {
            type = TokenType.VOIDTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getElse() throws IOException {
        in.mark(0);
        if (in.available() >= 3 && in.read() == 'l' && in.read() == 's' && in.read() == 'e') {
            type = TokenType.ELSETK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getFor() throws IOException {
        in.mark(0);
        if (in.available() >= 2 && in.read() == 'o' && in.read() == 'r') {
            type = TokenType.FORTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getBreak() throws IOException {
        in.mark(0);
        if (in.available() >= 4 && in.read() == 'r' && in.read() == 'e' && in.read() == 'a' && in.read() == 'k') {
            type = TokenType.BREAKTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getPrintf() throws IOException {
        in.mark(0);
        if (in.available() >= 5 && in.read() == 'r' && in.read() == 'i' && in.read() == 'n' && in.read() == 't' && in.read() == 'f') {
            type = TokenType.PRINTFTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getReturn() throws IOException {
        in.mark(0);
        if (in.available() >= 5 && in.read() == 'e' && in.read() == 't' && in.read() == 'u' && in.read() == 'r' && in.read() == 'n') {
            type = TokenType.RETURNTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getGetint() throws IOException {
        in.mark(0);
        if (in.available() >= 5 && in.read() == 'e' && in.read() == 't' && in.read() == 'i' && in.read() == 'n' && in.read() == 't') {
            type = TokenType.GETINTTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getGetchar() throws IOException {
        in.mark(0);
        if (in.available() >= 6 && in.read() == 'e' && in.read() == 't' && in.read() == 'c' && in.read() == 'h' && in.read() == 'a' && in.read() == 'r') {
            type = TokenType.GETCHARTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getConst() throws IOException {
        in.mark(0);
        if (in.available() >= 4 && in.read() == 'o' && in.read() == 'n' && in.read() == 's' && in.read() == 't') {
            type = TokenType.CONSTTK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean getContinue() throws IOException {
        in.mark(0);
        if (in.available() >= 7 && in.read() == 'o' && in.read() == 'n' && in.read() == 't' && in.read() == 'i' && in.read() == 'n' && in.read() == 'u' && in.read() == 'e') {
            type = TokenType.CONTINUETK;
            return true;
        }
        in.reset();
        return false;
    }

    public boolean isBlank(Integer c) {
        return (c == ' ' || c == '\n' || c == '\t' || c == '\r');
    }

    public boolean getIdent() throws IOException {
        type = TokenType.IDENFR;
        String s = new String();
        while (isIdent(ch)) {
            s += (char)ch;
            in.mark(0);
            ch = in.read();
        }
        in.reset();
        content = s;
        return false;
    }

    public boolean isIdent(int ch) {
        return (ch == '_' || (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }

}

