import frontend.CompUnit;
import frontend.Lexer;

import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] argv) throws IOException {
        Lexer lexer = new Lexer();
        lexer.getFile();
        lexer.recognize();
        CompUnit compUnit = new CompUnit(lexer.getWords());
        compUnit.parseCompUnit();
        compUnit.printWords();
    }
}
