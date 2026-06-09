package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Token {
    private TokenType type;
    private String value;
    private Integer line;
    public static List<String> errorList = new ArrayList<>();
    public static void addError(int lineNum, String errorCode){
        errorList.add(lineNum + " " + errorCode);
    }

    public Token(TokenType type, String value, Integer line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }

    public TokenType getType(){
        return type;
    }

    public String getValue(){
        return value;
    }
    public Integer getLine(){
        return line;
    }

    public static List<Token> tokenize(String input, Integer lineNum) throws IOException {
        String errorOutputFile = "error.txt";
        PrintWriter errorOutput = new PrintWriter(new FileWriter(errorOutputFile, true), true);
        List<Token> tokens = new ArrayList<>();
        StringBuilder currentToken = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            char currentChar = input.charAt(i);

            // 忽略空白字符
            if (Character.isWhitespace(currentChar)) {
                continue;
            }

            // 检查单行注释
            if (currentChar == '/' && (i + 1 < input.length() && input.charAt(i + 1) == '/')) {
                // 跳过到行末
                while (i < input.length() && input.charAt(i) != '\n') {
                    i++;
                }
                continue; // 继续处理下一个字符
            }

            // 检查逻辑运算符和关系运算符
            if (currentChar == '&' && (i + 1 < input.length() && input.charAt(i + 1) == '&')) {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.AND, "&&", lineNum));

                i++; // 跳过下一个字符
                continue;
            }

            if (currentChar == '|' && (i + 1 < input.length() && input.charAt(i + 1) == '|')) {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.OR, "||", lineNum));
                i++;
                continue;
            }

            if(currentChar == '&' && i + 1 < input.length() && input.charAt(i + 1) != '&'){
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.AND, currentToken.toString(), lineNum));
                addError(lineNum + 1, "a");
                i++;
                continue;
            }if(currentChar == '|' && i + 1 < input.length() && input.charAt(i + 1) != '|'){
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.OR, currentToken.toString(), lineNum));
                addError(lineNum + 1, "a");
                i++;
                continue;
            }
            if (currentChar == '=' && (i + 1 < input.length() && input.charAt(i + 1) == '=')) {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.EQL, "==", lineNum));
                i++; // 跳过下一个字符
                continue;
            }

// 检查字符常量，包括转义字符
            if (currentChar == '\'') {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                currentToken.append(currentChar); // 添加开头的单引号
                i++;
                if (i < input.length()) {
                    char nextChar = input.charAt(i);
                    if (nextChar == '\\') { // 处理转义字符
                        currentToken.append(nextChar); // 添加转义符号
                        i++;
                        if (i < input.length()) {
                            currentToken.append(input.charAt(i)); // 添加转义后的字符
                            i++;
                        }
                    } else if (nextChar != '\'') { // 如果是普通字符
                        currentToken.append(nextChar);
                        i++;
                    }
                    if (i < input.length() && input.charAt(i) == '\'') {
                        currentToken.append(input.charAt(i)); // 添加结尾的单引号
                        tokens.add(new Token(TokenType.CHRCON, currentToken.toString(), lineNum)); // 生成字符常量token
                        currentToken.setLength(0);
                        continue;
                    }
                }
                // 如果不是正确的字符常量格式，作为错误处理
                tokens.add(new Token(TokenType.ERROR, currentToken.toString(), lineNum));
                currentToken.setLength(0);
                continue;
            }

            if (currentChar == '!' && (i + 1 < input.length() && input.charAt(i + 1) == '=')) {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.NEQ, "!=", lineNum));
                i++; // 跳过下一个字符
                continue;
            }

            if (currentChar == '>' && (i + 1 < input.length() && input.charAt(i + 1) == '=')) {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.GEQ, ">=", lineNum));
                i++; // 跳过下一个字符
                continue;
            }

            if (currentChar == '<' && (i + 1 < input.length() && input.charAt(i + 1) == '=')) {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.LEQ, "<=", lineNum));
                i++; // 跳过下一个字符
                continue;
            }

            if (currentChar == '!') {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0);
                }*/
                tokens.add(new Token(TokenType.NOT, "!", lineNum));
                continue;
            }

            // 如果是符号，立即生成 token
            if ("[]{}(),;+-*/%<>=".indexOf(currentChar) != -1) {
                /*if (!currentToken.isEmpty()) {
                    tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                    currentToken.setLength(0); // 清空 currentToken
                }*/
                switch (currentChar) {
                    case '+':
                        tokens.add(new Token(TokenType.PLUS, "+", lineNum));
                        break;
                    case '-':
                        tokens.add(new Token(TokenType.MINU, "-", lineNum));
                        break;
                    case '*':
                        tokens.add(new Token(TokenType.MULT, "*", lineNum));
                        break;
                    case '/':
                        tokens.add(new Token(TokenType.DIV, "/", lineNum));
                        break;
                    case '%':
                        tokens.add(new Token(TokenType.MOD, "%", lineNum));
                        break;
                    case '<':
                        tokens.add(new Token(TokenType.LSS, "<", lineNum));
                        break;
                    case '>':
                        tokens.add(new Token(TokenType.GRE, ">", lineNum));
                        break;
                    case '=':
                        tokens.add(new Token(TokenType.ASSIGN, "=", lineNum));
                        break;
                    default:
                        // 其他符号的处理
                        tokens.add(new Token(identify(Character.toString(currentChar)), Character.toString(currentChar), lineNum));
                        break;
                }
                continue;
            }

            if (Character.isDigit(currentChar)) {
                currentToken.append(currentChar);
                while (i + 1 < input.length() && Character.isDigit(input.charAt(i + 1))) {
                    currentToken.append(input.charAt(++i));
                }
                tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                currentToken.setLength(0); // 清空 currentToken
                continue;
            }


            // 如果是标识符或关键字，累积直到遇到非字母或非数字字符
            if (Character.isLetter(currentChar) || currentChar == '_') {
                currentToken.append(currentChar);
                while (i + 1 < input.length() && (Character.isLetterOrDigit(input.charAt(i + 1)) || input.charAt(i + 1) == '_')) {
                    currentToken.append(input.charAt(++i));
                }
                tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
                currentToken.setLength(0); // 清空 currentToken
                continue;
            }

            // 如果是字符串常量，累积直到遇到结束引号
            if (currentChar == '"') {
                currentToken.append(currentChar);
                i++;
                while (i < input.length() && input.charAt(i) != '"') {
                    currentToken.append(input.charAt(i));
                    i++;
                }
                currentToken.append('"'); // 加上结束引号
                tokens.add(new Token(TokenType.STRCON, currentToken.toString(), lineNum)); // 字符串常量
                currentToken.setLength(0); // 清空 currentToken
                continue;
            }

            // 如果未匹配到任何规则，标记为错误
            currentToken.append(currentChar);
        }

        // 如果还有剩余的 token，加入到列表中
        if (!currentToken.isEmpty()) {
            tokens.add(new Token(identify(currentToken.toString()), currentToken.toString(), lineNum));
        }
        errorOutput.close();
        return tokens;
    }




    private static TokenType identify(String word){
        switch (word){
            case "const":
                return TokenType.CONSTTK;
            case "int":
                return TokenType.INTTK;
            case "char":
                return TokenType.CHARTK;
            case "void":
                return TokenType.VOIDTK;
            case "break":
                return TokenType.BREAKTK;
            case "continue":
                return TokenType.CONTINUETK;
            case "if":
                return TokenType.IFTK;
            case "else":
                return TokenType.ELSETK;
            case "for":
                return TokenType.FORTK;
            case "main":
                return TokenType.MAINTK;
            case "return":
                return TokenType.RETURNTK;
            case "getint":
                return TokenType.GETINTTK;
            case "getchar":
                return TokenType.GETCHARTK;
            case "printf":
                return TokenType.PRINTFTK;
            // 符号和运算符
            case "+":
                return TokenType.PLUS;
            case "-":
                return TokenType.MINU;
            case "*":
                return TokenType.MULT;
            case "/":
                return TokenType.DIV;
            case "%":
                return TokenType.MOD;
            case "&&":
                return TokenType.AND;
            case "||":
                return TokenType.OR;
            case "!":
                return TokenType.NOT;
            case "==":
                return TokenType.EQL;
            case "!=":
                return TokenType.NEQ;
            case "<":
                return TokenType.LSS;
            case "<=":
                return TokenType.LEQ;
            case ">":
                return TokenType.GRE;
            case ">=":
                return TokenType.GEQ;
            case "=":
                return TokenType.ASSIGN;
            // 其他符号
            case ";":
                return TokenType.SEMICN;
            case ",":
                return TokenType.COMMA;
            case "(":
                return TokenType.LPARENT;
            case ")":
                return TokenType.RPARENT;
            case "{":
                return TokenType.LBRACE;
            case "}":
                return TokenType.RBRACE;
            case "[":
                return TokenType.LBRACK;
            case "]":
                return TokenType.RBRACK;
        }
        try {
            BigInteger value = new BigInteger(word);
            // 检查值是否在 int 范围内
            if (value.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) >= 0 &&
                    value.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) <= 1) {
                return TokenType.INTCON; // 在 int 范围内
            }
        } catch (NumberFormatException e) {
            // 不是有效的数字
        }


        if (word.matches("[a-zA-Z_][a-zA-Z0-9_]*")) {
            return TokenType.IDENFR; // 识别为标识符
        }

        // 默认返回错误类型
        return TokenType.ERROR; // 默认为错误
    }
}
