package frontend;

import error.Err;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;


public class Lexer {
    private List<String> lines;                         // 文件内容
    private String source;                              // 当前行内容
    private int curPos;                                 // 当前指向字符
    private int lineNum;                                // 当前行号
    private StringBuilder name;                         // 当前字符串
    private LexType lexType;                            // 当前字符类型
    private HashMap<String,LexType> reserveWords;       // 保留字表
    private long num;                                    // 字值

    public Lexer(List<String> lines) {
        this.lines = lines;
        this.curPos = 0;
        this.lineNum = 1;
        this.reserveWords = new HashMap<>();
        reserveWords.put("main",LexType.MAINTK);
        reserveWords.put("const",LexType.CONSTTK);
        reserveWords.put("int",LexType.INTTK);
        reserveWords.put("char",LexType.CHARTK);
        reserveWords.put("break",LexType.BREAKTK);
        reserveWords.put("continue",LexType.CONTINUETK);
        reserveWords.put("if",LexType.IFTK);
        reserveWords.put("else",LexType.ELSETK);
        reserveWords.put("for",LexType.FORTK);
        reserveWords.put("getint",LexType.GETINTTK);
        reserveWords.put("getchar",LexType.GETCHARTK);
        reserveWords.put("printf",LexType.PRINTFTK);
        reserveWords.put("return",LexType.RETURNTK);
        reserveWords.put("void",LexType.VOIDTK);
    }

    public List<Token> tokenize(ArrayList<Err> errorList) {
        List<Token> tokens = new ArrayList<>();
        Iterator<String> iter = lines.iterator();
        while (iter.hasNext()) {
            source = iter.next();
            System.out.println(source);
            while (curPos < source.length()) {
                while (curPos < source.length() && "\t ".indexOf(source.charAt(curPos)) != -1) {
                    curPos++;
                }
                if (curPos < source.length()) {
                    Token token = next(iter, errorList);
                    tokens.add(token);
                }
            }
            lineNum++;
            curPos = 0;
        }
        return tokens;
    }

    private Token next(Iterator<String> iter, ArrayList<Err> errorList) {
        Token token;
        name = new StringBuilder();
        char cur = source.charAt(curPos);
        if (Character.isDigit(cur)) { // INTCONST
            intConst();
            token = new Token(name.toString(),num,lineNum,lexType);
        }
        else if (Character.isLetter(cur) || cur == '_') { // IDENFR/RESERVE
            identAndReserve();
            token = new Token(name.toString(),0,lineNum,lexType);
        }
        else if (cur == '/') { // NOTE/DIV
            noteOrDiv(iter);
            token = new Token(name.toString(), 0, lineNum, lexType); // 跨行注释存了最后一行
        }
        else if (cur == '\'') { // CHARCONST
            charConst();
            token = new Token(name.toString(),0,lineNum,lexType);
        }
        else if (cur == '\"') { // STRCONST
            stringConst();
            token = new Token(name.toString(),0,lineNum,lexType);
        }
        else { // SIGNAL
            signal(errorList);
            token = new Token(name.toString(),0, lineNum, lexType);
        }
        return token;
    }

    private void intConst() {
        name.append(source.charAt(curPos++));
        while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
            name.append(source.charAt(curPos++));
        }
        num = Long.parseLong(name.toString());
        lexType = LexType.INTCON;
    }

    private void identAndReserve() {
        name.append(source.charAt(curPos++));
        while (curPos < source.length() && (Character.isLetter(source.charAt(curPos)) ||
                Character.isDigit(source.charAt(curPos)) || source.charAt(curPos) == '_')) {
            name.append(source.charAt(curPos++));
        }
        lexType = reserveWords.getOrDefault(name.toString(), LexType.IDENFR);
    }

    private void noteOrDiv(Iterator<String> iter) {
        name.append(source.charAt(curPos++));
        if (curPos < source.length() && source.charAt(curPos) == '/') { // 单行注释
            do {
                name.append(source.charAt(curPos++));
            } while (curPos < source.length());
            lexType = LexType.NOTE;
        }
        else if (curPos < source.length() && source.charAt(curPos) == '*') { // 多行注释
            name.append(source.charAt(curPos++));
            while (!(curPos + 1 < source.length() && source.charAt(curPos) == '*' && source.charAt(curPos + 1) == '/')) {
                if (curPos < source.length()) {
                    name.append(source.charAt(curPos++));
                }
                else {
                    if (iter.hasNext()) {
                        source = iter.next();
                        lineNum++;
                        curPos = 0;
                    }
                    else {
                        return;
                    }
                }
            }
            name.append(source.charAt(curPos++));
            name.append(source.charAt(curPos++));
            lexType = LexType.NOTE;
        }
        else { // 除号
            lexType = LexType.DIV;
        }
    }

    private void charConst() {
        name.append(source.charAt(curPos++));
        if (source.charAt(curPos) == '\\') {
            name.append(source.charAt(curPos++));

        }
        name.append(source.charAt(curPos++));
        name.append(source.charAt(curPos++));
        lexType = LexType.CHRCON;
    }

    private void stringConst() {
        name.append(source.charAt(curPos++));
        while (curPos < source.length() && source.charAt(curPos) != '\"') {
            name.append(source.charAt(curPos++));
        }
        name.append(source.charAt(curPos++));
        lexType = LexType.STRCON;
    }

    private void signal(ArrayList<Err> errorList) {
        name.append(source.charAt(curPos));
        switch (source.charAt(curPos++)) {
            case '!':
                if (curPos < source.length() && source.charAt(curPos) == '=') {
                    name.append(source.charAt(curPos++));
                    lexType = LexType.NEQ;
                }
                else {
                    lexType = LexType.NOT;
                }
                break;

            case '&':
                if (curPos < source.length() && source.charAt(curPos) == '&') {
                    name.append(source.charAt(curPos++));
                    lexType = LexType.AND;
                }
                else {
                    errorList.add(new Err(lineNum,"a"));
                }
                break;

            case '|':
                if (curPos < source.length() && source.charAt(curPos) == '|') {
                    name.append(source.charAt(curPos++));
                    lexType = LexType.OR;
                }
                else {
                    errorList.add(new Err(lineNum,"a"));
                }
                break;

            case '+':
                lexType = LexType.PLUS;
                break;

            case '-':
                lexType = LexType.MINU;
                break;

                case '*':
                lexType = LexType.MULT;
                break;

            case '%':
                lexType = LexType.MOD;
                break;

            case '<':
                if (curPos < source.length() && source.charAt(curPos) == '=') {
                    name.append(source.charAt(curPos++));
                    lexType = LexType.LEQ;
                }
                else {
                    lexType = LexType.LSS;
                }
                break;

            case '>':
                if (curPos < source.length() && source.charAt(curPos) == '=') {
                    name.append(source.charAt(curPos++));
                    lexType = LexType.GEQ;
                }
                else {
                    lexType = LexType.GRE;
                }
                break;

            case '=':
                if (curPos < source.length() && source.charAt(curPos) == '=') {
                    name.append(source.charAt(curPos++));
                    lexType = LexType.EQL;
                }
                else {
                    lexType = LexType.ASSIGN;
                }
                break;

            case ';':
                lexType = LexType.SEMICN;
                break;

            case ',':
                lexType = LexType.COMMA;
                break;

            case '(':
                lexType = LexType.LPARENT;
                break;

            case ')':
                lexType = LexType.RPARENT;
                break;

            case '[':
                lexType = LexType.LBRACK;
                break;

            case ']':
                lexType = LexType.RBRACK;
                break;

            case '{':
                lexType = LexType.LBRACE;
                break;

            case '}':
                lexType = LexType.RBRACE;
                break;

            default:
                System.out.println("unpair");
                break;
        }
    }
}
