import frontend.Lexer;
import frontend.Parser;

import java.io.IOException;

public class Compiler {

    public static void main(String[] args) throws IOException {
        String sourceCode = FileIO.readTestFile();
        Lexer lexer = new Lexer(sourceCode);
        lexer.analyzeCode();
        FileIO.printLexerResult(lexer.getTokens());
        Parser parser = new Parser(lexer.getTokens(), lexer.getErrors());
        parser.analyzeCode();
        FileIO.printParserResult(parser.getCompUnit());
        FileIO.printError(parser.getErrors());
    }
}
