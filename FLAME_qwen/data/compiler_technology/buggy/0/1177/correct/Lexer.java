import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Lexer {
    private String source;
    private int curPos;
    private int lineNum;
    private ArrayList<Message> tokens;
    private String token;
    private boolean flag;

    public Lexer(String source) {
        this.source = source;
        this.curPos = 0;
        this.lineNum = 1;
        this.flag = false;
        this.tokens = new ArrayList<>();
    }

    public boolean isNonDigit(char c) {
        if ((c >='a' && c <= 'z') || (c >='A' && c <= 'Z') || c == '_') {
            return true;
        }
        return false;
    }

    public boolean analyze() {
        while (curPos < source.length()) {
            token = "";
            next();
            if (flag == true) {
                return false;
            }
        }
        return true;
    }

    public void next() {
        char c = source.charAt(curPos++);
        //读到字母或下划线
        if (isNonDigit(c)) {
            token += c;
            while (curPos < source.length() && (isNonDigit(source.charAt(curPos))
                    || Character.isDigit(source.charAt(curPos)))) {
                c = source.charAt(curPos++);
                token += c;
            }
            Message m = checkType(token, lineNum);
            tokens.add(m);
        } //数字
        else if (Character.isDigit(c)) {  //TODO
            token += c;
            while (curPos < source.length() &&
                    Character.isDigit(source.charAt(curPos))) {
                c = source.charAt(curPos++);
                token += c;
            }
            tokens.add(new Message(Type.INTCON, token, lineNum));
        } //字符串读取
        else if (c == '\"') {
            token += c;
            while (curPos < source.length()) {
                c = source.charAt(curPos++);
                token += c;
                if (c == '\"') break;
            }
            tokens.add(new Message(Type.STRCON, token, lineNum));
        } //字符读取
        else if (c == '\'') {  //TODO
            token += c;
            while (curPos < source.length()) {
                c = source.charAt(curPos++);
                token += c;
                if (c == '\'') break;
            }
            tokens.add(new Message(Type.CHRCON, token, lineNum));
        }

        //单个字符
        else if (c == '+') {
            tokens.add(new Message(Type.PLUS, "+", lineNum));
        } else if (c == '-') {
            tokens.add(new Message(Type.MINU, "-", lineNum));
        } else if (c == '*') {
            tokens.add(new Message(Type.MULT, "*", lineNum));
        } else if (c == '%') {
            tokens.add(new Message(Type.MOD, "%", lineNum));
        } else if (c == ';') {
            tokens.add(new Message(Type.SEMICN, ";", lineNum));
        } else if (c == ',') {
            tokens.add(new Message(Type.COMMA, ",", lineNum));
        } else if (c == '(') {
            tokens.add(new Message(Type.LPARENT, "(", lineNum));
        } else if (c == ')') {
            tokens.add(new Message(Type.RPARENT, ")", lineNum));
        } else if (c == '[') {
            tokens.add(new Message(Type.LBRACK, "[", lineNum));
        } else if (c == ']') {
            tokens.add(new Message(Type.RBRACK, "]", lineNum));
        } else if (c == '{') {
            tokens.add(new Message(Type.LBRACE, "{", lineNum));
        } else if (c == '}') {
            tokens.add(new Message(Type.RBRACE, "}", lineNum));
        }

        //可单可双
        else if (c == '<') {
            if (curPos < source.length() && source.charAt(curPos) == '=') {
                tokens.add(new Message(Type.LEQ, "<=", lineNum));
                curPos++;   //TODO
            } else {
                tokens.add(new Message(Type.LSS, "<", lineNum));
            }
        } else if (c == '>') {
            if (curPos < source.length() && source.charAt(curPos) == '=') {
                tokens.add(new Message(Type.GEQ, ">=", lineNum));
                curPos++;   //TODO
            } else {
                tokens.add(new Message(Type.GRE, ">", lineNum));
            }
        } else if (c == '=') {
            if (curPos < source.length() && source.charAt(curPos) == '=') {
                tokens.add(new Message(Type.EQL, "==", lineNum));
                curPos++;   //TODO
            } else {
                tokens.add(new Message(Type.ASSIGN, "=", lineNum));
            }
        } else if (c == '!') {
            if (curPos < source.length() && source.charAt(curPos) == '=') {
                tokens.add(new Message(Type.NEQ, "!=", lineNum));
                curPos++;   //TODO
            } else {
                tokens.add(new Message(Type.NOT, "!", lineNum));
            }
        }

        //可单可错误
        else if (c == '&') {
            if (curPos < source.length() && source.charAt(curPos) == '&') {
                tokens.add(new Message(Type.AND, "&&", lineNum));
                curPos++;   //TODO
            } else {
                error(lineNum);
            }
        } else if (c == '|') {
            if (curPos < source.length() && source.charAt(curPos) == '|') {
                tokens.add(new Message(Type.OR, "||", lineNum));
                curPos++;   //TODO
            } else {
                error(lineNum);
            }
        }

        else if (c == '/') {
            //注释
            token += c;
            if (curPos < source.length() && source.charAt(curPos) == '/') {
                c = source.charAt(curPos++);
                token += c;
                while (curPos < source.length() && source.charAt(curPos) != '\n') {
                    c = source.charAt(curPos++);
                    token += c;
                }
                if (curPos < source.length()) {
                    c = source.charAt(curPos++);
                    token += c;
                    lineNum++;
                }
                //tokens.add(new Message(Type.NOTE, token, lineNum));
            } else if (curPos < source.length() && source.charAt(curPos) == '*') {
                c = source.charAt(curPos++);
               token += c;
                while (curPos < source.length()) {
                    while (curPos < source.length() && source.charAt(curPos) != '*') {
                        c = source.charAt(curPos++);
                        token += c;
                        if (c == '\n') lineNum++;
                    }
                    while (curPos < source.length() && source.charAt(curPos) == '*') {
                        c = source.charAt(curPos++);
                        token += c;
                    }
                    if (curPos < source.length() && source.charAt(curPos) == '/') {
                        c = source.charAt(curPos++);
                        token += c;
                        break;
                    }
                }
                //tokens.add(new Message(Type.NOTE, token, lineNum));
            } else {
                tokens.add(new Message(Type.DIV, "/", lineNum));
            }
        } else if (c == '\n') {
            lineNum++;
        }
    }

    public Message checkType(String s, int line) {
        Message m = new Message(Type.IDENFR, s, line);
        if (s.equals("main")) {
            m.setType(Type.MAINTK);
        } else if (s.equals("const")) {
            m.setType(Type.CONSTTK);
        } else if (s.equals("int")) {
            m.setType(Type.INTTK);
        } else if (s.equals("char")) {
            m.setType(Type.CHARTK);
        } else if (s.equals("break")) {
            m.setType(Type.BREAKTK);
        } else if (s.equals("continue")) {
            m.setType(Type.CONTINUETK);
        } else if (s.equals("if")) {
            m.setType(Type.IFTK);
        } else if (s.equals("else")) {
            m.setType(Type.ELSETK);
        } else if (s.equals("for")) {
            m.setType(Type.FORTK);
        } else if (s.equals("getint")) {
            m.setType(Type.GETINTTK);
        } else if (s.equals("getchar")) {
            m.setType(Type.GETCHARTK);
        } else if (s.equals("printf")) {
            m.setType(Type.PRINTFTK);
        } else if (s.equals("return")) {
            m.setType(Type.RETURNTK);
        } else if (s.equals("void")) {
            m.setType(Type.VOIDTK);
        }
        return m;
    }

    public void error(int line) {
        flag = true;
        String outputFilePath = "error.txt";
        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(outputFilePath)))) {
            writer.printf("%d a", line);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public ArrayList<Message> getTokens() {
        return tokens;
    }
}