import frontend.Lexer;

import java.io.IOException;

public class Compiler {

    public static void main(String[] args) throws IOException {
        String sourceCode = FileIO.readTestFile();
        Lexer lexer = new Lexer(sourceCode);
        lexer.analyzeCode();
        FileIO.printLexerResult(lexer.getTokens());
        FileIO.printError(lexer.getErrors());
    }
}
