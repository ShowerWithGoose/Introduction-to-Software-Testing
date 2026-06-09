import frontend.Lexer;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        Lexer lexer = Lexer.getInstance();
        try {
            lexer.lexicalAnalysis();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}