package frontend;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Lexer {
    private final String fileText; // 读入的文件内容
    private char Char; // 当前读入的字符
    private char LastChar; // 上一个读入的字符
    private Token token; // 当前读入的单词
    private int curPos; // 当前读入的字符的位置
    private TokenType symbol; // 当前读入的单词的类型
    private int lineNum = 1; // 当前读入的行数
    HashMap<String, TokenType> reserves; // 保留字表
    // HashMap<Integer, ArrayList<ErrorType>> errorList; // 错误列表
    TreeMap<Integer, ArrayList<ErrorType>> errorList;
    ArrayList<Token> tokens; // 词法分析结果

    public Lexer(String fileText) {
        this.fileText = fileText;
        this.reserves = new HashMap<>() {{
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
        this.errorList = new TreeMap<>();
        this.tokens = new ArrayList<>();
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public boolean hasToken() {
        return curPos < fileText.length();
    }

    public void lexicalAnalysis() {
        ArrayList<Map.Entry<TokenType, String>> results = new ArrayList<>();
        boolean right = true;
        while(hasToken()) {
            int code = getsym();
            if (code == 0) {
                continue;
            }
            if (code == -1) {
                this.addError(lineNum, ErrorType.a);
                right = false;
            } else {
                results.add(Map.entry(symbol, token.getValue()));
            }
            token.setType(symbol);
            token.setLineNum(lineNum);
            tokens.add(token);
        }
        /*if (right) {
            try (BufferedWriter out = new BufferedWriter(new FileWriter("lexer.txt"))) {
                for (Map.Entry<TokenType, String> entry : results) {
                    out.write(entry.getKey().toString() + " " + entry.getValue());
                    out.newLine();
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } else {
            try (BufferedWriter err = new BufferedWriter(new FileWriter("error.txt"))) {
                for (Map.Entry<Integer, ArrayList<ErrorType>> entry : errorList.entrySet()) {
                    err.write(entry.getKey().toString() + " a");
                    err.newLine();
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }*/
    }

    public void errorOutput() {
        try (BufferedWriter err = new BufferedWriter(new FileWriter("error.txt"))) {
            for (Map.Entry<Integer, ArrayList<ErrorType>> entry : errorList.entrySet()) {
                for (ErrorType errorType : entry.getValue()) {
                    err.write(entry.getKey().toString() + " " + errorType.toString());
                    err.newLine();
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void addError(int lineNum, ErrorType errorType) {
        if (errorList.containsKey(lineNum)) {
            errorList.get(lineNum).add(errorType);
        } else {
            ArrayList<ErrorType> errorTypes = new ArrayList<>();
            errorTypes.add(errorType);
            errorList.put(lineNum, errorTypes);
        }
    }

    private int getsym() {
        cleanToken();
        getChar();
        while (this.Char == ' ' || this.Char == '\n' || this.Char == '\t') {
            if (this.Char == '\n') {
                lineNum++;
            }
            getChar();
        }
        if (this.Char == '\0') {
            return 0;
        }
        catToken();
        if (isLetter(this.Char) || this.Char == '_') {
            getChar();
            while (isLetter(this.Char) || isDigit(this.Char) || this.Char == '_') {
                catToken();
                getChar();
            }
            retract();
            if (isReserve() == 0) {
                // 标识符
                symbol = TokenType.IDENFR;
            } else {
                symbol = reserves.get(this.token.getValue());
            }
        } else if (isDigit(this.Char)) {
            getChar();
            while (isDigit(this.Char)) {
                catToken();
                getChar();
            }
            retract();
            symbol = TokenType.INTCON;
        } else if (this.Char == '\"') {
            // 是双引号
            getChar();
            while (this.Char != '\"') {
                catToken();
                getChar();
            }
            catToken();
            symbol = TokenType.STRCON;
        } else if (this.Char == '!') {
            getChar();
            if (this.Char == '=') {
                catToken();
                symbol = TokenType.NEQ;
            } else {
                retract();
                symbol = TokenType.NOT;
            }
        } else if (this.Char == '&') {
            getChar();
            if (this.Char == '&') {
                catToken();
                symbol = TokenType.AND;
            } else {
                retract();
                catToken('&');
                symbol = TokenType.AND;
                return -1;
            }
        } else if (this.Char == '|') {
            getChar();
            if (this.Char == '|') {
                catToken();
                symbol = TokenType.OR;
            } else {
                retract();
                catToken('|');
                symbol = TokenType.OR;
                return -1;
            }
        } else if (this.Char == '+') symbol = TokenType.PLUS;
        else if (this.Char == '-') symbol = TokenType.MINU;
        else if (this.Char == '*') symbol = TokenType.MULT;
        else if (this.Char == '%') symbol = TokenType.MOD;
        else if (this.Char == '<') {
            getChar();
            if (this.Char == '=') {
                catToken();
                symbol = TokenType.LEQ;
            } else {
                retract();
                symbol = TokenType.LSS;
            }
        } else if (this.Char == '>') {
            getChar();
            if (this.Char == '=') {
                catToken();
                symbol = TokenType.GEQ;
            } else {
                retract();
                symbol = TokenType.GRE;
            }
        } else if (this.Char == '=') {
            getChar();
            if (this.Char == '=') {
                catToken();
                symbol = TokenType.EQL;
            } else {
                retract();
                symbol = TokenType.ASSIGN;
            }
        } else if (this.Char == ';') symbol = TokenType.SEMICN;
        else if (this.Char == ',') symbol = TokenType.COMMA;
        else if (this.Char == '(') symbol = TokenType.LPARENT;
        else if (this.Char == ')') symbol = TokenType.RPARENT;
        else if (this.Char == '[') symbol = TokenType.LBRACK;
        else if (this.Char == ']') symbol = TokenType.RBRACK;
        else if (this.Char == '{') symbol = TokenType.LBRACE;
        else if (this.Char == '}') symbol = TokenType.RBRACE;
        else if (this.Char == '/') {
            getChar();
            if (this.Char == '/') {
                getChar();
                while (this.Char != '\n') {
                    getChar();
                    if (this.Char == '\0') {
                        break;
                    }
                }
                lineNum++;
                return 0;
            } else if (this.Char == '*') {
                getChar();
                while (curPos < fileText.length()) {
                    while (this.Char != '*') {
                        if (this.Char == '\n') lineNum++;
                        getChar();
                    }
                    while (this.Char == '*') {
                        getChar();
                    }
                    if (this.Char == '/') {
                        return 0;
                    }
                }
                return 0;
            } else {
                retract();
                symbol = TokenType.DIV;
            }
        } else if (this.Char == '\'') {
            getChar();
            if (this.Char == '\\') {
                catToken();
                getChar();
                catToken();
            } else {
                catToken();
            }
            getChar();
            if (this.Char == '\'') {
                catToken();
                symbol = TokenType.CHRCON;
            } else {
                retract();
                return -1;
            }
        } else {
            return 0;
        }
        return 1;
    }

    private void getChar() {
        if (curPos < fileText.length()) {
            this.LastChar = this.Char;
            this.Char = fileText.charAt(curPos);
            this.curPos++;
        } else {
            this.Char = '\0';
        }
    }

    private void cleanToken() {
        this.token = new Token();
    }

    private boolean isLetter(char c) {
        return Character.isLetter(c);
    }

    private boolean isDigit(char c) {
        return Character.isDigit(c);
    }

    private void catToken() {
        this.token.addChar(this.Char);
    }

    private void catToken(char c) {
        this.token.addChar(c);
    }

    private void retract() {
        this.curPos--;
        this.Char = this.LastChar;
    }

    private int isReserve() {
        if (this.reserves.containsKey(this.token.getValue())) {
            return this.reserves.get(this.token.getValue()).ordinal();
        } else {
            return 0;
        }
    }
}
