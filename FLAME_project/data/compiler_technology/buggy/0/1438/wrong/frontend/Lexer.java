package frontend;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.*;

public class Lexer {
    private static final String[] keywords = {
            "main", "for", "const", "int", "char", "break", "continue", "if", "else","void",
            "getint", "getchar", "printf","return",
    };

    private static final Map<String, TokenType> tokenMap = new HashMap<>();

    static {
        for (String keyword : keywords) {
            tokenMap.put(keyword, TokenType.valueOf(keyword.toUpperCase() + "TK"));
        }
        tokenMap.put(";", TokenType.SEMICN);
        tokenMap.put("!", TokenType.NOT);
        tokenMap.put("*", TokenType.MULT);
        tokenMap.put(",", TokenType.COMMA);
        tokenMap.put("&&", TokenType.AND);
        tokenMap.put("/", TokenType.DIV);
        tokenMap.put("||", TokenType.OR);
        tokenMap.put("%", TokenType.MOD);
        tokenMap.put("]", TokenType.RBRACK);
        tokenMap.put("(", TokenType.LPARENT);
        tokenMap.put(")", TokenType.RPARENT);
        tokenMap.put("<", TokenType.LSS);
        tokenMap.put("[", TokenType.LBRACK);
        tokenMap.put("<=", TokenType.LEQ);
        tokenMap.put(">", TokenType.GRE);
        tokenMap.put("{", TokenType.LBRACE);
        tokenMap.put("}", TokenType.RBRACE);
        tokenMap.put("==", TokenType.EQL);
        tokenMap.put("+", TokenType.PLUS);
        tokenMap.put("-", TokenType.MINU);
        tokenMap.put("=", TokenType.ASSIGN);
        tokenMap.put(">=", TokenType.GEQ);
        tokenMap.put("!=", TokenType.NEQ);
    }

    private int curPos = 0;
    private String currentLine;
    private List<String> inputLines;
    private StringBuilder outputBuilder;
    private StringBuilder errorBuilder;
    private int lineNumber;
    private boolean isError;

    public Lexer(List<String> inputLines) {
        this.inputLines = inputLines;
        this.outputBuilder = new StringBuilder();
        this.errorBuilder = new StringBuilder();
        this.isError = false;
    }

    public void analyze() throws FileNotFoundException {
        for (lineNumber = 0; lineNumber < inputLines.size(); lineNumber++) {
            currentLine = inputLines.get(lineNumber);
            curPos = 0;
            analyzeLine();
        }

        String lexerFilePath = "lexer.txt"; // 输出文件路径
        String errorFilePath = "error.txt"; // 输出文件路径

        FileOutputStream lexerFile = new FileOutputStream(lexerFilePath);
        FileOutputStream errorFile = new FileOutputStream(errorFilePath);

        try {
            lexerFile.write(outputBuilder.toString().getBytes());
            errorFile.write(errorBuilder.toString().getBytes());
        } catch (Exception e) {
            e.printStackTrace();
        }

        //System.out.println("正确输出：");
        //System.out.println(outputBuilder.toString());

        //System.out.println("错误输出：");
        //System.out.println(errorBuilder.toString());
    }

    private void analyzeLine() {
        String token = "";
        while (curPos < currentLine.length()) {
            token = "";
            char c = currentLine.charAt(curPos++);
            char last_c;
            if (Character.isWhitespace(c)) {
                continue; // Skip whitespace
            }
            token += c;

            if (isNonDigit(c)) {
                while (curPos < currentLine.length() &&
                        (isNonDigit(currentLine.charAt(curPos)) || Character.isDigit(currentLine.charAt(curPos)))) {
                    token += currentLine.charAt(curPos++);
                }
                reserve(token); // Check keyword table
            } else if (Character.isDigit(c)) { // digit
                while (curPos < currentLine.length() && Character.isDigit(currentLine.charAt(curPos))) {
                    token += currentLine.charAt(curPos++);
                }
                outputBuilder.append(TokenType.INTCON).append(" ").append(token).append("\n");
            } else if (c == '"') { // Handle strings
                token = "";
                while (curPos < currentLine.length()) {
                    c = currentLine.charAt(curPos++);
                    last_c = currentLine.charAt(curPos - 2);
                    if (c == '"' && last_c != '\\') {
                        break;
                    } else {
                        token += c;
                    }
                }
                outputBuilder.append(TokenType.STRCON).append(" ").append("\"").append(token).append("\"\n"); // Output string
            } else if (c == '\'') { // Handle characters
                token = "";
                c = currentLine.charAt(curPos++);
                if (c == '\\') {
                    token += c;
                    c = currentLine.charAt(curPos++);
                    token += c;
                    curPos++;
                } else {
                    token += c;
                    curPos++;
                }
                outputBuilder.append(TokenType.CHRCON).append(" ").append("'").append(token).append("'\n"); // Output string
            }  else if(c == '/') { // 第一个 /
                if (curPos < currentLine.length() && currentLine.charAt(curPos) == '/') { //
                    // 第二个 /
                    c = currentLine.charAt(curPos++); //
                    token += c;
                    while (curPos < currentLine.length()) {
                        // 非换行字符
                        c = currentLine.charAt(curPos++);
                        token += c;
                    }
                    //outputBuilder.append(TokenType.NOTE).append(" ").append(token).append("\n");
                } else if (curPos < currentLine.length() && currentLine.charAt(curPos) == '*') {
                    // /* 跨行注释 用状态机判断
                    c = currentLine.charAt(curPos++);
                    token += c;
                    while (curPos < currentLine.length()) {  // 状态转换循环（直至末尾）
                        while (curPos < currentLine.length() && currentLine.charAt(curPos) != '*') {
                            // 非*字符 对应状态q5
                            c = currentLine.charAt(curPos++);
                            token += c;
                            if (curPos == currentLine.length()) {
                                lineNumber++;
                                curPos = 0;
                                currentLine = inputLines.get(lineNumber);
                            }
                        }
                        // *
                        while (curPos < currentLine.length() && currentLine.charAt(curPos) == '*') {
                            // *字符 对应状态q6 如果没有转移到q7，则会在循环中转移到q5
                            c = currentLine.charAt(curPos++);
                            token += c;
                        }
                        if (curPos < currentLine.length() && currentLine.charAt(curPos) == '/') {
                            // /字符 对应状态q7
                            c = currentLine.charAt(curPos++);
                            token += c;
                            break;
                        }
                    }
                    //outputBuilder.append(TokenType.NOTE).append(" ").append(token).append("\n");
                } else {
                    outputBuilder.append(TokenType.DIV).append(" ").append(token).append("\n");
                }
            } else if (c == '<' || c == '>' || c == '=' || c == '!') { // <= >= == !=
                if (curPos < currentLine.length() && currentLine.charAt(curPos) == '=') {
                    token += currentLine.charAt(curPos++);
                }
                outputBuilder.append(tokenMap.get(token)).append(" ").append(token).append("\n");
            } else if (c == '&' || c == '|') { // && ||
                if (curPos < currentLine.length() && currentLine.charAt(curPos) == c) {
                    token += currentLine.charAt(curPos++);
                    outputBuilder.append(tokenMap.get(token)).append(" ").append(token).append("\n");
                } else {
                    errorBuilder.append(lineNumber + 1).append(" a\n");
                }

            } else {
                TokenType tokenType = tokenMap.get(token);
                if (tokenType != null) {
                    outputBuilder.append(tokenType).append(" ").append(token).append("\n");
                } else {
                    isError = true;
                    //errorBuilder.append(lineNumber).append(" ERROR: Unrecognized token '").append(token).append("'\n"); // Output error and line number
                    errorBuilder.append(lineNumber + 1).append(" a\n");
                }
            }
        }
    }

    private boolean isNonDigit(char c) {
        return Character.isLetter(c) || c == '_';
    }

    //看看是标志符还是关键字
    private void reserve(String token) {
        TokenType tokenType = tokenMap.get(token);
        if (tokenType != null) {
            outputBuilder.append(tokenType).append(" ").append(token).append("\n");
        } else {
            outputBuilder.append(TokenType.IDENFR).append(" ").append(token).append("\n");
        }
    }
}
