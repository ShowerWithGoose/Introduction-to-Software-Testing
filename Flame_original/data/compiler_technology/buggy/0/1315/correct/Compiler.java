import java.io.*;
import java.util.*;

public class Compiler {

    private BufferedReader reader;
    private PrintWriter tokenWriter;
    private PrintWriter errorWriter;
    private int lineNum;
    private boolean isInMultiLineComment;
    private boolean hasErrors; // 用于标识当前程序是否存在错误
    private static final Set<String> keywords = new HashSet<>(Arrays.asList(
        "const", "int", "char", "void", "main", "if", "else", "for", "while", 
        "break", "continue", "return", "printf", "scanf", "getint", "getchar"
    ));

    public Compiler(String inputFile, String tokenFile, String errorFile) throws IOException {
        reader = new BufferedReader(new FileReader(inputFile));
        tokenWriter = new PrintWriter(new FileWriter(tokenFile));
        errorWriter = new PrintWriter(new FileWriter(errorFile));
        lineNum = 1;
        isInMultiLineComment = false;
        hasErrors = false; // 初始化错误状态为无
    }

    public void analyze() throws IOException {
        String line;
        while ((line = reader.readLine()) != null) {
            processLine(line);
            lineNum++;
        }
        reader.close();
        tokenWriter.close();
        errorWriter.close();
    }

    private void processLine(String line) {
        int i = 0;
        while (i < line.length()) {
            // 如果当前处于多行注释中，继续查找结束符 "*/"
            if (isInMultiLineComment) {
                int endCommentIndex = line.indexOf("*/", i);
                if (endCommentIndex != -1) {
                    isInMultiLineComment = false;
                    i = endCommentIndex + 2; // 跳过 "*/"
                } else {
                    return; // 整行都在注释中，跳过处理
                }
            }
            if (i >= line.length()) {
                break; // 防止访问超出范围
            }
            char c = line.charAt(i);

            // 处理单行注释 "//"
            if (i + 1 < line.length() && c == '/' && line.charAt(i + 1) == '/') {
                break; // 跳过此行剩余部分
            }

            // 处理多行注释 "/*"
            if (i + 1 < line.length() && c == '/' && line.charAt(i + 1) == '*') {
                isInMultiLineComment = true;
                i += 2; // 跳过 "/*"
                continue;
            }

            // 跳过空白符
            if (Character.isWhitespace(c)) {
                i++;
                continue;
            }

            // 处理标识符和关键字
            if (Character.isLetter(c) || c == '_') {
                int start = i;
                while (i < line.length() && (Character.isLetterOrDigit(line.charAt(i)) || line.charAt(i) == '_')) {
                    i++;
                }
                String token = line.substring(start, i);
                processIdentifierOrKeyword(token);
            }
            
            // 处理字符串常量
            else if (c == '"') {
                i = processStringConstant(line, i);
            }
            // 处理字符常量
            else if (c == '\'') {
                i = processCharConstant(line, i);
            }
            // 处理数字常量
            else if (Character.isDigit(c)) {
                int start = i;
                while (i < line.length() && Character.isDigit(line.charAt(i))) {
                    i++;
                }
                String token = line.substring(start, i);
                tokenWriter.println("INTCON " + token); // 记录整数常量
            }
            // 处理操作符和符号
            else {
                i = processOperator(line, i);
            }
        }
    }

    private int processStringConstant(String line, int i) {
        int start = i;
        i++; // 跳过起始的引号
        StringBuilder strConst = new StringBuilder();
        boolean validString = true;

        while (i < line.length() && line.charAt(i) != '"') {
            char c = line.charAt(i);
            if (c == '\\') { // 处理转义字符
                if (i + 1 < line.length()) {
                    char next = line.charAt(i + 1);
                    // if (next == '0') {
                        strConst.append('\\').append(next);
                        i += 2;
                    // } else {
                    //     errorWriter.println(lineNum + " a"); // 非法转义字符
                    //     validString = false;
                    //     hasErrors = true; // 标记有错误
                    //     break;
                    // }
                }
            } else {
                strConst.append(c);
                i++;
            }
        }

        if (i < line.length() && line.charAt(i) == '"') {
            i++; // 跳过结束引号
            if (validString) {
                tokenWriter.println("STRCON " + "\"" + strConst.toString() + "\"");
            }
        } else {
            errorWriter.println(lineNum + " a"); // 未闭合的字符串
            hasErrors = true; // 标记有错误
        }
        return i;
    }

    private int processCharConstant(String line, int i) {
        int start = i;
        i++; // 跳过起始的单引号
        StringBuilder charConst = new StringBuilder();

        // 检查字符常量内容
        if (i < line.length() && line.charAt(i) != '\'') {
            char c = line.charAt(i);
            if (c == '\\') { // 处理转义字符
                if (i + 1 < line.length()) {
                    char next = line.charAt(i + 1);
                    // if (next == '0') {
                        charConst.append('\\').append(next);
                        i += 2;
                    // } else {
                    //     errorWriter.println(lineNum + " a"); // 非法转义字符
                    //     hasErrors = true; // 标记有错误
                    //     return i; // 返回，不输出字符常量
                    // }
                }
            } else {
                charConst.append(c);
                i++;
            }
        }

        if (i < line.length() && line.charAt(i) == '\'') {
            i++; // 跳过结束的单引号
            tokenWriter.println("CHRCON '" + charConst.toString() + "'");
        } else {
            errorWriter.println(lineNum + " a"); // 未闭合的字符常量
            hasErrors = true; // 标记有错误
        }
        return i;
    }

    private int processOperator(String line, int i) {
        char c = line.charAt(i);
        switch (c) {
            case '+': tokenWriter.println("PLUS +"); return i + 1;
            case '-': tokenWriter.println("MINU -"); return i + 1;
            case '*': tokenWriter.println("MULT *"); return i + 1;
            case '/': 
                if (i + 1 < line.length() && line.charAt(i + 1) == '/') {
                    return line.length(); // 单行注释，跳过此行剩余部分
                } else if (i + 1 < line.length() && line.charAt(i + 1) == '*') {
                    isInMultiLineComment = true;
                    return i + 2;
                } else {
                    tokenWriter.println("DIV /");
                    return i + 1;
                }
            case '%': tokenWriter.println("MOD %"); return i + 1; // 处理模运算符
            case '&': 
                if (i + 1 < line.length() && line.charAt(i + 1) == '&') {
                    tokenWriter.println("AND &&");
                    return i + 2;
                } else {
                    errorWriter.println(lineNum + " a");
                    hasErrors = true; // 标记有错误
                    return i + 1;
                }
            case '|': 
                if (i + 1 < line.length() && line.charAt(i + 1) == '|') {
                    tokenWriter.println("OR ||");
                    return i + 2;
                } else {
                    errorWriter.println(lineNum + " a");
                    hasErrors = true; // 标记有错误
                    return i + 1;
                }
            case '<': 
                if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                    tokenWriter.println("LEQ <=");
                    return i + 2;
                } else {
                    tokenWriter.println("LSS <");
                    return i + 1;
                }
            case '>': 
                if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                    tokenWriter.println("GEQ >=");
                    return i + 2;
                } else {
                    tokenWriter.println("GRE >");
                    return i + 1;
                }
            case '=': 
                if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                    tokenWriter.println("EQL ==");
                    return i + 2;
                } else {
                    tokenWriter.println("ASSIGN =");
                    return i + 1;
                }
            case '!': 
                if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                    tokenWriter.println("NEQ !=");
                    return i + 2;
                } else {
                    tokenWriter.println("NOT !");
                    return i + 1;
                }
            case ';': tokenWriter.println("SEMICN ;"); return i + 1;
            case ',': tokenWriter.println("COMMA ,"); return i + 1;
            case '(': tokenWriter.println("LPARENT ("); return i + 1;
            case ')': tokenWriter.println("RPARENT )"); return i + 1;
            case '[': tokenWriter.println("LBRACK ["); return i + 1;
            case ']': tokenWriter.println("RBRACK ]"); return i + 1;
            case '{': tokenWriter.println("LBRACE {"); return i + 1;
            case '}': tokenWriter.println("RBRACE }"); return i + 1;
            default:
                errorWriter.println(lineNum + " a");
                hasErrors = true; // 标记有错误
                return i + 1;
        }
    }

    private void processIdentifierOrKeyword(String token) {
        if (keywords.contains(token)) {
            tokenWriter.println(token.toUpperCase()+"TK" + " " + token);
        } else {
            tokenWriter.println("IDENFR " + token);
        }
    }

    public static void main(String[] args) throws IOException {
        Compiler lexer = new Compiler("testfile.txt", "lexer.txt", "error.txt");
        lexer.analyze();
        
    }
}
