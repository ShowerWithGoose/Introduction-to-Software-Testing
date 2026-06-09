package utils;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

import config.Config;

public class IOStream {
    public enum pathList{
        lexer,
        error
    }
    public static void init() throws IOException {
        for (pathList path: pathList.values()){
            if (Files.exists(Path.of(path + ".txt"))) {
                Files.delete(Path.of(path + ".txt"));
            }
        }
    }

    public static String getPath() {
        if (Config.DIY_TESTFILE == 0) {
            return "testfile.txt";
        } else {
            return String.format("../data/testfile%d.txt", Config.DIY_TESTFILE);
        }
    }

    public static String readFile() throws IOException {
        String path = getPath();
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new FileReader(path));
        String line;

        while ((line = br.readLine()) != null) {
            sb.append(line + "\n");
        }
        return sb.toString();
    }

    public static void writeLexer(String tokens) throws IOException {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("lexer.txt"))) {
            bufferedWriter.write(tokens);
        }
    }

    public static void writeError(String errors) throws IOException {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("error.txt"))) {
            bufferedWriter.write(errors);
        }
    }
}
