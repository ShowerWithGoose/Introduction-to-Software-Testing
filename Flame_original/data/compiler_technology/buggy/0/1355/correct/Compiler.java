import frontend.Lexer;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer();
        try {
            lexer.scanner();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
