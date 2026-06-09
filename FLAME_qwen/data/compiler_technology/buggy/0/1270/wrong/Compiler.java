import frontend.Lexer;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        String lexerOutputFile = "lexer.txt";
        String errorOutputFile = "error.txt";

        try {
            Lexer lexer = new Lexer(inputFile);
            lexer.analyze(lexerOutputFile, errorOutputFile);
        } catch (IOException e) {
            System.err.println("文件读取错误: " + e.getMessage());
        }
    }
}
