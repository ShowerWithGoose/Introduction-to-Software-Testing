package error;

import java.io.*;
import java.util.*;

public class Error {
    public static void error(int lineNumber, String errorType) throws IOException {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("error.txt", true))) {
            bufferedWriter.write(String.format("%d %s\n", lineNumber, errorType));
        }
    }

    public static void sortErrors() throws IOException {
        File errorFile = new File("error.txt");
        if(errorFile.exists()){
            // 用于存储文件中的所有错误信息，使用 Set 去重
            Set<String> errors = new HashSet<>();

            // 读取文件内容
            try (BufferedReader reader = new BufferedReader(new FileReader("error.txt"))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    errors.add(line);
                }
            }

            // 将 Set 转换成 List 并按照 lineNumber 对错误信息进行排序
            List<String> sortedErrors = new ArrayList<>(errors);
            sortedErrors.sort(Comparator.comparingInt(Error::extractLineNumber));

            // 覆盖写入排序后的内容到文件中
            try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
                for (String error : sortedErrors) {
                    writer.write(error);
                    writer.newLine();
                }
            }
        }
    }

    private static int extractLineNumber(String error) {
        String[] parts = error.split(" ");
        return Integer.parseInt(parts[0]);
    }
}
