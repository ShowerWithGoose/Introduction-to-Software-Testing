import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

import frontend.Lexer;
import frontend.Token;

public class Compiler {
    public static void main(String[] args) throws IOException {
        // 定义输入和输出文件的路径
        String testFilePath = "testfile.txt";
        String lexerFilePath = "lexer.txt";
        String errorFilePath = "error.txt";

        Lexer lexer = new Lexer(testFilePath, errorFilePath);

        if (lexer.getIsCorrect()) {
            ArrayList<Token> tokens = lexer.getTokens();
            try (BufferedWriter bw = new BufferedWriter(new FileWriter(lexerFilePath))) {
                for (int i = 0; i < tokens.size(); i++) {
                    bw.write(tokens.get(i).getType().toString() + " " + tokens.get(i).getContent());
                    //bw.write("hello");
                    bw.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            //System.out.println(tokens.size());
        }
    }
}