import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedHashMap;

public class Lexer {
    private static Lexer lexer;
    private HashSet<String> reserveWords;
    private LinkedHashMap<LexType, String> outputWords;
    private int lineNum;
    private int preLineNum;
    private String source;
    private String preSource;
    private int curPos;
    private int prePos;
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

    public int getLineNum() {
        return this.lineNum;
    }

    public int getCurPos() {
        return this.curPos;
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
            lexType  = reserveDealing(token);
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
                return 5;
            } else if (curPos < source.length() && source.charAt(curPos) == '*') { // '/*'
                stringBuilder.append(source.charAt(curPos));
                curPos++;
                if (curPos == source.length()) {
                    lineNum++;
                    curPos = 0;
                    source = inputStrings.get(lineNum);
                }
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
                return 5;
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
                IOStream.setErrorHappened(ErrorType.a, lineNum, curPos);
                token = stringBuilder.toString();
                lexType = LexType.AND;
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
                IOStream.setErrorHappened(ErrorType.a, lineNum, curPos);
                token = stringBuilder.toString();
                lexType = LexType.OR;
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

    public void setPrePos() {
        prePos = curPos;
        preLineNum = lineNum;
    }

    public LexType preRead() {
        StringBuilder stringBuilder = new StringBuilder();
        if (IOStream.outOfLineNum(preLineNum)) { // 行数大于实际行数
            return null;
        }
        preSource = inputStrings.get(preLineNum);
        if (prePos == preSource.length()) { // 本行读取完毕，换行
            prePos = 0;
            preLineNum++;
            return preRead();
        }
        char tempChar = preSource.charAt(prePos);
        if (tempChar == ' ') {
            prePos++;
            tempChar = preSource.charAt(prePos);
            return preRead();
        }
        prePos++;
        if (isLetterOrUnderline(tempChar)) {
            stringBuilder.append(tempChar);
            while (prePos < preSource.length() &&
                    (isLetterOrUnderline(preSource.charAt(prePos)) ||
                            Character.isDigit(preSource.charAt(prePos)))) {
                tempChar = preSource.charAt(prePos);
                prePos++;
                stringBuilder.append(tempChar);
            }
            // token = stringBuilder.toString();
            return reserveDealing(stringBuilder.toString());
        } else if (Character.isDigit(tempChar)) {
            stringBuilder.append(tempChar);
            while (prePos < preSource.length() &&
                    Character.isDigit(preSource.charAt(prePos))) {
                stringBuilder.append(preSource.charAt(prePos));
                prePos++;
            }
            //token = stringBuilder.toString();
            return LexType.INTCON;
            // outputWords.put(lexType, token);
        } else if (tempChar == '\'') {
            stringBuilder.append(tempChar);
            while (prePos < preSource.length() && preSource.charAt(prePos) != '\'') {
                if (preSource.charAt(prePos) == '\\') {
                    stringBuilder.append(preSource.charAt(prePos));
                    prePos++;
                }
                stringBuilder.append(preSource.charAt(prePos));
                prePos++;
            }
            stringBuilder.append(preSource.charAt(prePos)); // 最后的'
            prePos++;
            //token = stringBuilder.toString();
            return LexType.CHRCON;
        } else if (tempChar == '"') {
            stringBuilder.append(tempChar);
            while (prePos < preSource.length() && preSource.charAt(prePos) != '\"') {
                if (preSource.charAt(prePos) == '\\') {
                    stringBuilder.append(preSource.charAt(prePos));
                    prePos++;
                }
                stringBuilder.append(preSource.charAt(prePos));
                prePos++;
            }
            stringBuilder.append(preSource.charAt(prePos)); // 最后的"
            //token = stringBuilder.toString();
            prePos++;
            return LexType.STRCON;
        } else if (tempChar == '/') {
            stringBuilder.append(tempChar);
            if (prePos < preSource.length() && preSource.charAt(prePos) == '/') { // 第二个‘/’
                stringBuilder.append(preSource.charAt(prePos));
                prePos++;
                while (prePos < preSource.length()) { // 未到换行符
                    stringBuilder.append(preSource.charAt(prePos));
                    prePos++;
                }
                prePos = 0;
                preLineNum++; // source已经读完，换行
                return LexType.NOTE;
            } else if (prePos < preSource.length() && preSource.charAt(prePos) == '*') { // '/*'
                stringBuilder.append(preSource.charAt(prePos));
                prePos++;
                if (prePos == preSource.length()) {
                    preLineNum++;
                    prePos = 0;
                    preSource = inputStrings.get(preLineNum);
                }
                while (prePos < preSource.length()) {
                    while (prePos < preSource.length() && preSource.charAt(prePos) != '*') {
                        stringBuilder.append(preSource.charAt(prePos));
                        prePos++;
                        if (prePos == preSource.length()) { // 多行注释中的一行读完
                            preLineNum++;
                            prePos = 0;
                            preSource = inputStrings.get(preLineNum);
                        }
                    }
                    while (prePos < preSource.length() && preSource.charAt(prePos) == '*') {
                        stringBuilder.append(preSource.charAt(prePos));
                        prePos++;
                    }
                    if (prePos < preSource.length() && preSource.charAt(prePos) == '/') {
                        stringBuilder.append(preSource.charAt(prePos));
                        // lexType = LexType.NOTE;
                        break;
                    }
                }
                return LexType.NOTE;
            } else {
                //token = Character.toString(tempChar);
                //lexType = LexType.DIV;
                return LexType.DIV;
            }
        }  else if (tempChar == '<') {
            stringBuilder.append(tempChar);
            if (prePos < preSource.length() && preSource.charAt(prePos) == '=') { // <=
                stringBuilder.append(preSource.charAt(prePos));
                //token = stringBuilder.toString();
                //lexType = LexType.LEQ;
                prePos++;
                return LexType.LEQ;
            } else {
                //token = stringBuilder.toString();
                //lexType = LexType.LSS;
                return LexType.LSS;
            }
        } else if (tempChar == '>') {
            stringBuilder.append(tempChar);
            if (prePos < preSource.length() && preSource.charAt(prePos) == '=') { // >=
                //stringBuilder.append(source.charAt(prePos));
                //token = stringBuilder.toString();
                //lexType = LexType.GEQ;
                prePos++;
                return LexType.GEQ;
            } else {
                //token = stringBuilder.toString();
                //lexType = LexType.GRE;
                return LexType.GRE;
            }
        } else if (tempChar == '=') {
            stringBuilder.append(tempChar);
            if (prePos < preSource.length() && preSource.charAt(prePos) == '=') { // ==
                //stringBuilder.append(source.charAt(prePos));
                //token = stringBuilder.toString();
                //lexType = LexType.EQL;
                prePos++;
                return LexType.EQL;
            } else {
                //token = stringBuilder.toString();
                //lexType = LexType.ASSIGN;
                return LexType.ASSIGN;
            }
        } else if (tempChar == '!') {
            stringBuilder.append(tempChar);
            if (prePos < preSource.length() && preSource.charAt(prePos) == '=') { // !=
                //stringBuilder.append(source.charAt(prePos));
                //token = stringBuilder.toString();
                //lexType = LexType.NEQ;
                prePos++;
                return LexType.NEQ;
            } else {
                //token = stringBuilder.toString();
                //lexType = LexType.NOT;
                return LexType.NOT;
            }
        } else if (tempChar == '&') {
            stringBuilder.append(tempChar);
            if (prePos < preSource.length() && preSource.charAt(prePos) == '&') {
                //stringBuilder.append(source.charAt(prePos));
                //token = stringBuilder.toString();
                //lexType = LexType.AND;
                prePos++;
                return LexType.AND;
            } else { // error1
                IOStream.setErrorHappened(ErrorType.a, preLineNum, prePos);
                return LexType.AND; // 即预读的时候出现error,返回null
            }
        } else if (tempChar == '|') {
            stringBuilder.append(preSource.charAt(prePos));
            if (prePos < preSource.length() && preSource.charAt(prePos) == '|') {
                //stringBuilder.append(source.charAt(prePos));
                //token = stringBuilder.toString();
                //lexType = LexType.OR;
                prePos++;
                return LexType.OR;
            } else { // error1
                IOStream.setErrorHappened(ErrorType.a, lineNum, prePos);
                return null;
            }
        } else if (tempChar == '+') {
            //token = Character.toString(tempChar);
            //lexType = LexType.PLUS;
            return LexType.PLUS;
        } else if (tempChar == '-') {
            //token = Character.toString(tempChar);
            //lexType = LexType.MINU;
            return LexType.MINU;
        } else if (tempChar == ';') {
            //token = Character.toString(tempChar);
            //lexType = LexType.SEMICN;
            return LexType.SEMICN;
        } else if (tempChar == ',') {
            //token = Character.toString(tempChar);
            //lexType = LexType.COMMA;
            return LexType.COMMA;
        } else if (tempChar == '(') {
            //token = Character.toString(tempChar);
            //lexType = LexType.LPARENT;
            return LexType.LPARENT;
        } else if (tempChar == ')') {
            //token = Character.toString(tempChar);
            //lexType = LexType.RPARENT;
            return LexType.RPARENT;
        } else if (tempChar == '[') {
            //token = Character.toString(tempChar);
            //lexType = LexType.LBRACK;
            return LexType.LBRACK;
        } else if (tempChar == ']') {
            //token = Character.toString(tempChar);
            //lexType = LexType.RBRACK;
            return LexType.RBRACK;
        } else if (tempChar == '{') {
            //token = Character.toString(tempChar);
            //lexType = LexType.LBRACE;
            return LexType.LBRACE;
        } else if (tempChar == '}') {
            //token = Character.toString(tempChar);
            //lexType = LexType.RBRACE;
            return LexType.RBRACE;
        } else if (tempChar == '*') {
            //token = Character.toString(tempChar);
            //lexType = LexType.MULT;
            return LexType.MULT;
        } else if (tempChar == '%') {
            //token = Character.toString(tempChar);
            //lexType = LexType.MOD;
            return LexType.MOD;
        } else {
            return null;
        }
    }

    public void read1word() {
        while (true) {
            int next = next();
            if (next == 0 || next == 1 || next == 3) {
                break;
            }
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

    private LexType reserveDealing(String s) { // 查保留字表
        if (reserveWords.contains(s)) {
            if (s.equals("main")) {
                return LexType.MAINTK;
            } else if (s.equals("const")) {
                return LexType.CONSTTK;
            } else if (s.equals("int")) {
                return LexType.INTTK;
            } else if (s.equals("char")) {
                return LexType.CHARTK;
            } else if (s.equals("break")) {
                return LexType.BREAKTK;
            } else if (s.equals("continue")) {
                return LexType.CONTINUETK;
            } else if (s.equals("if")) {
                return LexType.IFTK;
            } else if (s.equals("else")) {
                return LexType.ELSETK;
            } else if (s.equals("for")) {
                return LexType.FORTK;
            } else if (s.equals("getint")) {
                return LexType.GETINTTK;
            } else if (s.equals("getchar")) {
                return LexType.GETCHARTK;
            } else if (s.equals("printf")) {
                return LexType.PRINTFTK;
            } else if (s.equals("return")) {
                return LexType.RETURNTK;
            } else if (s.equals("void")) {
                return LexType.VOIDTK;
            } else {
                return null;
            }
            //outputWords.put(lexType, s);
        } else {
            //outputWords.put(LexType.IDENFR, s);
            return LexType.IDENFR;
        }
    }

    public static Lexer getInstance() {
        // 如果是第一次使用：
        if (lexer == null) {
            lexer = new Lexer();
        }
        return lexer;
    }

    public void reset(int lineNum, int curPos, LexType lexType, String token) {
        this.lineNum = lineNum;
        this.curPos = curPos;
        this.lexType = lexType;
        this.token = token;
    }

}
