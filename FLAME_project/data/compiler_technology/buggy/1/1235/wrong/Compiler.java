import frontend.Lexer;
import frontend.Parser;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        String inputPath = "testfile.txt";
        String outputPathTrue = "symbol.txt";
        String outputPathFalse = "error.txt";

        try {
            Lexer lexer = new Lexer(inputPath, outputPathTrue, outputPathFalse);
            lexer.analysis();
//            lexer.writeTokensToFile();
//            lexer.writeErrorsToFile();
            Parser parser  = new Parser(lexer.getTokens(), outputPathTrue, outputPathFalse);
            parser.analysis();
            parser.writeTokensToFile();
            parser.writeErrorsToFile();

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}