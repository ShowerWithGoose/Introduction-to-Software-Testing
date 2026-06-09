package Frontend;

import java.io.*;
import java.util.*;

public class Lexer {
    // 单词类别枚举类
    public enum LexType {
        IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK,
        IFTK, ELSETK, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, VOIDTK,
        PLUS, MINU, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
        COMMA, SEMICN, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE, AND, OR, NOT,
        ERROR
    }

    // 定义单词类别和关键字
    private static final Map<String, LexType> keywords = new HashMap<>();

    static {
        keywords.put("main", LexType.MAINTK);
        keywords.put("const", LexType.CONSTTK);
        keywords.put("int", LexType.INTTK);
        keywords.put("char", LexType.CHARTK);
        keywords.put("break", LexType.BREAKTK);
        keywords.put("continue", LexType.CONTINUETK);
        keywords.put("if", LexType.IFTK);
        keywords.put("else", LexType.ELSETK);
        keywords.put("for", LexType.FORTK);
        keywords.put("getint", LexType.GETINTTK);
        keywords.put("getchar", LexType.GETCHARTK);
        keywords.put("printf", LexType.PRINTFTK);
        keywords.put("return", LexType.RETURNTK);
        keywords.put("void", LexType.VOIDTK);
    }

    // 定义符号表
    private static final Map<String, LexType> symbols = new HashMap<>();

    static {
        symbols.put("+", LexType.PLUS);
        symbols.put("-", LexType.MINU);
        symbols.put("*", LexType.MULT);
        symbols.put("/", LexType.DIV);
        symbols.put("%", LexType.MOD);
        symbols.put("<", LexType.LSS);
        symbols.put("<=", LexType.LEQ);
        symbols.put(">", LexType.GRE);
        symbols.put(">=", LexType.GEQ);
        symbols.put("==", LexType.EQL);
        symbols.put("!=", LexType.NEQ);
        symbols.put("=", LexType.ASSIGN);
        symbols.put(",", LexType.COMMA);
        symbols.put(";", LexType.SEMICN);
        symbols.put("(", LexType.LPARENT);
        symbols.put(")", LexType.RPARENT);
        symbols.put("[", LexType.LBRACK);
        symbols.put("]", LexType.RBRACK);
        symbols.put("{", LexType.LBRACE);
        symbols.put("}", LexType.RBRACE);
        symbols.put("&&", LexType.AND);
        symbols.put("||", LexType.OR);
        symbols.put("!", LexType.NOT);
    }

    private BufferedReader reader;
    private String currentToken;
    private LexType currentLexType;
    private int lineNumber = 1;

    // 单例模式的实例
    private static Lexer instance;

    private Lexer(String inputFile) throws IOException {
        reader = new BufferedReader(new FileReader(inputFile));
    }

    // 单例模式获取实例的方法
    public static Lexer getInstance(String inputFile) throws IOException {
        if (instance == null) {
            instance = new Lexer(inputFile);
        }
        return instance;
    }

    // 处理下一个单词
    public void next() throws IOException {
        StringBuilder token = new StringBuilder();
        int ch;

        while ((ch = reader.read()) != -1) {
            char currentChar = (char) ch;

            // 跳过空白字符
            if (Character.isWhitespace(currentChar)) {
                if (currentChar == '\n') {
                    lineNumber++;
                }

                // 处理字符串常量
            } else if (currentChar == '"') {
                token.append(currentChar); // 添加第一个双引号
                while ((ch = reader.read()) != -1) {
                    currentChar = (char) ch;
                    token.append(currentChar);
                    if (currentChar == '"') {
                        currentToken = token.toString();
                        currentLexType = LexType.STRCON;
                        return;
                    }
                    if (currentChar == '\n' || currentChar == '\r') {
                        currentToken = token.toString();
                        currentLexType = LexType.ERROR;
                        return;
                    }
                }
                currentToken = token.toString();
                currentLexType = LexType.ERROR;
                return;

                // 处理字符常量
            } else if (currentChar == '\'') {
                token.append(currentChar);  // 添加第一个单引号
                ch = reader.read();
                currentChar = (char) ch;
                if (currentChar == '\\') {  // 处理转义字符
                    token.append(currentChar);
                    ch = reader.read();
                    currentChar = (char) ch;
                    token.append(currentChar);  // 添加转义后的字符
                } else if (currentChar != '\'') {
                    token.append(currentChar);  // 添加普通字符
                }
                ch = reader.read();
                currentChar = (char) ch;
                if (currentChar == '\'') {
                    token.append(currentChar);  // 添加结束单引号
                    currentToken = token.toString();
                    currentLexType = LexType.CHRCON;
                    return;
                } else {
                    currentToken = token.toString();
                    currentLexType = LexType.ERROR;
                    return;
                }

                // 处理单行或多行注释
            } else if (currentChar == '/') {
                reader.mark(1);  // 标记当前位置
                ch = reader.read();
                currentChar = (char) ch;

                if (currentChar == '/') {
                    while (ch != -1 && currentChar != '\n') {
                        ch = reader.read();
                        currentChar = (char) ch;
                    }
                    lineNumber++;
                    continue;

                } else if (currentChar == '*') {
                    boolean endOfComment = false;
                    while ((ch = reader.read()) != -1) {
                        currentChar = (char) ch;
                        if (currentChar == '*' && (ch = reader.read()) != -1 && (char) ch == '/') {
                            endOfComment = true;
                            break;
                        }
                        if (currentChar == '\n') {
                            lineNumber++;
                        }
                    }
                    if (!endOfComment) {
                        currentToken = "Unclosed multi-line comment";
                        currentLexType = LexType.ERROR;
                        return;
                    }
                    continue;

                } else {
                    reader.reset();
                    currentToken = "/";
                    currentLexType = LexType.DIV;
                    return;
                }

                // 处理标识符和关键字
            } else if (Character.isLetter(currentChar) || currentChar == '_') {
                while (Character.isLetterOrDigit(currentChar) || currentChar == '_') {
                    token.append(currentChar);
                    reader.mark(1);
                    ch = reader.read();
                    currentChar = (char) ch;
                }
                reader.reset();
                currentToken = token.toString();
                currentLexType = keywords.containsKey(currentToken) ? keywords.get(currentToken) : LexType.IDENFR;
                return;

                // 处理整数常量
            } else if (Character.isDigit(currentChar)) {
                while (Character.isDigit(currentChar)) {
                    token.append(currentChar);
                    reader.mark(1);
                    ch = reader.read();
                    currentChar = (char) ch;
                }
                reader.reset();
                currentToken = token.toString();
                currentLexType = LexType.INTCON;
                return;

                // 处理符号
            } else {
                String symbol = String.valueOf(currentChar);
                reader.mark(1);
                ch = reader.read();
                if (ch != -1) {
                    String possibleTwoCharSymbol = symbol + (char) ch;
                    if (symbols.containsKey(possibleTwoCharSymbol)) {
                        currentToken = possibleTwoCharSymbol;
                        currentLexType = symbols.get(possibleTwoCharSymbol);
                        return;
                    }
                }
                reader.reset();
                if (symbols.containsKey(symbol)) {
                    currentToken = symbol;
                    currentLexType = symbols.get(symbol);
                } else {
                    currentToken = symbol;
                    currentLexType = LexType.ERROR;  // 处理错误符号
                }
                return;
            }
        }
        currentToken = null;
        currentLexType = null;
    }

    // 获取当前读取的单词值
    public String getToken() {
        return currentToken;
    }

    // 获取当前读取的单词类型
    public LexType getLexType() {
        return currentLexType;
    }
}
