package frontend.lexer;
import java.util.HashMap;
import java.io.*;
import java.util.Objects;

import exeptions.Error;
import exeptions.ErrorList;
import exeptions.ErrorType;

public class Lexer {
    StringBuilder token = new StringBuilder();
    private static String source = ""; // 源程序字符串
    private int curPos = 0; // 当前字符串位置
    private TokenType tokenType = TokenType.START; // 单词类别
    private int lineNum = 1; // 行号
    private final HashMap<String, TokenType> reserveWords = new HashMap<>(); // 保留字
    private final TokenList tokenList = new TokenList(); // 程序中识别出的单词
    private final TokenList correctedTokenList = new TokenList(); // 程序中识别出的单词，经过改正之后的结果
    private final ErrorList errorList = new ErrorList(); // 程序中出现的用词错误
    private static Lexer lexer = null; // 用于单例模式

    public Lexer() {
        // 标识符集合
        this.reserveWords.put("main", TokenType.MAINTK);
        this.reserveWords.put("const", TokenType.CONSTTK);
        this.reserveWords.put("int", TokenType.INTTK);
        this.reserveWords.put("char", TokenType.CHARTK);
        this.reserveWords.put("break", TokenType.BREAKTK);
        this.reserveWords.put("continue", TokenType.CONTINUETK);
        this.reserveWords.put("if", TokenType.IFTK);
        this.reserveWords.put("else", TokenType.ELSETK);
        this.reserveWords.put("for", TokenType.FORTK);
        this.reserveWords.put("getint", TokenType.GETINTTK);
        this.reserveWords.put("getchar", TokenType.GETCHARTK);
        this.reserveWords.put("printf", TokenType.PRINTFTK);
        this.reserveWords.put("return", TokenType.RETURNTK);
        this.reserveWords.put("void", TokenType.VOIDTK);
    }
    public static Lexer getLexer(String inputFile) {
        // 输入程序文件名
        // 读取文件，结果存到source
        File f = new File(inputFile);
        if (!f.isFile()) {
            System.out.printf("%s is not a file\n", inputFile);
        }
        try (InputStream in = new FileInputStream(f)){
            source = new String(in.readAllBytes()); // 读取字节流，转化为字符串
        } catch (IOException e) {
            System.out.printf("cannot open file %s\n", inputFile);
        }
        // 获取单例
        if (lexer == null) {
            lexer = new Lexer();
        }
        return lexer;
    }
    public TokenList getTokenList() {
        correctedTokenList.clear();
        tokenList.clear(); // 清空之前的单词表
        errorList.clear(); // 清空之前的错误表
        int len = source.length();
        tokenType = TokenType.START; // 初始化
        char curChar;
        while (curPos < len) {
            curChar = source.charAt(curPos++);
            // 预处理
            token.append(curChar); // 将新的符号加入token字符串
            if (curChar == '\r') continue;// 忽略'\r'字符
            // 进行词法分析
            switch(tokenType) {
                case START -> {
                    token.setLength(0); // 清空上次的符号
                    token.append(curChar);
                    if (isAlpha(curChar) || curChar == '_') {
                        tokenType = TokenType.IDENFR;
                    } else if (isDigit(curChar) && curChar != '0') {
                        tokenType = TokenType.INTCON_NZERO;
                    } else if (curChar == '0') {
                        tokenType = TokenType.INTCON_ZERO;
                    } else {
                        switch (curChar) {
                            case '\'' -> tokenType = TokenType.CHRCON_1;
                            case '\"' -> tokenType = TokenType.STRCON_1;
                            case '!' -> tokenType = TokenType.NOT_NEQ;
                            case '&' -> tokenType = TokenType.SINGLEAND;
                            case '|' -> tokenType = TokenType.SINGLEOR;
                            case '+' -> addToken(TokenType.PLUS);
                            case '-' -> addToken(TokenType.MINU);
                            case '*' -> addToken(TokenType.MULT);
                            case '/' -> tokenType = TokenType.ANNO_DIV;
                            case '%' -> addToken(TokenType.MOD);
                            case '<' -> tokenType = TokenType.LSS_LEQ;
                            case '>' -> tokenType = TokenType.GRE_GEQ;
                            case '=' -> tokenType = TokenType.ASSIGN_EQL;
                            case ',' -> addToken(TokenType.COMMA);
                            case ';' -> addToken(TokenType.SEMICN);
                            case ')' -> addToken(TokenType.RPARENT);
                            case '(' -> addToken(TokenType.LPARENT);
                            case ']' -> addToken(TokenType.RBRACK);
                            case '[' -> addToken(TokenType.LBRACK);
                            case '}' -> addToken(TokenType.RBRACE);
                            case '{' -> addToken(TokenType.LBRACE);
                            default -> {}
                        }
                    }
                }
                case ANNO_DIV -> {
                    switch (curChar) {
                        case '/' -> tokenType = TokenType.ANNO_2;
                        case '*' -> tokenType = TokenType.ANNO_3;
                        default -> {
                            tokenType = TokenType.START; // 是除号
                            if (curChar != '\n') curPos--; // 回退一次
                            token.setLength(1);  // 回退至只剩下一个字符
                            addToken(TokenType.DIV);
                        }
                    }
                }
                case ANNO_2 -> {
                    if (curChar == '\n') tokenType = TokenType.START;
                }
                case ANNO_3 -> {
                    if (curChar == '*') tokenType = TokenType.ANNO_4;
                }
                case ANNO_4 -> {
                    if (curChar == '/') tokenType = TokenType.START;
                    else if (curChar != '*') tokenType = TokenType.ANNO_3;
                }
                case NOT_NEQ -> {
                    tokenType = TokenType.START;
                    if (curChar == '=') {
                        addToken(TokenType.NEQ);
                    } else {
                        if (curChar != '\n') curPos--;
                        token.setLength(1); // 回退至只剩下一个字符
                        addToken(TokenType.NOT);
                    }
                }
                case GRE_GEQ -> {
                    tokenType = TokenType.START;
                    if (curChar == '=') {
                        addToken(TokenType.GEQ);
                    } else {
                        if (curChar != '\n') curPos--;
                        token.setLength(1);
                        addToken(TokenType.GRE);
                    }
                }
                case LSS_LEQ -> {
                    tokenType = TokenType.START;
                    if (curChar == '=') {
                        addToken(TokenType.LEQ);
                    } else {
                        if (curChar != '\n') curPos--;
                        token.setLength(1); // 这两步是要回退一个字符
                        addToken(TokenType.LSS);
                    }
                }
                case ASSIGN_EQL -> {
                    tokenType = TokenType.START;
                    if (curChar == '=') {
                        addToken(TokenType.EQL);
                    } else {
                        if (curChar != '\n') curPos--;
                        token.setLength(1); // 这两步是要回退一个字符
                        addToken(TokenType.ASSIGN);
                    }
                }
                case IDENFR -> {
                    if (curChar == '_' || isDigit(curChar) || isAlpha(curChar)) {
                        tokenType = TokenType.IDENFR;
                    } else {
                        if (curChar != '\n') curPos--;
                        int originLen = token.length();
                        token.setLength(originLen - 1);// 回退一个符号

                        tokenType = TokenType.START;
                        TokenType reserved = reserveWords.get(token.toString());
                        addToken(Objects.requireNonNullElse(reserved, TokenType.IDENFR));
                        // 看看是不是保留字token
                    }
                }
                case INTCON_ZERO -> {
                    tokenType = TokenType.START;
                    if (isDigit(curChar) || isAlpha(curChar) || curChar == '_') {
//                        addError(); // 因为要求里面首字符不能是0.所以这是错误情况
                         // 按照实验要求，直接返回
                    } else {
                        if (curChar != '\n') curPos--;
                        token.setLength(1); // 这两步是要回退一个字符
                        addToken(TokenType.INTCON);
                    }
                }
                case INTCON_NZERO -> {
                    if (isDigit(curChar)) {
                        tokenType = TokenType.INTCON_NZERO;
                    } else {
                        if (curChar != '\n') curPos--;// 不是数字，回退一个字符
                        int originLen = token.length();
                        token.setLength(originLen - 1);
                        addToken(TokenType.INTCON);
                        tokenType = TokenType.START;
                    }
                }
                case CHRCON_1 -> {
                    if (curChar == '\\') tokenType = TokenType.CHRCON_2;
                    else if (curChar >= ' ' && curChar <= '~')
                        tokenType = TokenType.CHRCON_3;
                    else {
//                        addError();
                    }
                }
                case CHRCON_2 -> {
                    if (isConvertCh(curChar)) tokenType = TokenType.CHRCON_3;
                    else {
//                        addError();
                    }
                }
                case CHRCON_3 -> {
                    if (curChar == '\'') {
                        addToken(TokenType.CHRCON);
                        tokenType = TokenType.START;
                    } else {
//                        addError();
                    }
                }
                case STRCON_1 -> {
                    if (curChar == '\"') {
                        addToken(TokenType.STRCON);
                        tokenType = TokenType.START;
                    }
                }
                case SINGLEAND -> {
                    if (curChar == '&') {
                        tokenType = TokenType.START;
                        addToken(TokenType.AND);
                    } else {
                        addError();
                        addCorrectedToken(TokenType.AND);
                    }
                }
                case SINGLEOR -> {
                    if (curChar == '|') {
                        tokenType = TokenType.START;
                        addToken(TokenType.OR);
                    } else {
                        addError();
                        addCorrectedToken(TokenType.OR);
                    }
                }
                default -> {}
            }
            if (curChar == '\n') lineNum++; // 记录行号，方便调试
        }
        return this.tokenList;
    }
    public TokenList getCorrectedTokenList() {
        return this.correctedTokenList;
    }
    public ErrorList getErrorList() {
        return this.errorList;
    }
    private void addToken(TokenType tokenType) {
        tokenList.add(new Token(token.toString(), tokenType, lineNum)); // 字符串类型token存入其字符串
        correctedTokenList.add(new Token(token.toString(), tokenType, lineNum)); // 添加正确结果
    }
    private void addCorrectedToken(TokenType tokenType) {
        String tokenName;
        if (tokenType == TokenType.AND) {
            tokenName = "&&";
        } else if (tokenType == TokenType.OR) {
            tokenName = "||";
        } else {
            tokenName = token.toString();
        }
        correctedTokenList.add(new Token(tokenName, tokenType, lineNum));
    }
    private void addError() {
        tokenType = TokenType.START; // 重置当前的状态以便继续
        if (errorList.isEmpty())
            errorList.add(new Error(ErrorType.ILLEGAL_SYMBOL, lineNum));
    }
    private boolean isAlpha(char c) {
        return (c <= 'Z' && c >= 'A') ||
                (c <= 'z' && c >= 'a');
    }
    private boolean isDigit(char c) {
        return (c <= '9' && c >= '0');
    }
    private boolean isConvertCh(char c) {
        return c == 'a' || c == 'b' || c == 't' || c == 'n' ||
                c == 'v' || c == 'f' || c == '\"' || c == '\'' ||
                c == '\\' || c == '0';
    }
}
