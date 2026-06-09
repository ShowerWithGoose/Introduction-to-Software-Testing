package error;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

import static utils.IO.writeError;

public class Error {
    public static void error(int lineNumber, ErrorType type) throws IOException {
        writeError("error.txt",lineNumber, type);
    }

    public static void sortErrors() throws IOException {
        // 用于存储文件中的所有错误信息
        List<String> errors = new ArrayList<>();
        // 读取文件内容
        try (BufferedReader reader = new BufferedReader(new FileReader("error.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                errors.add(line);
            }
        }
        // 按照 lineNumber 对错误信息进行排序
        errors.sort(Comparator.comparingInt(Error::extractLineNumber));
        // 覆盖写入排序后的内容到文件中
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
            for (String error : errors) {
                writer.write(error);
                writer.newLine();
            }
        }
    }

    private static int extractLineNumber(String error) {
        String[] parts = error.split(" ");
        return Integer.parseInt(parts[0]);
    }
}
