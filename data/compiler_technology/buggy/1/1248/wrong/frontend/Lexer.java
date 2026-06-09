package frontend;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class Lexer {
    private static Lexer instance;
    private BufferedReader in;
    // private BufferedWriter out;
    private BufferedWriter error;
    private int curPos; // 当前读到的位置
    private String line; // 逐行读取的内容，配合curPos使用
    private LexType type; // 当前读到单词的类别码
    private String token; // 单词值
    private int lineNum; // 当前行号
    private int num; // 解析数值
    private HashSet<String> keywords; // 保留字
    private HashMap<String, LexType> mapper;
    private boolean singleComment; // 是否正在处理多行注释
    private boolean multiComment; // 是否正在处理多行注释
    private ArrayList<Word> words;


    private Lexer(BufferedReader in, BufferedWriter error) { // 饿汉单例模式
        this.in = in;
        // this.out = out;
        this.error = error;
        curPos = 0;
        lineNum = 1;
        keywords = new HashSet<>(Arrays.asList("main", "const", "int",
                "char", "break", "continue", "if", "else", "for",
                "getint", "getchar", "printf", "return", "void"));
        initMapper();
        singleComment = false;
        multiComment = false;
        words = new ArrayList<>();
    }

    public static Lexer getInstance(BufferedReader in, BufferedWriter error) {
        if (instance == null) {
            instance = new Lexer(in, error);
        }
        return instance;
    }

    public void run() throws IOException {
        // String line;
        while ((line = in.readLine()) != null) {
            singleComment = false; // 每一行刷新单行注释的状态
            for (curPos = 0; curPos < line.length();) {
                if (multiComment) {
                    int index = line.indexOf("*/");
                    if (index != -1) {
                        curPos = index + 2;
                        multiComment = false;
                    }
                    else { // 本行不存在多行注释结束符
                        break;
                    }
                }
                if (singleComment) {
                    break;
                }
                while (curPos < line.length() && Character.isWhitespace(line.charAt(curPos))) {
                    curPos++;
                }
                if (curPos < line.length()) {
                    getToken();
                }
            }
            lineNum++;
        }
    }

    public void getToken() throws IOException {
        char ch = line.charAt(curPos);
        token = "";
        StringBuilder sb = new StringBuilder();
        String next2 = line.substring(curPos, Math.min(curPos+2, line.length()));

        if (isLetter(ch) || ch == '_') { // 字母：标识符或保留字
            parseLetter(sb);
        }
        else if (Character.isDigit(ch)) { // 数字
            parseDigit(sb);
        }
        else if (ch == '/') {
            char next = line.charAt(curPos+1);
            if (next == '/') { // 单行注释
                singleComment = true;
                return;
            }
            else if (next == '*') { // 多行注释
                curPos += 2;
                multiComment = true;
                return;
            }
            else { // 除号
                type = LexType.DIV;
                token = "/";
                curPos++;
            }
        }
        else if (ch == '\'') { // 单引号
            parseSingleQuotation(sb);
        }
        else if (ch == '"') { // 双引号
            parseDoubleQuotation(sb);
        }
        else if (ch == '&' || ch == '|') {
            parseLogical(ch);
        }
        else if (mapper.containsKey(next2)) {
            type = mapper.get(next2);
            token = next2;
            curPos += 2;
        }
        else if (mapper.containsKey(String.valueOf(ch))) {
            token = String.valueOf(ch);
            type = mapper.get(token);
            curPos++;
        }
        else {
            type = LexType.ERROR;
            System.out.println("Wrong: Undefined Symbol!");
            return;
        }
        if (this.type != LexType.ERROR) {
            words.add(new Word(lineNum, type, token, num));
        }
        // out.write(type + " " + token + "\n");
    }

    public void initMapper() {
        mapper = new HashMap<String, LexType>();
        mapper.put("!", LexType.NOT);
        mapper.put("+", LexType.PLUS);
        mapper.put("-", LexType.MINU);
        mapper.put("*", LexType.MULT);
        mapper.put("/", LexType.DIV);
        mapper.put("%", LexType.MOD);
        mapper.put("<", LexType.LSS);
        mapper.put("<=", LexType.LEQ);
        mapper.put(">", LexType.GRE);
        mapper.put(">=", LexType.GEQ);
        mapper.put("==", LexType.EQL);
        mapper.put("!=", LexType.NEQ);
        mapper.put("=", LexType.ASSIGN);
        mapper.put(";", LexType.SEMICN);
        mapper.put(",", LexType.COMMA);
        mapper.put("(", LexType.LPARENT);
        mapper.put(")", LexType.RPARENT);
        mapper.put("[", LexType.LBRACK);
        mapper.put("]", LexType.RBRACK);
        mapper.put("{", LexType.LBRACE);
        mapper.put("}", LexType.RBRACE);
    }

    public void parseLetter(StringBuilder sb) {
        do {
            sb.append(line.charAt(curPos));
            curPos++;
        } while(curPos < line.length() &&
                (Character.isLetter(line.charAt(curPos)) ||
                        Character.isDigit(line.charAt(curPos)) ||
                        line.charAt(curPos) == '_'));
        token = sb.toString();
        // 判断是否为保留字
        if (keywords.contains(token)) {
            type = LexType.valueOf((token.concat("tk")).toUpperCase());
        }
        else {
            type = LexType.IDENFR;
        }
    }

    public void parseDigit(StringBuilder sb) {
        do {
            sb.append(line.charAt(curPos));
            curPos++;
        } while(curPos < line.length() && Character.isDigit(line.charAt(curPos)));
        token = sb.toString();
        type = LexType.INTCON;
        // TODO 进行数值转换
        // num = Integer.parseInt(token);
    }

    public void parseSingleQuotation(StringBuilder sb) {
        sb.append('\'');
        sb.append(line.charAt(curPos+1));
        if (line.charAt(curPos+1) == '\\') {
            sb.append(line.charAt(curPos+2));
            curPos++;
        }
        sb.append('\'');
        curPos += 3; // 跳过右单引号
        type = LexType.CHRCON;
        token = sb.toString();
    }

    public void parseDoubleQuotation(StringBuilder sb) {
        do {
            sb.append(line.charAt(curPos));
            if (line.charAt(curPos) == '\\') { // 转义符，需要无条件读取下一个字符
                curPos++;
                sb.append(line.charAt(curPos));
            }
            curPos++;
        } while(curPos < line.length() && line.charAt(curPos) != '"');
        sb.append('"');
        curPos++;
        type = LexType.STRCON;
        token = sb.toString();
    }

    public void parseLogical(char ch) throws IOException {
        if (curPos+1 < line.length()) {
            char nextChar = line.charAt(curPos+1);
            curPos += 2;
            if (ch == nextChar) {
                type = (ch == '&') ? LexType.AND : LexType.OR;
                token = (ch == '&') ? "&&" : "||";
                return;
            }
        }
        type = LexType.ERROR;
        words.add(new Word(lineNum, type, token, num));
        error.write(lineNum + " a\n");
    }

    public boolean isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    public ArrayList<Word> getWords() {
        return words;
    }
}
