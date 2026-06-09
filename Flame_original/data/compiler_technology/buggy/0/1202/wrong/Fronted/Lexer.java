package Fronted;

import Fronted.ErrorLog;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;

public class Lexer {
    public InputStream inputStream;
    public ArrayList<String> lines;
    public int lineNum;
    public int charNum;
    public ArrayList<Token> tokens;
    public ArrayList<ErrorLog> errorLogs;

    public Lexer(InputStream inputStream) {
        this.inputStream = inputStream;
        this.lineNum = 0;
        this.charNum = 0;
        this.lines = new ArrayList<>();
        this.tokens = new ArrayList<>();
        this.errorLogs = new ArrayList<>();
        divideLines();
        run();
    }

    private void divideLines() {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public boolean isLineEnd() {
        if (isEnd()) {
            return true;
        } else if (charNum >= lines.get(lineNum).length()) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isEnd() {
        if (lineNum >= lines.size()) {
            return true;
        } else {
            return false;
        }
    }

    public String getLine() {
        if (!isEnd()) {
            return lines.get(lineNum);
        } else {
            return "";
        }
    }

    public char getChar() {
        if (!isLineEnd()) {
            return getLine().charAt(charNum);
        } else {
            return '\n';
        }
    }

    public String getComment() {
        StringBuilder sb = new StringBuilder();
        sb.append(getChar());
        if (charNum + 1 >= getLine().length()) {
            return sb.toString();
        } else {
            next();
            sb.append(getChar());
            back();
            return sb.toString();
        }
    }

    public void next() {
        if (charNum + 1 >= getLine().length()) {
            lineNum++;
            charNum = 0;
        } else {
            charNum++;
        }
    }

    public void back() {
        if (charNum > 0) {
            charNum--;
        }
    }

    private void run() {
        while (!isEnd()) {
            skipSpace();
            if (skipComment()) {
                continue;
            }
            getToken();
        }
    }

    private void skipSpace() {
        if (Character.isWhitespace(getChar())) {
            next();
            while (Character.isWhitespace(getChar())) {
                next();
            }
        }
    }

    private boolean skipComment() {
        if (getChar() == '/') {
            if (charNum + 1 >= getLine().length()) {
                return false;
            } else if (getLine().charAt(charNum + 1) == '/') {
                lineNum++;
                charNum = 0;
                return true;
            } else if (getLine().charAt(charNum + 1) == '*') {
                next();
                while (true) {
                    next();
                    if (getChar() == '*') {
                        if (charNum + 1 < getLine().length() && getLine().charAt(charNum + 1) == '/') {
                            next();
                            next();
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }


    private void getToken() {
        String s = new String();
        if (Character.isDigit(getChar())) { //1. INTCON
            s += getChar();
            while (charNum + 1 < getLine().length() && Character.isDigit(getLine().charAt(charNum + 1))) {
                // 下一个符号是数字
                next();
                s += getChar();
            }
            Token token = new Token(Token.TokenType.INTCON, lineNum + 1, s);
            tokens.add(token);
            next();
        } else if (getChar() == '\'') {  //2. CHRCON
            s += getChar();
            while (charNum + 1 < getLine().length()) {
                // 下一个符号是数字
                next();
                s += getChar();
                if (getChar() == '\'') {
                    if (getCommentCount() % 2 == 0) {
                        break;
                    }
                }
            }
            Token token = new Token(Token.TokenType.CHRCON, lineNum + 1, s);
            tokens.add(token);
            next();
        } else if (getChar() == '\"') {  //3. STRCON
            s += getChar();
            while (charNum + 1 < getLine().length()) {
                // 下一个符号是数字
                next();
                s += getChar();
                if (getChar() == '\"') {
                    if (getCommentCount() % 2 == 0) {
                        break;
                    }
                }
            }
            Token token = new Token(Token.TokenType.STRCON, lineNum + 1, s);
            tokens.add(token);
            next();
        } else if (Character.isLetter(getChar()) || getChar() == '_') {
            s += getChar();
            while (charNum + 1 < getLine().length() && (Character.isDigit(getLine().charAt(charNum + 1))
                    || Character.isLetter(getLine().charAt(charNum + 1)) || getLine().charAt(charNum + 1) == '_')) {
                // 下一个符号是数字
                next();
                s += getChar();
            }
            tokens.add(findStringToken(s));
            next();
        } else {
            s += getChar();
            if (getChar() == '+') {
                Token token = new Token(Token.TokenType.PLUS, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == '-') {
                Token token = new Token(Token.TokenType.MINU, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == '*') {
                Token token = new Token(Token.TokenType.MULT, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == '/') {
                Token token = new Token(Token.TokenType.DIV, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == '%') {
                Token token = new Token(Token.TokenType.MOD, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == ';') {
                Token token = new Token(Token.TokenType.SEMICN, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == ',') {
                Token token = new Token(Token.TokenType.COMMA, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == '(') {
                Token token = new Token(Token.TokenType.LPARENT, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == ')') {
                Token token = new Token(Token.TokenType.RPARENT, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == '[') {
                Token token = new Token(Token.TokenType.LBRACK, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == ']') {
                Token token = new Token(Token.TokenType.RBRACK, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == '{') {
                Token token = new Token(Token.TokenType.LBRACE, lineNum + 1, s);
                tokens.add(token);
                next();
            } else if (getChar() == '}') {
                Token token = new Token(Token.TokenType.RBRACE, lineNum + 1, s);
                tokens.add(token);
                next();
            } else {
                Token tk = findSymToken(s);
                if (tk != null) {
                    tokens.add(tk);
                }
                next();
            }
        }
    }

    private Token findStringToken(String string) {
        Token.TokenType type = null;
        if (string.equals("main")) {  // 4-18
            type = Token.TokenType.MAINTK;
        } else if (string.equals("const")) {
            type = Token.TokenType.CONSTTK;
        } else if (string.equals("int")) {
            type = Token.TokenType.INTTK;
        } else if (string.equals("char")) {
            type = Token.TokenType.CHARTK;
        } else if (string.equals("break")) {
            type = Token.TokenType.BREAKTK;
        } else if (string.equals("continue")) {
            type = Token.TokenType.CONTINUETK;
        } else if (string.equals("if")) {
            type = Token.TokenType.IFTK;
        } else if (string.equals("else")) {
            type = Token.TokenType.ELSETK;
        } else if (string.equals("for")) {
            type = Token.TokenType.FORTK;
        } else if (string.equals("getint")) {
            type = Token.TokenType.GETINTTK;
        } else if (string.equals("getchar")) {
            type = Token.TokenType.GETCHARTK;
        } else if (string.equals("printf")) {
            type = Token.TokenType.PRINTFTK;
        } else if (string.equals("return")) {
            type = Token.TokenType.RETURNTK;
        } else if (string.equals("void")) {
            type = Token.TokenType.VOIDTK;
        } else {
            type = Token.TokenType.IDENFR;
        }
        Token token = new Token(type, lineNum + 1, string);
        return token;
    }

    public Token findSymToken(String string) {
        if (getChar() == '=') {
            if (charNum + 1 >= getLine().length() || getLine().charAt(charNum + 1) != '=') {
                Token token = new Token(Token.TokenType.ASSIGN, lineNum + 1, string);
                return token;
            } else {
                next();
                string += getChar();
                Token token = new Token(Token.TokenType.EQL, lineNum + 1, string);
                return token;
            }
        } else if (getChar() == '!') {
            if (charNum + 1 >= getLine().length() || getLine().charAt(charNum + 1) != '=') {
                Token token = new Token(Token.TokenType.NOT, lineNum + 1, string);
                return token;
            } else {
                next();
                string += getChar();
                Token token = new Token(Token.TokenType.NEQ, lineNum + 1, string);
                return token;
            }
        } else if (getChar() == '<') {
            if (charNum + 1 >= getLine().length() || getLine().charAt(charNum + 1) != '=') {
                Token token = new Token(Token.TokenType.LSS, lineNum + 1, string);
                return token;
            } else {
                next();
                string += getChar();
                Token token = new Token(Token.TokenType.LEQ, lineNum + 1, string);
                return token;
            }
        } else if (getChar() == '>') {
            if (charNum + 1 >= getLine().length() || getLine().charAt(charNum + 1) != '=') {
                Token token = new Token(Token.TokenType.GRE, lineNum + 1, string);
                return token;
            } else {
                next();
                string += getChar();
                Token token = new Token(Token.TokenType.GEQ, lineNum + 1, string);
                return token;
            }
        } else if (getChar() == '&') {
            if (charNum + 1 >= getLine().length() || getLine().charAt(charNum + 1) != '&') {
                ErrorLog errorLog = new ErrorLog(lineNum + 1, 'a');
                errorLogs.add(errorLog);
                Token token = new Token(Token.TokenType.AND, lineNum + 1, string);
                return token;
            } else {
                next();
                string += getChar();
                Token token = new Token(Token.TokenType.AND, lineNum + 1, string);
                return token;
            }
        } else if (getChar() == '|') {
            if (charNum + 1 >= getLine().length() || getLine().charAt(charNum + 1) != '|') {
                ErrorLog errorLog = new ErrorLog(lineNum + 1, 'a');
                errorLogs.add(errorLog);
                Token token = new Token(Token.TokenType.OR, lineNum + 1, string);
                return token;
            } else {
                next();
                string += getChar();
                Token token = new Token(Token.TokenType.OR, lineNum + 1, string);
                return token;
            }
        } else {
            return null;
        }

    }

    public String getOutput() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token.getType() + " " + token.getContent() + "\n");
        }
        return sb.toString();
    }

    public String getErrorOutput() {
        StringBuilder sb = new StringBuilder();
        for (ErrorLog errorLog : errorLogs) {
            sb.append(errorLog.getLineNum() + " " + errorLog.getType() + "\n");
        }
        return sb.toString();
    }

    public int getCommentCount() {
        int i = charNum - 1;
        int sum = 0;
        if (getLine().charAt(i) == '\\') {
            sum++;
            i--;
            while (i >= 0 && getLine().charAt(i) == '\\') {
                sum++;
                i--;
            }
            return sum;
        } else {
            return 0;
        }
    }
}