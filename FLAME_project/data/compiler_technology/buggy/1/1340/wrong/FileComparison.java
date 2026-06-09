import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FileComparison {

    public static void main(String[] args) {

        String file1 = "parser.txt";
        String file2 = "ans.txt";

        try {
            int differingLine = findFirstDifferingLine(file1, file2);
            if (differingLine == -1) {
                System.out.println("两个文件内容完全相同.");
            } else {
                System.out.println("首个不同的行号: " + differingLine);
            }
        } catch (IOException e) {
            System.err.println("文件读取错误: " + e.getMessage());
        }
    }

    private static int findFirstDifferingLine(String file1, String file2) throws IOException {
        try (BufferedReader reader1 = new BufferedReader(new FileReader(file1));
             BufferedReader reader2 = new BufferedReader(new FileReader(file2))) {

            String line1, line2;
            int lineNumber = 1; // 行号从 1 开始

            while ((line1 = reader1.readLine()) != null) {
                line2 = reader2.readLine();

                if (line2 == null) {
                    // 第二个文件已结束，但第一个文件还有内容
                    return lineNumber;
                }

                if (!line1.equals(line2)) {
                    return lineNumber; // 返回首个不同的行号
                }

                lineNumber++;
            }

            // 如果第一个文件结束，但第二个文件还有内容
            if (reader2.readLine() != null) {
                return lineNumber; // 这里返回的是第一个文件最后一行后的下一行号
            }
        }

        return -1; // 文件内容完全相同
    }
}
