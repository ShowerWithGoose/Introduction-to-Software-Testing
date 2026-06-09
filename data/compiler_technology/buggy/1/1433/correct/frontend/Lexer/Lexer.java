package frontend.Lexer;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Lexer {
    private static Lexer instance = null;
    private String source;       // 源程序字符串
    private int curPos;      // 当前字符串位置指针
    private int lineNum;     // 当前行号
    private List<Token> tokens;     // 分析出的所有token
    private List<Token> errorTokens;
    private Map<String, TokenType> reserveWords; // 保留字表

    private Lexer() {
        this.curPos = 0;
        this.lineNum = 1;
        this.tokens = new ArrayList<>();
        this.errorTokens = new ArrayList<>();
        this.reserveWords = new HashMap<>();
        initializeReserveWords();
    }

    public static Lexer getInstance() {
        if (instance  == null) {
            instance = new Lexer();
        }
        return instance;
    }

    private void initializeReserveWords() {
        // 保留字
        reserveWords.put("main", TokenType.MAINTK);
        reserveWords.put("const", TokenType.CONSTTK);
        reserveWords.put("int", TokenType.INTTK);
        reserveWords.put("char", TokenType.CHARTK);
        reserveWords.put("void", TokenType.VOIDTK);
        reserveWords.put("if", TokenType.IFTK);
        reserveWords.put("else", TokenType.ELSETK);
        reserveWords.put("for", TokenType.FORTK);
        reserveWords.put("continue", TokenType.CONTINUETK);
        reserveWords.put("break", TokenType.BREAKTK);
        reserveWords.put("return", TokenType.RETURNTK);
        reserveWords.put("getint", TokenType.GETINTTK);
        reserveWords.put("getchar", TokenType.GETCHARTK);
        reserveWords.put("printf", TokenType.PRINTFTK);

        // 运算符和标点符号
        reserveWords.put("+", TokenType.PLUS);
        reserveWords.put("-", TokenType.MINU);
        reserveWords.put("*", TokenType.MULT);
        reserveWords.put("/", TokenType.DIV);
        reserveWords.put("%", TokenType.MOD);
        reserveWords.put("=", TokenType.ASSIGN);
        reserveWords.put("==", TokenType.EQL);
        reserveWords.put("!=", TokenType.NEQ);
        reserveWords.put("<", TokenType.LSS);
        reserveWords.put("<=", TokenType.LEQ);
        reserveWords.put(">", TokenType.GRE);
        reserveWords.put(">=", TokenType.GEQ);
        reserveWords.put("&&", TokenType.AND);
        reserveWords.put("||", TokenType.OR);
        reserveWords.put("!", TokenType.NOT);

        // 括号和其他符号
        reserveWords.put("(", TokenType.LPARENT);
        reserveWords.put(")", TokenType.RPARENT);
        reserveWords.put("[", TokenType.LBRACK);
        reserveWords.put("]", TokenType.RBRACK);
        reserveWords.put("{", TokenType.LBRACE);
        reserveWords.put("}", TokenType.RBRACE);
        reserveWords.put(";", TokenType.SEMICN);
        reserveWords.put(",", TokenType.COMMA);
    }

    // 设置输入源程序
    public void setSource(String source) {
        this.source = source;
        curPos = 0;
        lineNum = 1;
        this.tokens.clear();
    }

    public void analyze() {
        while (curPos < source.length()) {
            char currentChar = source.charAt(curPos);
            if (Character.isWhitespace(currentChar)) {
                if (currentChar == '\n') {
                    lineNum++;
                }
                curPos++;
            } else if (Character.isLetter(currentChar) || currentChar == '_') {
                handleIdentifierOrKeyword();
            } else if (Character.isDigit(currentChar)) {
                handleNumber();
            } else if (currentChar == '\'') {
                handleCharConst();
            } else if (currentChar == '\"') {
                handleStringConst();
            } else if (currentChar == '/') {
                handleCommentOrDivision();
            } else {
                handleSymbols();
            }
        }
    }

    private void handleIdentifierOrKeyword() {
        int start = curPos;
        while (curPos < source.length() && (Character.isLetterOrDigit(source.charAt(curPos)) ||
                source.charAt(curPos) == '_')) {
            curPos++;
        }
        String value = source.substring(start, curPos);
        TokenType type = reserveWords.getOrDefault(value, TokenType.IDENFR);   // 关键词匹配失败
        tokens.add(new Token(type, value, lineNum));
    }

    private void handleNumber() {
        int start = curPos;
        while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
            curPos++;
        }
        String value = source.substring(start, curPos);
        tokens.add(new Token(TokenType.INTCON, value, lineNum));
    }

    private void handleCharConst() {
        curPos++;
        if (curPos >= source.length()) {
            System.err.println("Unexpected end of input while reading character constant.");
        }

        char currentChar = source.charAt(curPos);
        String charValue = null;
        if (currentChar == '\\') {
            curPos++;
            if (curPos >= source.length()) {
                System.err.println("Unexpected end of input while reading escape character.");
            }
            switch (source.charAt(curPos)) {
                case 'a' -> charValue = "'\\a'";
                case 'b' -> charValue = "'\\b'";
                case 't' -> charValue = "'\\t'";
                case 'n' -> charValue = "'\\n'";
                case 'v' -> charValue = "'\\v'";
                case 'f' -> charValue = "'\\f'";
                case '\"' -> charValue = "'\\\"'";
                case '\'' -> charValue = "'\\''";
                case '\\' -> charValue = "'\\\\'";
                case '0' -> charValue = "'\\0'";
                default -> System.err.println("Invalid escape sequence: \\" + source.charAt(curPos));
            }
        } else {
            // 普通字符
            charValue = "'" + currentChar + "'";
        }

        curPos++; // 跳过字符
        if (curPos >= source.length() || source.charAt(curPos) != '\'') {
            System.err.println("Character constant not properly closed.");
        }
        curPos++; // 跳过结束的单引号
        tokens.add(new Token(TokenType.CHRCON, charValue, lineNum));
    }

    private void handleStringConst() {
        curPos++; // 跳过第一个双引号
        StringBuilder stringValue = new StringBuilder();

        while (curPos < source.length()) {
            char currentChar = source.charAt(curPos);

            // 检查转义字符
            if (currentChar == '\\') {
                curPos++;
                if (curPos >= source.length()) {
                    System.err.println("Unexpected end of input while reading escape sequence.");
                }
                char escapeChar = source.charAt(curPos);
                String tempChar = null;
                switch (escapeChar) {
                    case 'a' -> tempChar = "\\a";
                    case 'b' -> tempChar = "\\b";
                    case 't' -> tempChar = "\\t";
                    case 'n' -> tempChar = "\\n";
                    case 'v' -> tempChar = "\\v";
                    case 'f' -> tempChar = "\\f";
                    case '\"' -> tempChar = "\\\"";
                    case '\'' -> tempChar = "\\'";
                    case '\\' -> tempChar = "\\\\";
                    case '0' -> tempChar = "\\0";
                    default -> System.err.println("Invalid escape sequence: \\" + source.charAt(curPos));
                }
                stringValue.append(tempChar);
            } else if (currentChar == '\"') {
                // 遇到结尾的双引号
                curPos++;
                tokens.add(new Token(TokenType.STRCON, "\"" + stringValue + "\"", lineNum));
                return;
            } else {
                // 不是转义字符，直接加入字符串
                stringValue.append(currentChar);
            }
            curPos++;
        }

        // 未找到结束的双引号
        System.err.println("String constant not properly closed.");
    }

    private void handleCommentOrDivision() {
        curPos++;
        if (curPos >= source.length()) {
            tokens.add(new Token(TokenType.DIV, "/", lineNum));
            return;
        }

        if (source.charAt(curPos) == '/') {
            curPos++;
            while (curPos < source.length()) {
                if (source.charAt(curPos) == '\n') {
                    curPos++;
                    lineNum++;
                    break;
                }
                curPos++;
            }
        } else if (source.charAt(curPos) == '*') {
            curPos++;  // 跳过 '*'
            boolean isClosed = false;
            while (curPos < source.length()) {
                char curChar = source.charAt(curPos);
                if (curChar == '\n') { lineNum++; }
                if (curChar == '*') {
                    curPos++;
                    if (curPos < source.length() && source.charAt(curPos) == '/') {
                        // 结束多行注释
                        curPos++;
                        isClosed = true;
                        break;
                    }
                } else {
                    curPos++;  // 继续跳过注释中的字符
                }
            }
            if (!isClosed) {
                System.err.println("Note constant not properly closed.");
            }
        } else {
            tokens.add(new Token(TokenType.DIV, "/", lineNum));                 // 不是注释，返回除号的Token
        }
    }

    private void handleSymbols() {
        char c = source.charAt(curPos);

        String potentialTwoChar = curPos + 1 < source.length()
                ? String.valueOf(c) + String.valueOf(source.charAt(curPos + 1))
                : null;

        if (potentialTwoChar != null && reserveWords.containsKey(potentialTwoChar)) {
            // 如果匹配到双字符运算符
            curPos += 2;
            tokens.add(new Token(reserveWords.get(potentialTwoChar), potentialTwoChar, lineNum));
        } else if (reserveWords.containsKey(String.valueOf(c))) {
            // 匹配单字符符号
            curPos++;
            tokens.add(new Token(reserveWords.get(String.valueOf(c)), String.valueOf(c), lineNum));
        } else {
            curPos++;
            StringBuilder sb = new StringBuilder();
            sb.append(c);
            sb.append(c);
            tokens.add(new Token(reserveWords.get(sb.toString()), String.valueOf(c), lineNum));
            errorTokens.add(new Token(TokenType.a, String.valueOf(c), lineNum));
        }
    }

    public List<Token> getTokens() { return tokens; }

    public List<Token> getErrorTokens() { return errorTokens; }
}
