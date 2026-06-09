import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedHashMap;

public class Lexer {
    private static Lexer lexer;
    private HashSet<String> reserveWords;
    private LinkedHashMap<LexType, String> outputWords;
    private int lineNum;
    private int number;
    private String source;
    private int curPos;
    private String token;
    private LexType lexType;
    private ArrayList<String> inputStrings; // 输入格式
    private Lexer() {
        reserveWords = new HashSet<>();
        createReserveWords();
        outputWords = new LinkedHashMap<>();
        lineNum = 0;
        curPos = 0;
    }

    public int next() {
        StringBuilder stringBuilder = new StringBuilder();
        if (IOStream.outOfLineNum(lineNum)) { // 行数大于实际行数
            return 1;
        }
        source = inputStrings.get(lineNum);
        if (curPos == source.length()) { // 本行读取完毕，换行
            lineNum++;
            curPos = 0;
            return 2;
        }
        char tempChar = source.charAt(curPos);
        curPos++;
        if (tempChar == ' ') {
            return 2;
        } else if (isLetterOrUnderline(tempChar)) {
            stringBuilder.append(tempChar);
            while (curPos < source.length() &&
                    (isLetterOrUnderline(source.charAt(curPos)) ||
                            Character.isDigit(source.charAt(curPos)))) {
                tempChar = source.charAt(curPos);
                curPos++;
                stringBuilder.append(tempChar);
            }
            token = stringBuilder.toString();
            reserveDealing(token);
            return 0;
        } else if (Character.isDigit(tempChar)) {
            stringBuilder.append(tempChar);
            while (curPos < source.length() &&
                    Character.isDigit(source.charAt(curPos))) {
                stringBuilder.append(source.charAt(curPos));
                curPos++;
            }
            token = stringBuilder.toString();
            lexType = LexType.INTCON;
            // outputWords.put(lexType, token);
            return 0;
        } else if (tempChar == '\'') {
            stringBuilder.append(tempChar);
            while (curPos < source.length() && source.charAt(curPos) != '\'') {
                if (source.charAt(curPos) == '\\') {
                    stringBuilder.append(source.charAt(curPos));
                    curPos++;
                }
                stringBuilder.append(source.charAt(curPos));
                curPos++;
            }
            stringBuilder.append(source.charAt(curPos)); // 最后的'
            curPos++;
            token = stringBuilder.toString();
            lexType = LexType.CHRCON;
            return 0;
        } else if (tempChar == '"') {
            stringBuilder.append(tempChar);
            while (curPos < source.length() && source.charAt(curPos) != '\"') {
                if (source.charAt(curPos) == '\\') {
                    stringBuilder.append(source.charAt(curPos));
                    curPos++;
                }
                stringBuilder.append(source.charAt(curPos));
                curPos++;
            }
            stringBuilder.append(source.charAt(curPos)); // 最后的"
            curPos++;
            token = stringBuilder.toString();
            lexType = LexType.STRCON;
            return 0;
        } else if (tempChar == '/') {
            stringBuilder.append(tempChar);
            if (curPos < source.length() && source.charAt(curPos) == '/') { // 第二个‘/’
                stringBuilder.append(source.charAt(curPos));
                curPos++;
                while (curPos < source.length()) { // 未到换行符
                    stringBuilder.append(source.charAt(curPos));
                    curPos++;
                }
                lineNum++; // source已经读完，换行
                curPos = 0; // curPos清零
                lexType = LexType.NOTE;
                return 2;
            } else if (curPos < source.length() && source.charAt(curPos) == '*') { // '/*'
                stringBuilder.append(source.charAt(curPos));
                curPos++;
                while (curPos < source.length()) {
                    while (curPos < source.length() && source.charAt(curPos) != '*') {
                        stringBuilder.append(source.charAt(curPos));
                        curPos++;
                        if (curPos == source.length()) { // 多行注释中的一行读完
                            lineNum++;
                            curPos = 0;
                            source = inputStrings.get(lineNum);
                        }
                    }
                    while (curPos < source.length() && source.charAt(curPos) == '*') {
                        stringBuilder.append(source.charAt(curPos));
                        curPos++;
                    }
                    if (curPos < source.length() && source.charAt(curPos) == '/') {
                        stringBuilder.append(source.charAt(curPos));
                        curPos++;
                        lexType = LexType.NOTE;
                        break;
                    }
                }
                return 2;
            } else {
                token = Character.toString(tempChar);
                lexType = LexType.DIV;
                return 0;
            }
        }  else if (tempChar == '<') {
            stringBuilder.append(tempChar);
            if (curPos < source.length() && source.charAt(curPos) == '=') { // <=
                stringBuilder.append(source.charAt(curPos));
                token = stringBuilder.toString();
                lexType = LexType.LEQ;
                curPos++;
            } else {
                token = stringBuilder.toString();
                lexType = LexType.LSS;
            }
            return 0;
        } else if (tempChar == '>') {
            stringBuilder.append(tempChar);
            if (curPos < source.length() && source.charAt(curPos) == '=') { // >=
                stringBuilder.append(source.charAt(curPos));
                token = stringBuilder.toString();
                lexType = LexType.GEQ;
                curPos++;
            } else {
                token = stringBuilder.toString();
                lexType = LexType.GRE;
            }
            return 0;
        } else if (tempChar == '=') {
            stringBuilder.append(tempChar);
            if (curPos < source.length() && source.charAt(curPos) == '=') { // ==
                stringBuilder.append(source.charAt(curPos));
                token = stringBuilder.toString();
                lexType = LexType.EQL;
                curPos++;
            } else {
                token = stringBuilder.toString();
                lexType = LexType.ASSIGN;
            }
            return 0;
        } else if (tempChar == '!') {
            stringBuilder.append(tempChar);
            if (curPos < source.length() && source.charAt(curPos) == '=') { // !=
                stringBuilder.append(source.charAt(curPos));
                token = stringBuilder.toString();
                lexType = LexType.NEQ;
                curPos++;
            } else {
                token = stringBuilder.toString();
                lexType = LexType.NOT;
            }
            return 0;
        } else if (tempChar == '&') {
            stringBuilder.append(tempChar);
            if (curPos < source.length() && source.charAt(curPos) == '&') {
                stringBuilder.append(source.charAt(curPos));
                token = stringBuilder.toString();
                lexType = LexType.AND;
                curPos++;
                return 0;
            } else { // error1
                IOStream.setErrorHappened(ErrorType.a, lineNum);
                return 3;
            }
        } else if (tempChar == '|') {
            stringBuilder.append(source.charAt(curPos));
            if (curPos < source.length() && source.charAt(curPos) == '|') {
                stringBuilder.append(source.charAt(curPos));
                token = stringBuilder.toString();
                lexType = LexType.OR;
                curPos++;
                return 0;
            } else { // error1
                IOStream.setErrorHappened(ErrorType.a, lineNum);
                return 3;
            }
        } else if (tempChar == '+') {
            token = Character.toString(tempChar);
            lexType = LexType.PLUS;
            return 0;
        } else if (tempChar == '-') {
            token = Character.toString(tempChar);
            lexType = LexType.MINU;
            return 0;
        } else if (tempChar == ';') {
            token = Character.toString(tempChar);
            lexType = LexType.SEMICN;
            return 0;
        } else if (tempChar == ',') {
            token = Character.toString(tempChar);
            lexType = LexType.COMMA;
            return 0;
        } else if (tempChar == '(') {
            token = Character.toString(tempChar);
            lexType = LexType.LPARENT;
            return 0;
        } else if (tempChar == ')') {
            token = Character.toString(tempChar);
            lexType = LexType.RPARENT;
            return 0;
        } else if (tempChar == '[') {
            token = Character.toString(tempChar);
            lexType = LexType.LBRACK;
            return 0;
        } else if (tempChar == ']') {
            token = Character.toString(tempChar);
            lexType = LexType.RBRACK;
            return 0;
        } else if (tempChar == '{') {
            token = Character.toString(tempChar);
            lexType = LexType.LBRACE;
            return 0;
        } else if (tempChar == '}') {
            token = Character.toString(tempChar);
            lexType = LexType.RBRACE;
            return 0;
        } else if (tempChar == '*') {
            token = Character.toString(tempChar);
            lexType = LexType.MULT;
            return 0;
        } else if (tempChar == '%') {
            token = Character.toString(tempChar);
            lexType = LexType.MOD;
            return 0;
        } else {
            return 4;
        }
    }

    public void setInputStrings(ArrayList<String> inputStrings) {
        this.inputStrings = inputStrings;
    }

    public String getToken() {
        return this.token;
    }

    public LexType getLexType() {
        return this.lexType;
    }

    private void createReserveWords() {
        reserveWords.add("main");
        reserveWords.add("const");
        reserveWords.add("int");
        reserveWords.add("char");
        reserveWords.add("break");
        reserveWords.add("continue");
        reserveWords.add("if");
        reserveWords.add("else");
        reserveWords.add("for");
        reserveWords.add("getint");
        reserveWords.add("getchar");
        reserveWords.add("printf");
        reserveWords.add("return");
        reserveWords.add("void");
    }

    private Boolean isLetterOrUnderline(char c) {
        if (Character.isLetter(c)) {
            return true;
        } else if (c == '_') {
            return true;
        }
        return false;
    }

    private void reserveDealing(String s) { // 查保留字表
        if (reserveWords.contains(s)) {
            if (s.equals("main")) {
                lexType = LexType.MAINTK;
            } else if (s.equals("const")) {
                lexType = LexType.CONSTTK;
            } else if (s.equals("int")) {
                lexType = LexType.INTTK;
            } else if (s.equals("char")) {
                lexType = LexType.CHARTK;
            } else if (s.equals("break")) {
                lexType = LexType.BREAKTK;
            } else if (s.equals("continue")) {
                lexType = LexType.CONTINUETK;
            } else if (s.equals("if")) {
                lexType = LexType.IFTK;
            } else if (s.equals("else")) {
                lexType = LexType.ELSETK;
            } else if (s.equals("for")) {
                lexType = LexType.FORTK;
            } else if (s.equals("getint")) {
                lexType = LexType.GETINTTK;
            } else if (s.equals("getchar")) {
                lexType = LexType.GETCHARTK;
            } else if (s.equals("printf")) {
                lexType = LexType.PRINTFTK;
            } else if (s.equals("return")) {
                lexType = LexType.RETURNTK;
            } else if (s.equals("void")) {
                lexType = LexType.VOIDTK;
            }
            //outputWords.put(lexType, s);
        } else {
            //outputWords.put(LexType.IDENFR, s);
            lexType = LexType.IDENFR;
        }
    }

    public static Lexer getInstance() {
        // 如果是第一次使用：
        if (lexer == null) {
            lexer = new Lexer();
        }
        return lexer;
    }

}
