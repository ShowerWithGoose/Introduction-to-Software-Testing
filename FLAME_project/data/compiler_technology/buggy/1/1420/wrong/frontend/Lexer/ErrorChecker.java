package frontend.Lexer;

import frontend.ErrorChecker.ErrorBlock;

import java.io.*;
import java.util.List;

public class ErrorChecker {

    private BufferedReader reader;
    private int lineNumber = 1; // 用于记录当前行号
    private boolean inBlockComment = false; // 是否处于多行注释中
    private List<ErrorBlock> errorList;  // 错误列表

    // 构造函数，传入源程序文件和错误列表
    public ErrorChecker(String inputFile, List<ErrorBlock> errorList) throws IOException {
        reader = new BufferedReader(new FileReader(inputFile));
        this.errorList = errorList;  // 将错误列表传入
    }

    // 处理错误
    public void checkErrors() throws IOException {
        String line;
        while ((line = reader.readLine()) != null) {
            processLine(line);
            lineNumber++; // 行号递增
        }
        reader.close();
    }

    // 处理每一行的错误
    private void processLine(String line) {
        StringBuilder cleanLine = new StringBuilder();
        boolean inString = false;  // 用于跳过字符串常量内的内容
        int i = 0;

        while (i < line.length()) {
            char currentChar = line.charAt(i);

            // 检查是否在多行注释中
            if (inBlockComment) {
                if (i + 1 < line.length() && currentChar == '*' && line.charAt(i + 1) == '/') {
                    inBlockComment = false;  // 多行注释结束
                    i += 2;
                } else {
                    i++;
                }
                continue;
            }

            // 检查是否进入多行注释
            if (i + 1 < line.length() && currentChar == '/' && line.charAt(i + 1) == '*') {
                inBlockComment = true;
                i += 2;
                continue;
            }

            // 检查是否为单行注释
            if (i + 1 < line.length() && currentChar == '/' && line.charAt(i + 1) == '/') {
                break;  // 跳过单行注释后的内容
            }

            // 跳过字符串内容
            if (currentChar == '"') {
                inString = !inString;
            }

            // 如果当前字符不是注释且不在字符串中，添加到 cleanLine
            if (!inBlockComment && !inString) {
                cleanLine.append(currentChar);
            }

            i++;
        }

        // 处理清理后的行
        String cleanedLine = cleanLine.toString();

        // 检查是否有不合法的逻辑与或逻辑或符号
        if (cleanedLine.contains("&") && !cleanedLine.contains("&&")) {
            // 检查到单个 &，表示有逻辑与错误
            reportError(lineNumber, "a");
        } else if (cleanedLine.contains("|") && !cleanedLine.contains("||")) {
            // 检查到单个 |，表示有逻辑或错误
            reportError(lineNumber, "a");
        }
    }

    // 将错误添加到错误列表中
    private void reportError(int lineNumber, String errorCode) {
        errorList.add(new ErrorBlock(lineNumber, errorCode));  // 创建新的 ErrorBlock 并加入到错误列表中
    }
}
