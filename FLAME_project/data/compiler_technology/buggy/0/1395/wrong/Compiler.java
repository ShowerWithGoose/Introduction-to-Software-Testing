import frontend.Error;
import frontend.Lexer;
import frontend.tokens.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Compiler {

    // 开一个全局数组errors
    private static ArrayList<Error> errors = new ArrayList<Error>();

    public static void main(String[] args) {
        // 将testfile.txt读入到sourceCode
        //System.out.println("hhh" + System.getProperty("user.dir")); // 打印当前工作目录
        String inputFilePath = "testfile.txt";
        StringBuilder sourceCode = new StringBuilder();
        try {
            List<String> lines = Files.readAllLines(Paths.get(inputFilePath));
            for (String line : lines) {
                sourceCode.append(line).append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }


        Lexer lexer = new Lexer(sourceCode.toString(), errors);
        ArrayList<Token> tokens = lexer.lex();
//        System.out.println(lexer.showLexerResult());

        if (errors.isEmpty()) {
            String filename = "lexer.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
                writer.write(lexer.showLexerResult());
                System.out.println("String written to file successfully.");
            } catch (IOException e) {
                System.err.println("An error occurred while writing to the file: " + e.getMessage());
            }
        } else {
            // 把errors输出到error.txt
            String filename = "error.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
                for (Error error : errors) {
                    writer.write(error.getLine() + " " + error.getMessage() + "\n");
                }
                System.out.println("Errors written to file successfully.");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}