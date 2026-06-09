import frontend.Lexer;

import java.io.IOException;

public class Compiler {
    public static void main(String[] argv) throws IOException {
        Lexer lexer = new Lexer();
        lexer.getFile();
//        lexer.printLine();
        lexer.recognize();
        lexer.printWords();
    }
}
