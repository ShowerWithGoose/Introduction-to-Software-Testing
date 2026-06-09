import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import frontend.Lexer;
import frontend.Token;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String testFilePath = "testfile.txt";
        String lexerFilePath = "lexer.txt";
        String errorFilePath = "error.txt";

        Lexer lexer = new Lexer(testFilePath, errorFilePath);

        boolean origin_output = true;
        if (origin_output) {
            if (lexer.getIsCorrect()) {
                ArrayList<Token> tokens = lexer.getTokens();
                try (BufferedWriter bw = new BufferedWriter(new FileWriter(lexerFilePath))) {
                    for (int i = 0; i < tokens.size(); i++) {
                        bw.write(tokens.get(i).getType().toString() + " " + tokens.get(i).getContent());
                        bw.newLine();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}