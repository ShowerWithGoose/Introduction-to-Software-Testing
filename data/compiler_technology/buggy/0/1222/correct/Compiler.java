import frontend.lexer.Lexer;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        Lexer lexer = Lexer.getInstance();
        try {
            lexer.initBuffer("testfile.txt", "lexer.txt", "error.txt");
            while (lexer.getsym() != null) {
            }
            lexer.showLexer();
            lexer.closeBuffer();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}