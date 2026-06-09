package Lexer;

import Error.error;
import Error.errorMessage;

import java.io.*;
import java.util.ArrayList;

import IO.*;
public class LexicalAnalyzer {

    private final errorMessage errorManager;
    private KeywordManager keywordManager;

    private static ArrayList<Token> tokens = new ArrayList<>();


    public LexicalAnalyzer(errorMessage errorMessage) {
        this.keywordManager = new KeywordManager(); // 关联关键词管理
        this.errorManager = errorMessage;
    }

    // 处理操作符
    private int handleOperator(char c, char nextC, int lineNumber) {
        String token = String.valueOf(c);
        // 双字节
        if ((c == '<' || c == '>' || c == '=' || c == '!') && nextC == '=') {
            token += "=";
            tokens.add(new Token(token,  lineNumber));
            return 2;
        } else if(c == '|') {
            if (nextC == '|') {
                token += "|";
                tokens.add(new Token(token,  lineNumber));
                return 2;
            } else {
                errorMessage.addError(new error(token, lineNumber, "a"));
                tokens.add(new Token("||",  lineNumber));
                return 1;
            }
        } else if(c == '&' ) {
            if (nextC == '&') {
                token += "&";
                tokens.add(new Token(token,  lineNumber));
                return 2;
            } else {
                tokens.add(new Token("&&",  lineNumber));
                errorMessage.addError(new error(token, lineNumber, "a"));
                return 1;
            }

        } else {
            // 单字节
            tokens.add(new Token(token,  lineNumber));
            return 1;
        }
    }

    // 判断是否为标识符
    private boolean isIdentifier(String word) {
        if (!Character.isLetter(word.charAt(0)) && word.charAt(0) != '_') {
            return false;
        }
        for (int i = 1; i < word.length(); i++) {
            if (!Character.isLetterOrDigit(word.charAt(i)) && word.charAt(i) != '_') {
                return false;
            }
        }
        return true;
    }

    // 判断是否为整数常量
    private boolean isIntegerConstant(String word) {
        for (int i = 0; i < word.length(); i++) {
            if (!Character.isDigit(word.charAt(i))) return false;
        }
        return true;
    }

    // 词法分析方法
    public void analyze(IO io) throws IOException {
        BufferedReader inputFile = io.getTextfileReader();
        BufferedWriter outputFile = io.getLexerWriter();
        String buffer;
        int lineNumber = 0;
        boolean inSingleComment = false, inMultiComment = false, inString = false;

        while ((buffer = inputFile.readLine()) != null) {
            buffer += "\n";
            lineNumber++;
            int i = 0;
            while (i < buffer.length()) {
                // 结束 单行注释
                if (inSingleComment) {
                    if (buffer.charAt(i) == '\n') {
                        inSingleComment = false;
                    }
                    i++;
                    continue;
                }
                // 结束 多行注释
                if (inMultiComment) {
                    if (buffer.startsWith("*/", i)) {
                        inMultiComment = false;
//                        tokens.add(new Token.Token("*/", "ZHUSHI2_END", lineNumber));
                        i += 2;
                    } else {
                        i++;
                    }
                    continue;
                }
                // String
                if (inString) {
                    StringBuilder token = new StringBuilder("\"");
                    i++;
                    while (i < buffer.length() && buffer.charAt(i) != '"') {
                        token.append(buffer.charAt(i++));
                    }
                    if (i < buffer.length() && buffer.charAt(i) == '"') {
                        token.append('"');
                        i++;
                    }
                    tokens.add(new Token(String.valueOf(token), "STRCON", lineNumber));
                    inString = false;
                    continue;
                }
                // 跳过 空白
                if (Character.isWhitespace(buffer.charAt(i))) {
                    i++;
                    continue;
                }
                // 单行注释 开始
                if (buffer.charAt(i) == '/' && buffer.charAt(i + 1) == '/') {
                    i += 2;
                    inSingleComment = true;
//                    tokens.add(new Token.Token("//",  "ZHUSHI1", lineNumber));
                    continue;
                }
                // 多行注释 开始
                if (buffer.charAt(i) == '/' && buffer.charAt(i + 1) == '*') {
                    inMultiComment = true;
//                    tokens.add(new Token.Token("/*", "ZHUSHI2_BEGIN", lineNumber));
                    i += 2;
                    continue;
                }
                // String 开始
                if (buffer.charAt(i) == '"') {
                    inString = true;
                    continue;
                }
                // Char 开始
                if (buffer.charAt(i) == '\'') {
                    char c = buffer.charAt(i + 1);
                    if (c == '\\') {
                        c = buffer.charAt(i + 2);
                        tokens.add(new Token("'\\" + c+ "'", "CHRCON",  lineNumber));
                        i += 4;
                    } else {
                        tokens.add(new Token("'" + c + "'", "CHRCON",  lineNumber));
                        i += 3;
                    }
                    continue;
                }
                // Identifer 判断
                if (Character.isLetter(buffer.charAt(i)) || buffer.charAt(i) == '_') {
                    StringBuilder token = new StringBuilder();
                    while (i < buffer.length() && (Character.isLetterOrDigit(buffer.charAt(i)) || buffer.charAt(i) == '_')) {
                        token.append(buffer.charAt(i++));
                    }
                    String category = keywordManager.getKeywordCategory(token.toString());
                    if (category != null) {
                        tokens.add(new Token(String.valueOf(token),  lineNumber));
                    } else if (isIdentifier(token.toString())) {
                        tokens.add(new Token(String.valueOf(token), "IDENFR", lineNumber));
                    }
                    continue;
                }

                // 数字 判断
                if (Character.isDigit(buffer.charAt(i))) {
                    StringBuilder token = new StringBuilder();
                    while (i < buffer.length() && Character.isDigit(buffer.charAt(i))) {
                        token.append(buffer.charAt(i++));
                    }
                    // Int 判断
                    if (isIntegerConstant(token.toString())) {
                        tokens.add(new Token(String.valueOf(token), "INTCON",  lineNumber));
                    }
                    // Error 判断
                    else {
                        tokens.add(new Token(String.valueOf(token),  lineNumber));
                    }
                    continue;
                }
                // Operator 判断
                if (keywordManager.isSingleCharOperator(buffer.charAt(i))) {
                    int num = handleOperator(buffer.charAt(i), (i + 1 < buffer.length()) ? buffer.charAt(i + 1) : '\0', lineNumber);
                    i += num;
                    continue;
                }
            }
        }
        PrintTokens(outputFile);
        inputFile.close();
        outputFile.close();
    }


    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public static void PrintTokens(BufferedWriter output) throws IOException {
        for (Token token : tokens) {
            output.write(token.getTokenContent() + "\n");
        }
    }

    public static void PrintTokens1() {
        for (int i = 0; i < tokens.size(); i++) {
           System.out.println(i + " " + tokens.get(i).getTokenContent());
        }
    }

}
