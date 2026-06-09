import frontend.Lexer;
import frontend.Parser;
import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        String lexerOutputFile = "lexer.txt";
        String errorOutputFile = "error.txt";
        String parserOutputFile = "parser.txt";
        clearFile(lexerOutputFile);
        clearFile(errorOutputFile);
        clearFile(parserOutputFile);
        try {
            Lexer lexer = new Lexer(inputFile);
            List<Token> tokens = lexer.analyze(lexerOutputFile, errorOutputFile);
            Parser parser = new Parser(tokens);
            parser.parse(parserOutputFile, errorOutputFile);
        } catch (IOException e) {
            System.err.println("文件读取错误: " + e.getMessage());
        }
    }
    private static void clearFile(String filename) {
        try {
            // 使用 FileWriter 覆盖文件内容
            new FileWriter(filename, false).close();
        } catch (IOException e) {
            System.err.println("无法清空文件: " + filename + " - " + e.getMessage());
        }
    }
}