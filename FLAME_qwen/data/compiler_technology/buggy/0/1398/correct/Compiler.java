import lexer.LexicalAnalysis;

import java.io.File;
import java.io.FileNotFoundException;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        LexicalAnalysis analysis = new LexicalAnalysis();
        analysis.run();
    }
}
