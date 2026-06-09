import frontend.Lexer;

import java.io.IOException;

import static utils.IO.clearFiles;

public class Compiler {
    public static void main(String[] args) throws IOException {
        clearFiles("lexer.txt","error.txt");
        Lexer lexer = new Lexer();
        lexer.analyze();
        lexer.print_lexer_result();
    }
}