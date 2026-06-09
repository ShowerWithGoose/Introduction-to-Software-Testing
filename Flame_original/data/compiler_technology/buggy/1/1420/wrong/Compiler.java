//package Compiler;

import frontend.ErrorChecker.ErrorBlock;
import frontend.Lexer.Lexer;
import frontend.Lexer.ErrorChecker;
import frontend.Lexer.Token;
import frontend.SyntaxTree.SyntaxTreeNode;

import java.io.File;
import java.io.IOException;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import frontend.Parser.Parser;

public class Compiler {

    public static void main(String[] args) {

        boolean debugFlag = false;  // 控制是否输出词法分析结果，true 为输出，false 为不输出

        ArrayList<Token> tokens = new ArrayList<>();    // 创建词法分析生成词列表
        ArrayList<ErrorBlock> errorList = new ArrayList<>(); //创建错误列表
        // 词法分析部分
        try {
            // 定义源程序和错误文件的路径
            String sourceFile = "./testfile.txt";  // 源代码文件
            String errorFile = "./error.txt";    // 错误输出文件
            String outputFile = "./lexer.txt";   // 词法分析结果输出文件

            // 创建源代码文件
            File source = new File(sourceFile);
            if (!source.exists()) {
                source.getParentFile().mkdirs();  // 如果文件夹不存在，则创建文件夹
                source.createNewFile();  // 创建文件
            }

            // 创建错误文件
            File error = new File(errorFile);
            if (!error.exists()) {
                error.getParentFile().mkdirs();  // 如果文件夹不存在，则创建文件夹
                error.createNewFile();  // 创建文件
            }

            // 创建词法分析结果文件
            File output = new File(outputFile);
            if (!output.exists()) {
                output.getParentFile().mkdirs();  // 如果文件夹不存在，则创建文件夹
                output.createNewFile();  // 创建文件
            }

            // 调用错误处理程序，检查错误
            ErrorChecker errorChecker = new ErrorChecker(sourceFile, errorList);
            errorChecker.checkErrors();

            BufferedWriter writer = null;

            // 仅在 debugFlag 为 true 时创建 BufferedWriter
            if (debugFlag) {
                writer = new BufferedWriter(new FileWriter(outputFile));
            }

            Lexer lexer = Lexer.getInstance(sourceFile);

            while (true) {
                lexer.next();  // 每次循环都调用 next() 进行词法分析
                // 如果 currentToken 或 currentLexType 为 null，说明到达文件末尾，退出循环
                if (lexer.getToken() == null || lexer.getLexType() == null) {
                    break;
                }

                Token token = new Token();
                token.setValue(lexer.getToken());    // 设置单词值
                token.setTokenType(lexer.getLexType());   // 设置单词类型
                token.setLine(lexer.getLineNum());   // 设置行号
                tokens.add(token);

                // 如果 debugFlag 为 true，输出调试信息
                if (debugFlag) {
                    writer.write(lexer.getLexType() + " " + lexer.getToken());
                    writer.newLine();  // 写入换行符

                    // 同时输出到控制台
                    System.out.println(token.getValue() + ' ' + token.getTokenType().toString() + ' ' + token.getLineNumber());
                }
            }

            // 仅在 debugFlag 为 true 时关闭 BufferedWriter
            if (debugFlag && writer != null) {
                writer.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        // 词法分析部分到此结束，进入语法分析部分
        try {
            if (tokens.isEmpty()) {
                System.out.println("Error: No tokens available for syntax analysis.");
                return;
            }

            // 创建语法分析器，传入词法分析生成的 tokens
            Parser parser = new Parser(tokens);

            // 解析编译单元（CompUnit），即整个源程序
            SyntaxTreeNode syntaxTree = parser.parseCompUnit();

            // 检查是否出现语法错误
            if (!parser.getErrors().isEmpty()) {
                // 调用错误输出方法
                parser.transformError(errorList);
                errorList.sort(Comparator.comparingInt(ErrorBlock::getLineNumber));
                try (BufferedWriter errorWriter = new BufferedWriter(new FileWriter("./error.txt"))) {
                    for (ErrorBlock error : errorList) {
                        errorWriter.write(error.toString());
                        errorWriter.newLine();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else {
                // 如果没有错误，输出语法树
                String syntaxTreeOutputFile = "./parser.txt";
                File ParserOutput = new File(syntaxTreeOutputFile);
                if (!ParserOutput.exists()) {
                    ParserOutput.getParentFile().mkdirs();  // 如果文件夹不存在，则创建文件夹
                    ParserOutput.createNewFile();  // 创建文件
                }

                BufferedWriter syntaxTreeWriter = new BufferedWriter(new FileWriter(syntaxTreeOutputFile));
                syntaxTree.traverse(syntaxTreeWriter);  // 调用 traverse 时传入 BufferedWriter
                syntaxTreeWriter.write("<CompUnit>");
                syntaxTreeWriter.close();
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


//
////package Compiler;
//import frontend.Lexer.frontend.Lexer;
//import frontend.Lexer.ErrorChecker;
//import java.io.File;
//import java.io.IOException;
//import java.io.BufferedWriter;
//import java.io.FileWriter;
//import java.io.BufferedReader;
//import java.io.FileReader;
//import java.util.Objects;
//
//public class Compiler {
//    public static void main(String[] args) {
//        try {
//            // 定义测试用例的父目录路径
//            String parentPath = "E:/First-year-of-Junior/compile/Compile-main-code/main-code/frontend.Lexer/2024public/C";
//
//            // 指定一共有多少个testcase
//            int totalTestCases = 16;
//
//            // 遍历每个testcase文件夹
//            for (int i = 1; i <= totalTestCases; i++) {
//                String testCasePath = parentPath + "/testcase" + i;
//                String sourceFile = testCasePath + "/testfile.txt";  // 源代码文件
//                String errorFile = testCasePath + "/error.txt";      // 错误输出文件
//                String outputFile = testCasePath + "/lexer.txt";     // 词法分析结果输出文件
//                String answerFile = testCasePath + "/ans.txt";       // 正确答案文件
//
//                // 创建源代码文件
//                File source = new File(sourceFile);
//                if (!source.exists()) {
//                    source.getParentFile().mkdirs();  // 如果文件夹不存在，则创建文件夹
//                    source.createNewFile();  // 创建文件
//                }
//
//                // 创建错误文件
//                File error = new File(errorFile);
//                if (!error.exists()) {
//                    error.getParentFile().mkdirs();  // 如果文件夹不存在，则创建文件夹
//                    error.createNewFile();  // 创建文件
//                }
//
//                // 创建词法分析结果文件
//                File output = new File(outputFile);
//                if (!output.exists()) {
//                    output.getParentFile().mkdirs();  // 如果文件夹不存在，则创建文件夹
//                    output.createNewFile();  // 创建文件
//                }
//
//                // 调用错误处理程序，检查错误
//                ErrorChecker errorChecker = new ErrorChecker(sourceFile, errorFile);
//                errorChecker.checkErrors();
//
//                // 检查是否有错误输出
//                File errorOutput = new File(errorFile);
//                if (errorOutput.length() == 0) {
//
//                    // 创建 BufferedWriter 用于写入词法分析结果
//                    BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
//
//                    frontend.Lexer lexer = frontend.Lexer.getInstance(sourceFile);
//                    while (true) {
//                        lexer.next();  // 每次循环都调用 next() 进行词法分析
//
//                        // 如果 currentToken 或 currentLexType 为 null，说明到达文件末尾，退出循环
//                        if (lexer.getToken() == null || lexer.getLexType() == null) {
//                            break;
//                        }
//
//                        // 将词法分析结果写入 lexer.txt 文件
//                        writer.write(lexer.getLexType() + " " + lexer.getToken());
//                        writer.newLine();  // 写入换行符
//                    }
//
//                    // 关闭 BufferedWriter 以确保数据写入文件
//                    writer.close();
//
//                    // 对比 lexer.txt 和 ans.txt 文件内容
//                    if (compareFiles(outputFile, answerFile)) {
//                        System.out.println("testcase " + i + ": pass");
//                    } else {
//                        System.out.println("testcase " + i + ": fail");
//                    }
//                } else {
//                    System.out.println("testcase " + i + ": fail (errors in source file)");
//                }
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//    }
//
//    // 文件对比方法
//    public static boolean compareFiles(String file1Path, String file2Path) throws IOException {
//        BufferedReader file1Reader = new BufferedReader(new FileReader(file1Path));
//        BufferedReader file2Reader = new BufferedReader(new FileReader(file2Path));
//
//        String line1, line2 = null;
//        while ((line1 = file1Reader.readLine()) != null && (line2 = file2Reader.readLine()) != null) {
//            if (!Objects.equals(line1, line2)) {
//                file1Reader.close();
//                file2Reader.close();
//                return false;
//            }
//        }
//
//        // 如果其中一个文件结束了，但另一个还有内容，文件不一致
//        boolean areFilesEqual = (line1 == null && line2 == null);
//        file1Reader.close();
//        file2Reader.close();
//        return areFilesEqual;
//    }
//}
