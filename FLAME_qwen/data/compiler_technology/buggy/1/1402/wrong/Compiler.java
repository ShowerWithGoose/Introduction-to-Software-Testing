import frontend.Lexer;
import frontend.Parser;
import error.Error;

import java.io.IOException;

import static utils.IO.clearFiles;

public class Compiler {
    public static void main(String[] args) throws IOException {
        clearFiles("lexer.txt","error.txt","parser.txt");
        Lexer.getInstance().analyze();
        Lexer.getInstance().print_lexer_result();
        Parser.getInstance().analyze();
        Error.sortErrors();
    }
}