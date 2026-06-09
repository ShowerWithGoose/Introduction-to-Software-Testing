import lexer.LexicalAnalysis;
import parser.ParserAnalysis;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        LexicalAnalysis lexicalAnalysis = new LexicalAnalysis();
        lexicalAnalysis.run();
        ParserAnalysis parserAnalysis = new ParserAnalysis();
        parserAnalysis.setTokens(lexicalAnalysis.getTokens());
        parserAnalysis.run();
    }
}
