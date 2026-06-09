package frontend;
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Lexer {
    private Input input;
    private char ch;  // 当前字符
    private String curWord; // 当前识别到的标识符或数字
    private Token curToken;
    private long curNum;  // 当前识别到的数字
    private Symbol curSym;  // 当前的符号类型
    private Error error; // 懒得每次遇到都写一次Error
    private Map<String, Symbol> reservedWords = new HashMap<>();  // 保留字表
    private ArrayList<Token> tokenList = new ArrayList<>();
    private ArrayList<Error> errorList = new ArrayList<>();

    // 符号类型
    enum Symbol {
        IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK,
        BREAKTK, CONTINUETK, IFTK, ELSETK, FORTK, VOIDTK, GETINTTK, GETCHARTK,
        PRINTFTK, RETURNTK, PLUS, MINU, NOT, AND, OR, MULT, DIV, MOD, LSS, LEQ,
        GRE, GEQ, EQL, NEQ, ASSIGN, SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK,
        LBRACE, RBRACE
    }

    public Lexer(Input input) {
        this.input = input;
        loadReservedWords();
        try {
            getsym();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 词法分析主程序
    public void getsym() throws IOException {

        while (!this.input.endFile()) {

            input.skipWhiteSpace();
            if (skipComment()) {
                continue;
            }


            ch = input.getChar();

            // 处理标识符或关键字
            if (Character.isLetter(ch) || ch == '_') {
                StringBuilder sb = new StringBuilder();
                while (!input.endFile() && (Character.isLetterOrDigit(ch) || ch == '_')) {
                    sb.append(ch);
                    input.moveForward(1);
                    ch = input.getChar();
                }//出来的时候是空格 ； 等。这里如果后续出错可以改while条件
                curWord = sb.toString();

                int curLine = input.getLineNum();
                if (reservedWords.containsKey(curWord)) {//暂时没有处理“ ” 内是保留字的情况
                    curSym = reservedWords.get(curWord);
                    curToken = new Token(curSym, curLine, curWord);
                } else {
                    curToken = new Token(Symbol.IDENFR, curLine, curWord);
                }
                tokenList.add(curToken);

            }

            // 处理数字
            else if (Character.isDigit(ch)) {
                curNum = 0;
                while (!input.endFile() && Character.isDigit(ch)) {
                    curNum = curNum * 10 + (ch - '0');
                    input.moveForward(1);
                    ch = input.getChar();
                }//出来的时候是空格 ； 等。这里如果后续出错可以改while条件
                //error

                curWord = String.valueOf(curNum);
                curSym = Symbol.INTCON;
                int curLine = input.getLineNum();
                curToken = new Token(curSym, curLine, curWord);
                tokenList.add(curToken);
            }

            else if (ch == '"') {
                StringBuilder sb = new StringBuilder();
                char lastc = 0;
                while(! input.endFile()) {
                    sb.append(ch);
                    input.moveForward(1);
                    lastc = ch;
                    ch = input.getChar();
                    if (ch == '"' && lastc != 92) { //47 即 /
                        break;
                    }
                }
                sb.append(ch);
                curWord = sb.toString();
                int curLine = input.getLineNum();
                curToken = new Token(Symbol.STRCON, curLine, curWord);
                tokenList.add(curToken);
                input.moveForward(1);
            }

            else if (ch == 39) { // 39 即 '
                String subS = input.getString(3);
                char arr[] = subS.toCharArray();
                if (arr[1] == 92) {
                    String subS1 = input.getString(4);
                    char arr1[] = subS1.toCharArray();
                    if (arr1[0] == 39 && arr1[3] == 39) {
                        curWord = subS1;
                        int curLine = input.getLineNum();
                        curToken = new Token(Symbol.CHRCON, curLine, curWord);
                        tokenList.add(curToken);
                        input.moveForward(4);
                    } else{
                        //todo
                        //error
                    }
                } else if (arr[0] == 39 && arr[2] == 39) {
                    curWord = subS;
                    int curLine = input.getLineNum();
                    curToken = new Token(Symbol.CHRCON, curLine, curWord);
                    tokenList.add(curToken);
                    input.moveForward(3);
                } else {
                    //todo
                    //error
                }
            }

            // 处理 `<`, `<=`, `<>`
            else if (ch == '<') {
                String subS = input.getString(2);
                if (subS.equals("<=")) {
                    curSym = Symbol.LEQ;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, "<=");
                    tokenList.add(curToken);
                    input.moveForward(2);
                } else {
                    curSym = Symbol.LSS;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, "<");
                    tokenList.add(curToken);
                    input.moveForward(1);
                }
            }

            // 处理 `>`, `>=`
            else if (ch == '>') {
                String subS = input.getString(2);
                if (subS.equals(">=")) {
                    curSym = Symbol.GEQ;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, ">=");
                    tokenList.add(curToken);
                    input.moveForward(2);
                } else {
                    curSym = Symbol.GRE;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, ">");
                    tokenList.add(curToken);
                    input.moveForward(1);
                }
            }

            //处理 = ==
            else if (ch == '=') {
                String subS = input.getString(2);
                if (subS.equals("==")) {
                    curSym = Symbol.EQL;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, "==");
                    tokenList.add(curToken);
                    input.moveForward(2);
                } else {
                    curSym = Symbol.ASSIGN;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, "=");
                    tokenList.add(curToken);
                    input.moveForward(1);
                }
            }

            //处理 ! !=
            else if (ch == '!') {
                String subS = input.getString(2);
                if (subS.equals("!=")) {
                    curSym = Symbol.NEQ;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, "!=");
                    tokenList.add(curToken);
                    input.moveForward(2);
                } else {
                    curSym = Symbol.NOT;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, "!");
                    tokenList.add(curToken);
                    input.moveForward(1);
                }
            }

            //处理 &&
            else if (ch == '&') {
                String subS = input.getString(2);
                if (subS.equals("&&")) {
                    curSym = Symbol.AND;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, "&&");
                    tokenList.add(curToken);
                    input.moveForward(2);
                } else {
                    //todo
                    //a类错误
                    int curLine = input.getLineNum();
                    error = new Error('a', curLine);
                    errorList.add(error);
                    input.moveForward(1);
                }
            }

            //处理 ||
            else if (ch == '|') {
                String subS = input.getString(2);
                if (subS.equals("||")) {
                    curSym = Symbol.OR;
                    int curLine = input.getLineNum();
                    curToken = new Token(curSym, curLine, "||");
                    tokenList.add(curToken);
                    input.moveForward(2);
                } else {
                    //todo
                    //a类错误
                    int curLine = input.getLineNum();
                    error = new Error('a', curLine);
                    errorList.add(error);
                    input.moveForward(1);
                }
            }

            // 处理其他符号
            else {
                boolean flag = true;
                switch (ch) {
                    case '+':
                        curSym = Symbol.PLUS;
                        break;
                    case '-':
                        curSym = Symbol.MINU;
                        break;
                    case '*':
                        curSym = Symbol.MULT;
                        break;
                    case '/':            //
                        curSym = Symbol.DIV;
                        break;
                    case '%':
                        curSym = Symbol.MOD;
                        break;
                    case ',':
                        curSym = Symbol.COMMA;
                        break;
                    case '(':
                        curSym = Symbol.LPARENT;
                        break;
                    case ')':
                        curSym = Symbol.RPARENT;
                        break;
                    case ';':
                        curSym = Symbol.SEMICN;
                        break;
                    case '[':
                        curSym = Symbol.LBRACK;
                        break;
                    case ']':
                        curSym = Symbol.RBRACK;
                        break;
                    case '{':
                        curSym = Symbol.LBRACE;
                        break;
                    case '}':
                        curSym = Symbol.RBRACE;
                        break;
                    default:
                        flag = false;
                        //todo
                        //error
                        break;
                }
                if (flag) {
                    int curLine = input.getLineNum();
                    String s = String.valueOf(ch);
                    curToken = new Token(curSym, curLine, s);
                    tokenList.add(curToken);
                    input.moveForward(1);
                } else {
                    //todo
                    //error
                    input.moveForward(1);
                }
            }
        }

    }

    public boolean skipComment() {
        if ("//".equals(this.input.getString(2))) {
//            System.out.println("find comment");
            this.input.skipCurLine();
            return true;
        } else if ("/*".equals(this.input.getString(2))) {
            input.moveForward(2);
            while (!this.input.endFile() &&
                    !"*/".equals(this.input.getString(2))) {
                this.input.moveForward(1);
            }
            if ("*/".equals(this.input.getString(2))) {
                this.input.moveForward(2);
                return true;
            }
        }
        return false;
    }

    // 加载保留字到映射表
    private void loadReservedWords() {
        reservedWords.put("main", Symbol.MAINTK);
        reservedWords.put("const", Symbol.CONSTTK);
        reservedWords.put("int", Symbol.INTTK);
        reservedWords.put("char", Symbol.CHARTK);
        reservedWords.put("break", Symbol.BREAKTK);
        reservedWords.put("continue", Symbol.CONTINUETK);
        reservedWords.put("if", Symbol.IFTK);
        reservedWords.put("else", Symbol.ELSETK);
        reservedWords.put("!", Symbol.NOT);
        reservedWords.put("&&", Symbol.AND);
        reservedWords.put("||", Symbol.OR);
        reservedWords.put("for", Symbol.FORTK);
        reservedWords.put("getint", Symbol.GETINTTK);
        reservedWords.put("getchar", Symbol.GETCHARTK);
        reservedWords.put("printf", Symbol.PRINTFTK);
        reservedWords.put("return", Symbol.RETURNTK);

        reservedWords.put("+", Symbol.PLUS);
        reservedWords.put("-", Symbol.MINU);
        reservedWords.put("void", Symbol.VOIDTK);
        reservedWords.put("*", Symbol.MULT);
        reservedWords.put("/", Symbol.DIV);
        reservedWords.put("%", Symbol.MOD);
        reservedWords.put("<", Symbol.LSS);
        reservedWords.put("<=", Symbol.LEQ);
        reservedWords.put(">", Symbol.GRE);
        reservedWords.put(">=", Symbol.GEQ);
        reservedWords.put("==", Symbol.EQL);
        reservedWords.put("!=", Symbol.NEQ);
        reservedWords.put("=", Symbol.ASSIGN);
        reservedWords.put(";", Symbol.SEMICN);
        reservedWords.put(",", Symbol.COMMA);
        reservedWords.put("(", Symbol.LPARENT);

        reservedWords.put(")", Symbol.RPARENT);
        reservedWords.put("[", Symbol.LBRACK);
        reservedWords.put("]", Symbol.RBRACK);
        reservedWords.put("{", Symbol.LBRACE);
        reservedWords.put("}", Symbol.RBRACE);
    }

    public ArrayList<String> getTokenListToString() {
        ArrayList<String> tokenStringList = new ArrayList<>();
        for (int i = 0; i < tokenList.size(); i++) {
            tokenStringList.add(tokenList.get(i).toString());
        }
        return tokenStringList;
    }

    public boolean noError() {
        return errorList.isEmpty();
    }

    public ArrayList<String> getErrorListToString() {
        ArrayList<String> errorStringList = new ArrayList<>();
        for (int i = 0; i < errorList.size(); i++) {
            errorStringList.add(errorList.get(i).toString());
        }
        return errorStringList;
    }
}
