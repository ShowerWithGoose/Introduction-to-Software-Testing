package frontend;

import java.io.*;
import java.util.*;

public class Lexer {
    private List<Token> tokens = new ArrayList<>(); // 用于存储词法分析结果
    private List<String> errors = new ArrayList<>(); // 用于存储错误信息
    private int lineNumber = 1;  // 当前处理行号
    private char currentChar;  // 当前字符
    private int currentIndex = 0;  // 当前字符在字符串中的索引
    private String code;  // 输入的代码
    private int length;  // 代码的总长度

    // 初始化词法分析器，设置要分析的代码
    public Lexer(FileProcessor fileProcessor) {
        this.code = fileProcessor.getCode();  // 从FileProcessor获取代码
        this.length = code.length();
        this.currentChar = nextChar();  // 预读第一个字符
    }

    // 获取下一个字符
    private char nextChar() {
        if (currentIndex < length) {
            return code.charAt(currentIndex++);
        } else {
            return '\0';  // 文件结束符
        }
    }

    // 预读下一个字符
    private char peekChar() {
        if (currentIndex < length) {
            return code.charAt(currentIndex);
        } else {
            return '\0';  // 文件结束符
        }
    }

    // 分析代码
    public void analyze() {
        while (currentChar != '\0') {  // 直到 EOF 结束
            if (Character.isWhitespace(currentChar)) {
                if (currentChar == '\n') {
                    lineNumber++;  // 处理换行符，增加行号
                }
                currentChar = nextChar();  // 跳过空白字符
            } else if (currentChar == '"') {
                analyzeString();  // 处理字符串常量 STRCON
            } else if (currentChar == '\'') {
                analyzeChar();  // 处理字符常量 CHRCON
            } else if (Character.isLetter(currentChar)) {
                analyzeIdentifierOrKeyword();  // 处理标识符或关键字
            } else if (Character.isDigit(currentChar)) {
                analyzeNumber();  // 处理数字
            } else {
                analyzeSymbol();  // 处理符号
            }
        }
    }

    // 处理字符串常量
    private void analyzeString() {
        StringBuilder sb = new StringBuilder();
        sb.append(currentChar);  // 添加起始双引号
        currentChar = nextChar();

        while (currentChar != '"' && currentChar != '\0') {
            if (currentChar == '\\' && peekChar() == 'n') {
                sb.append("\\n");  // 处理转义字符
                nextChar();  // 跳过 'n'
            } else {
                sb.append(currentChar);
            }
            currentChar = nextChar();
        }

        if (currentChar == '"') {
            sb.append('"');  // 添加结束双引号
            tokens.add(new Token("STRCON", sb.toString(), lineNumber));
            currentChar = nextChar();  // 跳过结束双引号
        } else {
            errors.add(lineNumber + " a");  // 未闭合的字符串
        }
    }

    // 处理字符常量
    private void analyzeChar() {
        StringBuilder sb = new StringBuilder();
        sb.append(currentChar);  // 添加起始单引号
        currentChar = nextChar();

        if (currentChar == '\\' && peekChar() == 'n') {
            sb.append("\\n");  // 处理转义字符
            nextChar();  // 跳过 'n'
            currentChar = nextChar();
        } else if (currentChar != '\'' && currentChar != '\0') {
            sb.append(currentChar);
            currentChar = nextChar();
        }

        if (currentChar == '\'') {
            sb.append('\'');  // 添加结束单引号
            tokens.add(new Token("CHRCON", sb.toString(), lineNumber));
            currentChar = nextChar();  // 跳过结束单引号
        } else {
            errors.add(lineNumber + " a");  // 未闭合的字符常量
        }
    }

    // 处理标识符或关键字
    private void analyzeIdentifierOrKeyword() {
        StringBuilder sb = new StringBuilder();
        while (Character.isLetterOrDigit(currentChar) || currentChar == '_') {
            sb.append(currentChar);
            currentChar = nextChar();
        }
        String word = sb.toString();
        String tokenType = Keywords.getTokenType(word);
        tokens.add(new Token(tokenType, word, lineNumber));
    }

    // 处理数字
    private void analyzeNumber() {
        StringBuilder sb = new StringBuilder();
        while (Character.isDigit(currentChar)) {
            sb.append(currentChar);
            currentChar = nextChar();
        }
        tokens.add(new Token("INTCON", sb.toString(), lineNumber));
    }

    // 处理其他符号（如运算符，分隔符等）
    private void analyzeSymbol() {
        if (currentChar == '&' && peekChar() == '&') {
            tokens.add(new Token("AND", "&&", lineNumber));
            nextChar();  // 跳过第二个 &
            currentChar = nextChar();
        } else if (currentChar == '|' && peekChar() == '|') {
            tokens.add(new Token("OR", "||", lineNumber));
            nextChar();  // 跳过第二个 |
            currentChar = nextChar();
        } else {
            String tokenType = Keywords.getTokenType(Character.toString(currentChar));
            if (!tokenType.equals("IDENFR")) {
                tokens.add(new Token(tokenType, Character.toString(currentChar), lineNumber));
            } else {
                errors.add(lineNumber + " a");  // 非法字符
            }
            currentChar = nextChar();  // 推进到下一个字符
        }
    }

    // 获取词法分析的结果（供语法分析器使用）
    public List<Token> getTokens() {
        return tokens;
    }

    // 获取错误信息
    public List<String> getErrors() {
        return errors;
    }

    // 输出词法分析结果
    public void writeTokens(FileProcessor fileProcessor) throws IOException {
        for (Token token : tokens) {
            fileProcessor.writeByLine(token.toString());
        }
    }

    // 输出错误信息
    public void writeErrors(FileProcessor fileProcessor) throws IOException {
        for (String error : errors) {
            fileProcessor.writeByLine(error);
        }
    }
}
