import frontend.Lexer;
import frontend.Parser;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) {
        String filePath = "testfile.txt";
        try {
            String content = new String(Files.readAllBytes(Paths.get(filePath)));
            // System.out.println(content);
            Lexer lexer = new Lexer(content);
            lexer.lexicalAnalysis();
            Parser parser = new Parser(lexer.getTokens(), lexer);
            parser.syntaxAnalysis();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
