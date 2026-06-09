//package Compiler;
import Frontend.Lexer;
import Frontend.ErrorChecker;
import java.io.File;
import java.io.IOException;
import java.io.BufferedWriter;
import java.io.FileWriter;

public class Compiler {
    public static void main(String[] args) {
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
            ErrorChecker errorChecker = new ErrorChecker(sourceFile, errorFile);
            errorChecker.checkErrors();

            // 检查是否有错误输出
       File errorOutput = new File(errorFile);

      if (errorOutput.length() == 0) {

                // 创建 BufferedWriter 用于写入词法分析结果
                BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));

                Lexer lexer = Lexer.getInstance(sourceFile);
                while (true) {
                    lexer.next();  // 每次循环都调用 next() 进行词法分析

                    // 如果 currentToken 或 currentLexType 为 null，说明到达文件末尾，退出循环
                    if (lexer.getToken() == null || lexer.getLexType() == null) {
                        break;
                    }

                    // 将词法分析结果写入 lexer.txt 文件
                    writer.write(lexer.getLexType() + " " + lexer.getToken());
                    writer.newLine();  // 写入换行符
                }

                // 关闭 BufferedWriter 以确保数据写入文件
                writer.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


//
////package Compiler;
//import Frontend.Lexer;
//import Frontend.ErrorChecker;
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
//            String parentPath = "E:/First-year-of-Junior/compile/Compile-main-code/main-code/Lexer/2024public/C";
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
//                    Lexer lexer = Lexer.getInstance(sourceFile);
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
