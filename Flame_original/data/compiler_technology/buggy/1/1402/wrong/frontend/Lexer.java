package frontend;

import error.ErrorType;
import token.Token;
import token.TokenType;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import static error.Error.error;
import static utils.IO.*;

public class Lexer {
    private static final Lexer instance = new Lexer(); //只需要创建一个对象，采用单例模式
    public static Lexer getInstance() {
        return instance;
    }

    private boolean haveError = false;
    private List<Token> tokens = new ArrayList<>();
    public List<Token> getToken() {
        return tokens;
    }

    private final HashMap<String, TokenType> reserved = new HashMap<>(); //保留字的map
    private StringBuilder tmp_token = new StringBuilder(); //临时存放每一个分析出来的token

    public void analyze() throws IOException { //分析读入的字符流，生成符号流存储起来
        initMap(); //初始化保留字Map

        int i = 0, lineNumber = 1;
        String input = read("testfile.txt");
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("test.txt"))) {
            bufferedWriter.write(input);
        }

        while (i < input.length()) {
            clearToken();

            while (i < input.length() && isSpace(input.charAt(i))) {
                if (input.charAt(i) == '\n')
                    lineNumber++;
                i++;
            }

            if (i < input.length()) { //一定要有这个判断，否则可能会溢出
                if (input.charAt(i) == '_' || Character.isLetter(input.charAt(i))) { //是标识符或者保留字，注意下划线
                    while (input.charAt(i) == '_' || Character.isLetter(input.charAt(i)) || Character.isDigit(input.charAt(i))) {
                        catToken(input.charAt(i));
                        i++;
                    }
                    tokens.add(new Token(reserved.getOrDefault(tmp_token.toString(), TokenType.IDENFR), tmp_token.toString(), lineNumber));
                } else if (Character.isDigit(input.charAt(i))) { //是常数
                    while (Character.isDigit(input.charAt(i))) {
                        catToken(input.charAt(i));
                        i++;
                    }
                    tokens.add(new Token(TokenType.INTCON, tmp_token.toString(), lineNumber));
                } else if (input.charAt(i) == '\'') { //是字符常量,单引号开头
                    catToken(input.charAt(i)); //放入开头的单引号
                    i++;
                    if (input.charAt(i) == '\\') { //是转义字符
                        catToken(input.charAt(i));
                        i++;
                        catToken(input.charAt(i));
                        i++;
                    } else {
                        catToken(input.charAt(i)); //放入中间的字符
                        i++;
                    }
                    catToken(input.charAt(i)); //放入末尾的单引号
                    i++;
                    tokens.add(new Token(TokenType.CHRCON, tmp_token.toString(), lineNumber));
                } else if (input.charAt(i) == '\"') { //是字符串常量，双引号开头
                    catToken(input.charAt(i)); //放入开头的双引号
                    i++;
                    while (input.charAt(i) != '\"') {
                        catToken(input.charAt(i));
                        i++;
                    }
                    catToken(input.charAt(i)); //放入末尾的双引号
                    i++;
                    tokens.add(new Token(TokenType.STRCON, tmp_token.toString(), lineNumber));
                } else if (input.charAt(i) == '!') {
                    i++;
                    if (input.charAt(i) == '=') {
                        i++;
                        tokens.add(new Token(TokenType.NEQ, "!=", lineNumber));
                    } else {
                        tokens.add(new Token(TokenType.NOT, "!", lineNumber));
                    }
                } else if (input.charAt(i) == '&') {
                    i++;
                    if (input.charAt(i) == '&') {
                        i++;
                        tokens.add(new Token(TokenType.AND, "&&", lineNumber));
                    } else {
                        error(lineNumber, ErrorType.a);
                        haveError = true;
                        tokens.add(new Token(TokenType.AND,"&&",lineNumber));
                    }
                } else if (input.charAt(i) == '|') {
                    i++;
                    if (input.charAt(i) == '|') {
                        i++;
                        tokens.add(new Token(TokenType.OR, "||", lineNumber));
                    } else {
                        error(lineNumber, ErrorType.a);
                        haveError = true;
                        tokens.add(new Token(TokenType.OR,"||",lineNumber));
                    }
                } else if (input.charAt(i) == '+') {
                    i++;
                    tokens.add(new Token(TokenType.PLUS, "+", lineNumber));
                } else if (input.charAt(i) == '-') {
                    i++;
                    tokens.add(new Token(TokenType.MINU, "-", lineNumber));
                } else if (input.charAt(i) == '*') {
                    i++;
                    tokens.add(new Token(TokenType.MULT, "*", lineNumber));
                } else if (input.charAt(i) == '/') { //注意，可能是除法，或者单行或多行注释
                    i++;
                    if (input.charAt(i) == '/') { //单行注释
                        i++;
                        while (i < input.length() && input.charAt(i) != '\n') { //跳过注释内容直到换行或文件末尾
                            i++;
                        }
                    } else if (input.charAt(i) == '*') { //多行注释
                        i++;
                        while (i < input.length() - 1) {
                            if (input.charAt(i) == '*' && input.charAt(i + 1) == '/') {
                                i += 2;
                                break;
                            } else if (input.charAt(i) == '\n') {
                                lineNumber++;
                                i++;
                            } else {
                                i++;
                            }
                        }
                    } else {
                        tokens.add(new Token(TokenType.DIV, "/", lineNumber));
                    }
                } else if (input.charAt(i) == '%') {
                    i++;
                    tokens.add(new Token(TokenType.MOD, "%", lineNumber));
                } else if (input.charAt(i) == '<') {
                    i++;
                    if (input.charAt(i) == '=') {
                        i++;
                        tokens.add(new Token(TokenType.LEQ, "<=", lineNumber));
                    } else {
                        tokens.add(new Token(TokenType.LSS, "<", lineNumber));
                    }
                } else if (input.charAt(i) == '>') {
                    i++;
                    if (input.charAt(i) == '=') {
                        i++;
                        tokens.add(new Token(TokenType.GEQ, ">=", lineNumber));
                    } else {
                        tokens.add(new Token(TokenType.GRE, ">", lineNumber));
                    }
                } else if (input.charAt(i) == '=') {
                    i++;
                    if (input.charAt(i) == '=') {
                        i++;
                        tokens.add(new Token(TokenType.EQL, "==", lineNumber));
                    } else {
                        tokens.add(new Token(TokenType.ASSIGN, "=", lineNumber));
                    }
                } else if (input.charAt(i) == ';') {
                    i++;
                    tokens.add(new Token(TokenType.SEMICN, ";", lineNumber));
                } else if (input.charAt(i) == ',') {
                    i++;
                    tokens.add(new Token(TokenType.COMMA, ",", lineNumber));
                } else if (input.charAt(i) == '(') {
                    i++;
                    tokens.add(new Token(TokenType.LPARENT, "(", lineNumber));
                } else if (input.charAt(i) == ')') {
                    i++;
                    tokens.add(new Token(TokenType.RPARENT, ")", lineNumber));
                } else if (input.charAt(i) == '[') {
                    i++;
                    tokens.add(new Token(TokenType.LBRACK, "[", lineNumber));
                } else if (input.charAt(i) == ']') {
                    i++;
                    tokens.add(new Token(TokenType.RBRACK, "]", lineNumber));
                } else if (input.charAt(i) == '{') {
                    i++;
                    tokens.add(new Token(TokenType.LBRACE, "{", lineNumber));
                } else if (input.charAt(i) == '}') {
                    i++;
                    tokens.add(new Token(TokenType.RBRACE, "}", lineNumber));
                }
            }
        }
    }

    private void initMap() {
        reserved.put("main", TokenType.MAINTK);
        reserved.put("const", TokenType.CONSTTK);
        reserved.put("int", TokenType.INTTK);
        reserved.put("char", TokenType.CHARTK);
        reserved.put("break", TokenType.BREAKTK);
        reserved.put("continue", TokenType.CONTINUETK);
        reserved.put("if", TokenType.IFTK);
        reserved.put("else", TokenType.ELSETK);
        reserved.put("for", TokenType.FORTK);
        reserved.put("getint", TokenType.GETINTTK);
        reserved.put("getchar", TokenType.GETCHARTK);
        reserved.put("printf", TokenType.PRINTFTK);
        reserved.put("return", TokenType.RETURNTK);
        reserved.put("void", TokenType.VOIDTK);
    }

    private void catToken(char ch) {
        tmp_token.append(ch);
    }

    private void clearToken() {
        tmp_token.setLength(0);
    }

    private boolean isSpace(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
    }

    public void print_lexer_result() throws IOException {
        if (!haveError) {
            for (Token t : tokens) { //foreach遍历输出结果
                writeLexer(t.toString());
            }
        }
    }

}