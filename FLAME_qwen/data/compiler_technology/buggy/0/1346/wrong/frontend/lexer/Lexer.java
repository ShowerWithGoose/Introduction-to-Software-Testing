package frontend.lexer;

import error.Error;
import error.ErrorHandler;
import error.ErrorType;

import java.io.*;
import java.util.*;

/**
 * @author
 * @Description:
 * @date 2024/9/29 16:47
 */
public class Lexer {
    //单例模式
    private static final Lexer instance = new Lexer();
    //词法分析出的
    private List<Token> tokens = new ArrayList<>();

    public static Lexer getInstance() {
        return instance;
    }

    private Map<String, LexType> reserveWords = new HashMap<String, LexType>() {{
        put("main", LexType.MAINTK);
        put("const", LexType.CONSTTK);
        put("int", LexType.INTTK);
        put("char", LexType.CHARTK);
        put("break", LexType.BREAKTK);
        put("continue", LexType.CONTINUETK);
        put("if", LexType.IFTK);
        put("else", LexType.ELSETK);
        put("for", LexType.FORTK);
        put("getint", LexType.GETINTTK);
        put("getchar", LexType.GETCHARTK);
        put("printf", LexType.PRINTFTK);
        put("return", LexType.RETURNTK);
        put("void", LexType.VOIDTK);
    }};

    public void analyze(String filename) {
        InputStream inputFileStream = null;
        try {
            inputFileStream = new FileInputStream(filename);
        } catch (FileNotFoundException e) {
            System.err.println("Can not open " + filename);
        }
        Scanner scanner = new Scanner(inputFileStream);
        //手动分行
        StringJoiner stringJoiner = new StringJoiner("\n");
        while (scanner.hasNextLine()) {
            stringJoiner.add(scanner.nextLine());
        }
        //源程序字符串
        String source = stringJoiner.toString();
        //当前行号
        int lineNum = 1;
        //源代码长度
        int sourceContent = source.length();
        //实际读入过程是按单词读入，以空格为边界去分开
        for (int curPos = 0; curPos < sourceContent; curPos++) {
            String token = "";
            char c = source.charAt(curPos);
            char next;
            if (curPos < sourceContent - 1) {
                next = source.charAt(curPos + 1);
            } else {
                next = '\0';
            }
            if (c == '_' || Character.isLetter(c)) { // 标识符IDENFR 或者其他所有的保留字
                token += c;
                while (next == '_' || Character.isDigit(next) || Character.isLetter(next)) {
                    token += next;
                    curPos++;
                    if (curPos == sourceContent - 1) {
                        break;
                    } else {
                        c = source.charAt(curPos);
                        next = source.charAt(curPos + 1);
                    }
                }
                tokens.add(new Token(reserveWords.getOrDefault(token, LexType.IDENFR), lineNum, token));
            } else if (Character.isDigit(c)) {// 数字INTCON
                token += c;
                while (Character.isDigit(next)) {
                    token += next;
                    curPos++;
                    if (curPos == sourceContent - 1) {
                        break;
                    } else {
                        c = source.charAt(curPos);
                        next = source.charAt(curPos + 1);
                    }
                }
                tokens.add(new Token(LexType.INTCON, lineNum, token));
            } else if (c == '\"') { // 字符串STRCON
                token += c;
                curPos++;
                c = source.charAt(curPos);
                while (c != '\"') {
                    token += c;
                    curPos++;
                    c = source.charAt(curPos);
                    next = source.charAt(curPos + 1);
                }
                tokens.add(new Token(LexType.STRCON, lineNum, token));
            } else if (c == '\'') { // 字符CHRCON
                token += c;
                curPos++;
                c = source.charAt(curPos);
                while (c != '\'') {
                    token += c;
                    curPos++;
                    c = source.charAt(curPos);
                    next = source.charAt(curPos + 1);
                }
                tokens.add(new Token(LexType.CHRCON, lineNum, token));
            } else if (c == '!') { // !NOT 或 !=NEQ
                if (next != '=') tokens.add(new Token(LexType.NOT, lineNum, "!"));
                else {
                    tokens.add(new Token(LexType.NEQ, lineNum, "!="));
                    curPos++;
                }
            } else if (c == '&') { // &&AND
                if (next == '&') {
                    tokens.add(new Token(LexType.AND, lineNum, "&&"));
                    curPos++;
                } else { //错误处理
                    tokens.add(new Token(LexType.AND, lineNum, "&"));
                    ErrorHandler.getInstance().addError(new Error(lineNum, ErrorType.a));
                }
            } else if (c == '|') { // ||OR
                if (next == '|') {
                    tokens.add(new Token(LexType.OR, lineNum, "||"));
                    curPos++;
                } else { // 错误处理
                    tokens.add(new Token(LexType.OR, lineNum, "|"));
                    ErrorHandler.getInstance().addError(new Error(lineNum, ErrorType.a));
                }
            } else if (c == '+') { // +PLUS
                tokens.add(new Token(LexType.PLUS, lineNum, "+"));
            } else if (c == '-') { // -MINU
                tokens.add(new Token(LexType.MINU, lineNum, "-"));
            } else if (c == '*') { // *MULT
                tokens.add(new Token(LexType.MULT, lineNum, "*"));
            } else if (c == '/') { // /DIV 或 //单行注释 或/*多行注释
                if (next == '/') { // //单行注释
                    int i = source.indexOf('\n', curPos + 2);
                    if (i == -1)
                        i = sourceContent;
                    curPos = i - 1;
                } else if (next == '*') { // /*多行注释
                    int i = curPos + 2;
                    char e = source.charAt(i);
                    while(!(e=='*'&&source.charAt(i+1)=='/')){
                        if(e=='\n')
                            lineNum++;
                        i++;
                        e = source.charAt(i);
                    }
                    curPos=i+1;
                }
            }else if (c == '%') { // %MOD
                tokens.add(new Token(LexType.MOD, lineNum, "%"));
            } else if (c == '<') { // <LSS 或 <=LEQ
                if (next != '=') { // <
                    tokens.add(new Token(LexType.LSS, lineNum, "<"));
                } else { //<=
                    tokens.add(new Token(LexType.LEQ, lineNum, "<="));
                    curPos++;
                }
            } else if (c == '>') { // >GRE 或 >=GEQ
                if (next != '=') { // >
                    tokens.add(new Token(LexType.GRE, lineNum, ">"));
                } else { // >=
                    tokens.add(new Token(LexType.GEQ, lineNum, ">="));
                    curPos++;
                }
            } else if (c == '=') { // ==EQL 或 =ASSIGN
                if (next == '=') { //==
                    tokens.add(new Token(LexType.EQL, lineNum, "=="));
                    curPos++;
                }
                else { //=
                    tokens.add(new Token(LexType.ASSIGN, lineNum, "="));
                }
            } else if (c == ';'){//SEMICN
                tokens.add(new Token(LexType.SEMICN, lineNum, ";"));
            }
            else if (c == ','){//COMMA
                tokens.add(new Token(LexType.COMMA, lineNum, ","));
            }
            else if (c == '('){//LPARENT
                tokens.add(new Token(LexType.LPARENT, lineNum, "("));
            }
            else if (c == ')'){//RPARENT
                tokens.add(new Token(LexType.RPARENT, lineNum, ")"));
            }
            else if (c == '['){//LBRACK
                tokens.add(new Token(LexType.LBRACK, lineNum, "["));
            }
            else if (c == ']'){//RBRACK
                tokens.add(new Token(LexType.RBRACK, lineNum, "]"));
            }
            else if (c == '{'){//LBRACE
                tokens.add(new Token(LexType.LBRACE, lineNum, "{"));
            }
            else if (c == '}'){//RBRACE
                tokens.add(new Token(LexType.RBRACE, lineNum, "}"));
            }else if(c == '\n'){//换行
                lineNum++;
            }
        }
        //关闭打开的传递
        scanner.close();
        try {
            inputFileStream.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
        public void printTokens(String filename){
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
                for (Token token : tokens) {
                    writer.write(token.toString());
                }
            } catch (IOException e) {
                System.err.println("Can not open " + filename);
            }
        }
}
