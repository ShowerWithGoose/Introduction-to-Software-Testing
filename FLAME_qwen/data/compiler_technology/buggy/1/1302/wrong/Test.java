import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;


public class Test {
    public static void main(String[] args) {
        String[] testcaseDirs = {"testfile/A/", "testfile/B/", "testfile/C/", "testfile/error/"};
        int[] testcaseNums = {11, 6, 16, 14};
        String[] outFiles = {"symbol.txt", "symbol.txt", "symbol.txt", "error.txt"};
        for (int i = 0; i < testcaseNums.length; i++) {
            test(testcaseDirs[i], testcaseNums[i], outFiles[i]);
        }
    }

    public static void test(String dir, int num, String symbolFilePath) {
        for (int i = 1; i <= num; i++) {
            String sourceFilePath = String.format(dir + "testcase%d/testfile.txt", i);
            String targetFilePath = "testfile.txt";
            String ansFilePath = String.format(dir + "testcase%d/ans.txt", i);

            // 复制文件
            if (copyFile(sourceFilePath, targetFilePath)) {
                System.out.println("复制文件成功: " + sourceFilePath);

                // 执行 Compiler.jar
                if (executeCompiler()) {
                    System.out.println("Compiler.jar 执行成功");

                    // 比较两个文件
                    compareFiles(ansFilePath, symbolFilePath);
                } else {
                    System.out.println("执行 Compiler.jar 失败");
                }
            } else {
                System.out.println("复制文件失败: " + sourceFilePath);
            }
        }
    }

    private static boolean copyFile(String source, String target) {
        try {
            Path sourcePath = Paths.get(source);
            Path targetPath = Paths.get(target);
            Files.copy(sourcePath, targetPath, StandardCopyOption.REPLACE_EXISTING);
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

    private static boolean executeCompiler() {
        try {
            Process process = new ProcessBuilder("java", "-jar", "out/artifacts/compiler_jar/compiler.jar").inheritIO().start();
            return process.waitFor() == 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    private static void compareFiles(String ansFilePath, String symbolFilePath) {
        try {
            List<String> ansLines = Files.readAllLines(Paths.get(ansFilePath));
            List<String> symbolLines = Files.readAllLines(Paths.get(symbolFilePath));

            if (ansLines.equals(symbolLines)) {
                System.out.println("文件内容一致: " + ansFilePath + " 和 " + symbolFilePath);
            } else {
                System.out.println("文件内容不一致: " + ansFilePath + " 和 " + symbolFilePath);
                printDifferences(ansLines, symbolLines);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void printDifferences(List<String> ansLines, List<String> symbolLines) {
        int maxLines = Math.max(ansLines.size(), symbolLines.size());

        for (int i = 0; i < maxLines; i++) {
            String ansLine = i < ansLines.size() ? ansLines.get(i) : "无内容";
            String symbolLine = i < symbolLines.size() ? symbolLines.get(i) : "无内容";

            if (!ansLine.equals(symbolLine)) {
                System.out.printf("第%d行不同:\n  ans.txt: %s\n  symbol.txt: %s%n", i + 1, ansLine, symbolLine);
            }
        }
    }
}
