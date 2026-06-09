package utils;

import error.ErrorType;
import token.TokenType;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.StringJoiner;

public class IO {
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

    public static void writeLexer(String content) throws IOException {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("lexer.txt", true))) {
            bufferedWriter.write(content+'\n');
        }
    }

    public static void writeParser(String content) throws IOException {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("parser.txt", true))) {
            bufferedWriter.write(content+'\n');
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
