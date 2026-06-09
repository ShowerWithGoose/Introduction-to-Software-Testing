package utils;

import java.io.*;
import java.util.ArrayList;

public class IOUtil {
    public static String readFileToString(String filePath) throws IOException {
        StringBuilder fileContent = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                fileContent.append(line).append("\n"); // 每行读取并加入到StringBuilder
            }
        }
        return fileContent.toString();
    }
    public static void writeToFile(String filePath, ArrayList<String> data) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            // 遍历ArrayList并逐行写入文件
            for (String line : data) {
                writer.write(line);
                writer.newLine();  // 写入换行符
            }
        } catch (IOException e) {
            e.printStackTrace();  // 处理IO异常
        }
    }
}
