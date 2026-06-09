package utils;

import error.ErrorType;
import token.TokenType;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.StringJoiner;

public class IO {

    //    public static String read(String filePath) throws IOException {
//        StringBuilder content = new StringBuilder();
//
//        // 使用 FileReader 逐字符读取
//        try (FileReader reader = new FileReader(filePath)) {
//            int character;
//            boolean lastWasCR = false;
//
//            while ((character = reader.read()) != -1) {
//                // 处理 Windows 的 \r\n 换行符，避免重复添加 \r
//                if (character == '\r') {
//                    content.append("\r");
//                    lastWasCR = true;  // 标记读取到了 \r
//                } else {
//                    if (character == '\n') {
//                        if (lastWasCR) {
//                            content.append("\n");  // 如果上一个字符是 \r，添加完整的 \r\n
//                        } else {
//                            content.append("\n");  // 如果上一个不是 \r，则添加 \n
//                        }
//                    } else {
//                        content.append((char) character);  // 普通字符直接追加
//                    }
//                    lastWasCR = false;  // 重置标记
//                }
//            }
//        }
//        return content.toString();
//    }
    public static String read(String filePath) throws IOException {
        StringBuilder content = new StringBuilder();

        try (FileReader fileReader = new FileReader(filePath)) {
            int character;
            while ((character = fileReader.read()) != -1) {
                content.append((char) character); // 按字符读取并追加到 StringBuilder
            }
        }
        return content.toString();
    }

    public static void writeError(String filePath, int lineNumber, ErrorType type) throws IOException {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(filePath, true))) {
            bufferedWriter.write(String.format("%d %s\n", lineNumber, type));
        }
    }

    public static void writeRight(String filePath, TokenType type, String content) throws IOException {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(filePath, true))) {
            bufferedWriter.write(String.format("%s %s\n", type, content));
        }
    }

    public static void clearFiles(String... filePaths) {
        for (String filePath : filePaths) {
            try (FileWriter fileWriter = new FileWriter(filePath, false)) {

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
