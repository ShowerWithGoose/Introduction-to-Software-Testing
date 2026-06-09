package frontend;

import error.Error_A;

import java.io.IOException;
import java.io.PushbackInputStream;
import java.util.ArrayList;

public class Lexer {
    PushbackInputStream input;
//    private final ArrayList<String> input;
    private int pos = 0;
    private Token curToken;
    private int lineNum = 1;
    private FileOutput fileOutput;

    public Lexer(PushbackInputStream input, FileOutput fileOutput) {
        this.input = input;
        this.fileOutput = fileOutput;
    }

    public boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    public boolean isLetter(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    public void next() throws Error_A, IOException {
        if (isEnd()) {
            return;
        }
        char c = read();
        StringBuilder sb = new StringBuilder();
        LexType lexType = null;
        if (isLetter(c) || c == '_') {
            while(!isEnd() && (isLetter(c) || isDigit(c) || c == '_')) {
                sb.append(c);
                c = read();
            }
            unread(c);
            lexType = LexType.IDENFR;
            lexType = lexType.find(sb.toString());
        } else if (isDigit(c)) {
            while(!isEnd() && isDigit(c)) {
                sb.append(c);
                c = read();
            }
            unread(c);
            lexType = LexType.INTCON;
        } else if (c == '/') {
            c = read();
            if (c == '/') {
                while(!isEnd() && c != '\n') {
                    c = read();
                }
                next();
                return;
            } else if (c == '*') {
                char lastchar = c;
                while(!isEnd()) {
                    c = read();
                    if (lastchar == '*' && c == '/') {
                        break;
                    }
                    lastchar = c;
                }
                next();
                return;
            } else {
                lexType = LexType.DIV;
                unread(c);
                sb.append('/');
            }
        } else if (c == '\"') {
            sb.append(c);
            c = read();
            char lastchar = c;
            while(!isEnd()) {
                sb.append(c);
                c = read();
                if (c == '\"' && lastchar != '\\') {
                    break;
                }
                lastchar = c;
            }
            sb.append(c);
            lexType = LexType.STRCON;
        } else if (c == '\'') {
            sb.append(c);
            c = read();
            if (c == '\\') {
                sb.append(c);
                c = read();
            }
            sb.append(c);
            c = read();
            sb.append(c);
            lexType = LexType.CHRCON;
        } else if (c == '!') {
            sb.append(c);
            c = read();
            if (c == '=') {
                sb.append(c);
                lexType = LexType.NEQ;
            } else {
                lexType = LexType.NOT;
                unread(c);
            }
        } else if (c == '&') {
            sb.append(c);
            c = read();
            if (c == '&') {
                sb.append(c);
                lexType = LexType.AND;
            } else {
                unread(c);
                throw new Error_A("&",fileOutput,lineNum);
            }
        } else if (c == '|') {
            sb.append(c);
            c = read();
            if (c == '|') {
                sb.append(c);
                lexType = LexType.OR;
            } else {
                unread(c);
                throw new Error_A("|",fileOutput,lineNum);
            }
        } else if (c == '+') {
            sb.append(c);
            lexType = LexType.PLUS;
        } else if (c == '-') {
            sb.append(c);
            lexType = LexType.MINU;
        } else if (c == '*') {
            sb.append(c);
            lexType = LexType.MULT;
        } else if (c == '%') {
            sb.append(c);
            lexType = LexType.MOD;
        } else if (c == '=') {
            sb.append(c);
            c = read();
            if (c == '=') {
                sb.append(c);
                lexType = LexType.EQL;
            } else {
                unread(c);
                lexType = LexType.ASSIGN;
            }
        } else if (c == '>') {
            sb.append(c);
            c = read();
            if (c == '=') {
                sb.append(c);
                lexType = LexType.GEQ;
            } else {
                unread(c);
                lexType = LexType.GRE;
            }
        } else if (c == '<') {
            sb.append(c);
            c = read();
            if (c == '=') {
                sb.append(c);
                lexType = LexType.LEQ;
            } else {
                unread(c);
                lexType = LexType.LSS;
            }
        } else if (c == ';') {
            lexType = LexType.SEMICN;
            sb.append(c);
        } else if (c == ',') {
            lexType = LexType.COMMA;
            sb.append(c);
        } else if (c == '(') {
            lexType = LexType.LPARENT;
            sb.append(c);
        } else if (c == ')') {
            lexType = LexType.RPARENT;
            sb.append(c);
        } else if (c == '[') {
            lexType = LexType.LBRACK;
            sb.append(c);
        } else if (c == ']') {
            lexType = LexType.RBRACK;
            sb.append(c);
        } else if (c == '{') {
            lexType = LexType.LBRACE;
            sb.append(c);
        } else if (c == '}') {
            lexType = LexType.RBRACE;
            sb.append(c);
        } else if (c == '\n') {
            lineNum++;
            next();
            return;
        } else if (c == ' ' || c == '\t' || c == '\r') {
            next();
            return;
        }
        curToken = new Token(sb.toString(),lexType,lineNum);
    }

    public Token peek() {
        return curToken;
    }

/*    public char read() {
        while (input.get(lineNum - 1).isEmpty() && lineNum < input.size()) {
            lineNum ++;
        }
        if (lineNum - 1 >= input.size()){
            lineNum ++;
            return ' ';
        } else if (pos < input.get(lineNum - 1).length()) {
            return input.get(lineNum - 1).charAt(pos++);
        } else if (lineNum == input.size() && pos == input.get(lineNum - 1).length()) {
            return ' ';
        } else {
            pos = 1;
            lineNum += 1;
            while (input.get(lineNum - 1).isEmpty() && lineNum < input.size()) {
                lineNum ++;
            }
            if (lineNum > input.size()) {
                return ' ';
            } else {
                return input.get(lineNum - 1).charAt(0);
            }
        }

    }

    public char last() {
        if (pos > 0) {
            return input.get(lineNum - 1).charAt(pos - 1);
        }
        return input.get(lineNum - 2).charAt(input.get(lineNum - 2).length() - 1);
    }

    public void back() {
        if (pos > 0) {
            pos --;
        } else if (lineNum > 1) {
            lineNum--;
            pos = input.get(lineNum - 1).length();
        }
    }*/

    public boolean isEnd() {
/*        if (lineNum == input.size() && pos == input.get(input.size() - 1).length()) {
            return true;
        } else {
            return false;
        }*/
        try {
            return input.available() == 0;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }

    private char read() throws IOException {
        return (char)input.read();
        //System.out.print(nchar);
    }
    private void unread(char c) throws IOException {
        input.unread(c);
    }
}
