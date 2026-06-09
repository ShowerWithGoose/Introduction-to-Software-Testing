import frontend.Lexer;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        String inputPath = "testfile.txt";
        String outputPathTrue = "lexer.txt";
        String outputPathFalse = "error.txt";

        try {
            Lexer lexer = new Lexer(inputPath, outputPathTrue, outputPathFalse);
            lexer.analysis();
            lexer.writeTokensToFile();
            lexer.writeErrorsToFile();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}