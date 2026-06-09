package frontend;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private final InputStream inputStream;
    private int row_num;
    private int column_num;//用于记录出现错误的行列号
    private int lineNum;//用于记录当前行号
    private ErrorType errorType;
    private ArrayList<Pair> dictionary;
    private HashMap<Integer, String> context;

    public Lexer(InputStream inputStream) {
        this.errorType = null;
        this.inputStream = inputStream;
        this.dictionary = new ArrayList<>();
        this.context = new HashMap<>();
        this.row_num = 0;
        this.column_num = 0;
        this.lineNum = 0;
        readContext();
    }

    public void readContext() {
        try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(this.inputStream))) {
            String line;
            while ((line = bufferedReader.readLine())  != null) {
                this.lineNum++;
                this.context.put(this.lineNum, line);
                analyse(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void analyse(String line) { //将注释部分处理掉
        boolean notation_flag = false;
        if (line.contains("//")) {
            line = line.substring(0, line.indexOf("//"));
        }
        if (line.contains("/*")) {
            line = line.substring(0, line.indexOf("/*"));
            notation_flag = true;
        }
        if (notation_flag && line.contains("*/")) {
            line = line.substring(line.indexOf("*/") + 2);
            notation_flag = false;
        }
        if (notation_flag)
            return;
        int pos = 0;
        while (pos < line.length()) {
            pos += next(pos, line);
        }
    }

    public int next(int pos, String line) {
        StringBuilder token = new StringBuilder();
        if (line.charAt(pos) == ' ' || line.charAt(pos) == '\n' || line.charAt(pos) == '\t') {
            return 1;
        }
        else if (Character.isDigit(line.charAt(pos))) {
            token.append(line.charAt(pos++));
            while (pos < line.length() && Character.isDigit(line.charAt(pos))) {
                token.append(line.charAt(pos++));
            }
            this.dictionary.add(new Pair(LexType.INTCON, token.toString()));
        } else if (isNotDigit(line.charAt(pos))) {
            if (isKeySymbol(line.charAt(pos))) {
                parseKeySymbol(pos, line, token);
            } else if (line.charAt(pos) == '\"') {
                parseStringConst(pos, line, token);
            } else if (line.charAt(pos) == '\'') {
                parseCharConst(pos, line, token);
            } else {
                token.append(line.charAt(pos++));
                while (pos < line.length() && !isKeySymbol(line.charAt(pos)) &&
                        (isNotDigit(line.charAt(pos)) || Character.isDigit(line.charAt(pos)))) {
                    token.append(line.charAt(pos++));
                }
                parseKeyWord(token.toString());
            }
        }
        return token.length();
    }

    public boolean isNotDigit(char ch) {
        return (ch > 32 && ch <= 126) && !Character.isDigit(ch);
    }

    public boolean isKeySymbol(char ch) {
        return ch == '!' || ch == '&' || ch == '|' || ch == '+' || ch == '-' || ch == '*'
                || ch == '/' || ch == '%' || ch == '<' || ch == '>' || ch == '=' || ch == ';'
                || ch == ',' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}';
    }

    public void parseStringConst(int pos, String line, StringBuilder token) {
        token.append(line.charAt(pos++));
        while (pos < line.length() && line.charAt(pos) != '\"') {
            if (line.charAt(pos) == '\\') {
                token.append(line.charAt(pos++));
            }
            token.append(line.charAt(pos++));
        }
        token.append(line.charAt(pos));
        this.dictionary.add(new Pair(LexType.STRCON, token.toString()));
    }

    public void parseCharConst(int pos, String line, StringBuilder token) {
        token.append(line.charAt(pos++));
        while (pos < line.length() && line.charAt(pos) != '\'') {
            if (line.charAt(pos) == '\\') {
                token.append(line.charAt(pos++));
            }
            token.append(line.charAt(pos++));
        }
        token.append(line.charAt(pos));
        this.dictionary.add(new Pair(LexType.CHRCON, token.toString()));
    }

    public void parseKeySymbol(int pos, String line, StringBuilder token) {
        char ch = line.charAt(pos++);
        token.append(ch);
        if (ch == '!') {
            if (line.charAt(pos) == '=') {
                token.append(line.charAt(pos));
                this.dictionary.add(new Pair(LexType.NEQ, token.toString()));
            } else {
                this.dictionary.add(new Pair(LexType.NOT, token.toString()));
            }
        } else if (ch == '&') {
            if (line.charAt(pos) == '&') {
                token.append(line.charAt(pos));
                this.dictionary.add(new Pair(LexType.AND, token.toString()));
            } else {
                this.row_num = this.lineNum;
                this.column_num = pos - 1;
                this.errorType = ErrorType.a;
            }
        } else if (ch == '|') {
            if (line.charAt(pos) == '|') {
                token.append(line.charAt(pos));
                this.dictionary.add(new Pair(LexType.OR, token.toString()));
            } else {
                this.row_num = this.lineNum;
                this.column_num = pos - 1;
                this.errorType = ErrorType.a;
            }
        } else if (ch == '<') {
            if (line.charAt(pos) == '=') {
                token.append(line.charAt(pos));
                this.dictionary.add(new Pair(LexType.LEQ, token.toString()));
            } else {
                this.dictionary.add(new Pair(LexType.LSS, token.toString()));
            }
        } else if (ch == '>') {
            if (line.charAt(pos) == '=') {
                token.append(line.charAt(pos));
                this.dictionary.add(new Pair(LexType.GEQ, token.toString()));
            } else {
                this.dictionary.add(new Pair(LexType.GRE, token.toString()));
            }
        } else if (ch == '=') {
            if (line.charAt(pos) == '=') {
                token.append(line.charAt(pos));
                this.dictionary.add(new Pair(LexType.EQL, token.toString()));
            } else {
                this.dictionary.add(new Pair(LexType.ASSIGN, token.toString()));
            }
        } else if (ch == '+') {
            this.dictionary.add(new Pair(LexType.PLUS, token.toString()));
        } else if (ch == '-') {
            this.dictionary.add(new Pair(LexType.MINU, token.toString()));
        } else if (ch == '*') {
            this.dictionary.add(new Pair(LexType.MULT, token.toString()));
        } else if (ch == '/') {
            this.dictionary.add(new Pair(LexType.DIV, token.toString()));
        } else if (ch == '%') {
            this.dictionary.add(new Pair(LexType.MOD, token.toString()));
        } else if (ch == ';') {
            this.dictionary.add(new Pair(LexType.SEMICN, token.toString()));
        } else if (ch == ',') {
            this.dictionary.add(new Pair(LexType.COMMA, token.toString()));
        } else if (ch == '(') {
            this.dictionary.add(new Pair(LexType.LPARENT, token.toString()));
        }else if (ch == ')') {
            this.dictionary.add(new Pair(LexType.RPARENT, token.toString()));
        }else if (ch == '[') {
            this.dictionary.add(new Pair(LexType.LBRACK, token.toString()));
        }else if (ch == ']') {
            this.dictionary.add(new Pair(LexType.RBRACK, token.toString()));
        }else if (ch == '{') {
            this.dictionary.add(new Pair(LexType.LBRACE, token.toString()));
        } else if (ch == '}') {
            this.dictionary.add(new Pair(LexType.RBRACE, token.toString()));
        }
    }

    public void parseKeyWord(String token) {
        switch (token) {
            case "main" -> this.dictionary.add(new Pair(LexType.MAINTK, token));
            case "const" -> this.dictionary.add(new Pair(LexType.CONSTTK, token));
            case "int" -> this.dictionary.add(new Pair(LexType.INTTK, token));
            case "char" -> this.dictionary.add(new Pair(LexType.CHARTK, token));
            case "break" -> this.dictionary.add(new Pair(LexType.BREAKTK, token));
            case "continue" -> this.dictionary.add(new Pair(LexType.CONTINUETK, token));
            case "if" -> this.dictionary.add(new Pair(LexType.IFTK, token));
            case "else" -> this.dictionary.add(new Pair(LexType.ELSETK, token));
            case "for" -> this.dictionary.add(new Pair(LexType.FORTK, token));
            case "getint" -> this.dictionary.add(new Pair(LexType.GETINTTK, token));
            case "getchar" -> this.dictionary.add(new Pair(LexType.GETCHARTK, token));
            case "printf" -> this.dictionary.add(new Pair(LexType.PRINTFTK, token));
            case "return" -> this.dictionary.add(new Pair(LexType.RETURNTK, token));
            case "void" -> this.dictionary.add(new Pair(LexType.VOIDTK, token));
            default -> this.dictionary.add(new Pair(LexType.IDENFR, token));
        }
    }

    public void LexerOutPut() {
        String answer = "lexer.txt";
        String error = "error.txt";
        if (this.errorType != null) {
            try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(error))) {
                bufferedWriter.write(row_num + " a");
            } catch (IOException e) {
                System.err.println("Can't write " + error);
            }
        } else {
            try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(answer))) {
                for (Pair item : this.dictionary) {
                    bufferedWriter.write(item.getKey().toString() + " " + item.getValue());
                    bufferedWriter.newLine();
                }
            } catch (IOException e) {
                System.err.println("Can't write " + answer);
            }
        }
    }
}
