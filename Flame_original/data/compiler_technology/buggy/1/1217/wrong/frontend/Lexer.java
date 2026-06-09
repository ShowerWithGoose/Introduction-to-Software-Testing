package frontend;

import java.io.*;
import java.util.*;
import java.util.regex.*;

import error.Error;
import error.ErrorType;

public class Lexer {
    private static Lexer instance;
    private BufferedReader reader;
    private String currentLine;
    private int lineNumber = 0;
    private int currentPos = 0;
    private String tokenValue;
    private LexType tokenType;
    public static List<Error> errorList = new ArrayList<>();  // 用于记录错误的行号和类别码

    // Token patterns
    private static final Pattern IDENFR_PATTERN = Pattern.compile("[a-zA-Z_][a-zA-Z0-9_]*");
    private static final Pattern INTCON_PATTERN = Pattern.compile("\\d+");
    private static final Pattern STRCON_PATTERN = Pattern.compile("\".*?\"");
    private static final Pattern CHRCON_PATTERN = Pattern.compile("'(\\\\[abfnrtv0\\\\'\"\\?]|[^\\\\'])'");

    // 保留字表
    private static final Map<String, LexType> RESERVED_WORDS = new HashMap<>();
    static {
        RESERVED_WORDS.put("const", LexType.CONSTTK);
        RESERVED_WORDS.put("int", LexType.INTTK);
        RESERVED_WORDS.put("char", LexType.CHARTK);
        RESERVED_WORDS.put("void", LexType.VOIDTK);
        RESERVED_WORDS.put("main", LexType.MAINTK);
        RESERVED_WORDS.put("if", LexType.IFTK);
        RESERVED_WORDS.put("else", LexType.ELSETK);
        RESERVED_WORDS.put("for", LexType.FORTK);
        RESERVED_WORDS.put("break", LexType.BREAKTK);
        RESERVED_WORDS.put("continue", LexType.CONTINUETK);
        RESERVED_WORDS.put("return", LexType.RETURNTK);
        RESERVED_WORDS.put("getint", LexType.GETINTTK);
        RESERVED_WORDS.put("getchar", LexType.GETCHARTK);
        RESERVED_WORDS.put("printf", LexType.PRINTFTK);
        
        RESERVED_WORDS.put("&&", LexType.AND);
        RESERVED_WORDS.put("||", LexType.OR);
        RESERVED_WORDS.put(">=", LexType.GEQ);
        RESERVED_WORDS.put("<=", LexType.LEQ);
        RESERVED_WORDS.put("==", LexType.EQL);
        RESERVED_WORDS.put("!=", LexType.NEQ);

        RESERVED_WORDS.put("!", LexType.NOT);
        RESERVED_WORDS.put("+", LexType.PLUS);
        RESERVED_WORDS.put("-", LexType.MINU);
        RESERVED_WORDS.put("*", LexType.MULT);
        RESERVED_WORDS.put("/", LexType.DIV);
        RESERVED_WORDS.put("%", LexType.MOD);
        RESERVED_WORDS.put("<", LexType.LSS);
        RESERVED_WORDS.put(">", LexType.GRE); 
        RESERVED_WORDS.put("=", LexType.ASSIGN);
        RESERVED_WORDS.put(";", LexType.SEMICN);
        RESERVED_WORDS.put(",", LexType.COMMA);
        RESERVED_WORDS.put("(", LexType.LPARENT);
        RESERVED_WORDS.put(")", LexType.RPARENT);
        RESERVED_WORDS.put("[", LexType.LBRACK);
        RESERVED_WORDS.put("]", LexType.RBRACK);
        RESERVED_WORDS.put("{", LexType.LBRACE);
        RESERVED_WORDS.put("}", LexType.RBRACE);
    }

    private Lexer() {}

    public static Lexer getInstance() {
        if (instance == null) {
            instance = new Lexer();
        }
        return instance;
    }

    // 初始化词法分析器，读取源文件
    public void initialize(String filePath) throws IOException {
        reader = new BufferedReader(new FileReader(filePath));
    }

    private String getNextLine() throws IOException {
        currentLine = reader.readLine();
        currentPos = 0;
        lineNumber++;
        return currentLine;
    }

    // 核心方法：处理下一个单词
    public boolean next() throws IOException {
        if (currentLine == null || currentPos >= currentLine.length()) {
            currentLine = getNextLine();
            if (currentLine == null) {
                return false; // 文件结束
            }
        }

        // 跳过空白字符
        while (currentPos < currentLine.length() && Character.isWhitespace(currentLine.charAt(currentPos))) {
            currentPos++;
        }

        if (currentPos >= currentLine.length()) {
            return next();
        }

        char c = currentLine.charAt(currentPos);

        // 处理注释
        if (c == '/') {
            if (currentPos + 1 < currentLine.length()) {
                char nextChar = currentLine.charAt(currentPos + 1);
                if (nextChar == '/') {
                    // 单行注释，跳过到行尾
                    currentPos = currentLine.length();
                    return next();
                } else if (nextChar == '*') {
                    // 多行注释，寻找 */
                    currentPos += 2;  // 跳过 /*
                    while (currentLine != null) {
                        while (currentPos < currentLine.length() && !(currentLine.charAt(currentPos) == '*' && currentPos + 1 < currentLine.length() && currentLine.charAt(currentPos + 1) == '/')) {
                            if (currentLine.charAt(currentPos) == '\n') {
                                lineNumber++;
                            }
                            currentPos++;
                        }
                        if (currentPos < currentLine.length()) {
                            currentPos += 2;  // 跳过 */
                            return next();
                        }
                        currentLine = getNextLine();  // 跨行
                    }
                    return false;
                }
            }
        }

         // 优先匹配双字符符号
        if (currentPos + 1 < currentLine.length()) {
            String potentialTwoChar = currentLine.substring(currentPos, currentPos + 2);
            if (RESERVED_WORDS.containsKey(potentialTwoChar)) {
                tokenValue = potentialTwoChar;
                tokenType = RESERVED_WORDS.get(potentialTwoChar);
                currentPos += 2;
                return true;
            }
        }

        // 匹配单字符符号
        String singleChar = String.valueOf(c);
        if (RESERVED_WORDS.containsKey(singleChar)) {
            tokenValue = singleChar;
            tokenType = RESERVED_WORDS.get(singleChar);
            currentPos++;
            return true;
        }

        // 检查非法符号
        if (c == '&') {
            errorList.add(new Error(lineNumber,ErrorType.a));  // 记录错误行号和类别码
            tokenValue = "&&";
            tokenType = RESERVED_WORDS.get("&&");
            currentPos++;
            return true;
        }
        if (c == '|') {
            errorList.add(new Error(lineNumber,ErrorType.a)); // 记录错误行号和类别码
            tokenValue = "||";
            tokenType = RESERVED_WORDS.get("||");
            currentPos++;
            return true;
        }

        // 识别保留字和标识符，优先匹配保留字
        Matcher matcher = IDENFR_PATTERN.matcher(currentLine.substring(currentPos));
        if (matcher.find() && matcher.start() == 0) {
            tokenValue = matcher.group();  // 获取当前匹配到的单词

            // 检查是否是保留字
            if (RESERVED_WORDS.containsKey(tokenValue)) {
                tokenType = RESERVED_WORDS.get(tokenValue);  // 如果是保留字，更新tokenType
            } else {
                tokenType = LexType.IDENFR;  // 如果是标识符，更新为IDENFR类型
            }

            currentPos += tokenValue.length();  // 更新当前读取的位置
            return true;
        }

        // 识别整数
        matcher = INTCON_PATTERN.matcher(currentLine.substring(currentPos));
        if (matcher.find() && matcher.start() == 0) {
            tokenValue = matcher.group();
            tokenType = LexType.INTCON;
            currentPos += tokenValue.length();
            return true;
        }

        // 识别字符串
        matcher = STRCON_PATTERN.matcher(currentLine.substring(currentPos));
        if (matcher.find() && matcher.start() == 0) {
            tokenValue = matcher.group();
            tokenType = LexType.STRCON;
            currentPos += tokenValue.length();
            return true;
        }

        // 识别字符
        matcher = CHRCON_PATTERN.matcher(currentLine.substring(currentPos));
        if (matcher.find() && matcher.start() == 0) {
            tokenValue = matcher.group();
            tokenType = LexType.CHRCON;
            currentPos += tokenValue.length();
            return true;
        }

        // 错误处理：无法识别的符号
        tokenValue = String.valueOf(c);
        tokenType = null;  // 代表错误
        currentPos++;
        return false;
    }

    public String getToken() {
        return tokenValue;
    }

    public LexType getLexType() {
        return tokenType;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    // 输出错误到文件
    public void writeErrorsToFile(String errorFilePath) throws IOException {
        try (BufferedWriter errorWriter = new BufferedWriter(new FileWriter(errorFilePath))) {
            Collections.sort(errorList, Comparator.comparingInt(Error::getLineNumber));
            for (Error error : errorList) {
                errorWriter.write(error.lineNumber + " " +error.type.toString() + "\n");
            }
        }
    }
}
