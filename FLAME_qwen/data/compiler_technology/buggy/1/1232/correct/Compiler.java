import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import frontend.lexer.Lexer;
import frontend.lexer.Token;
import frontend.parser.Parser;
import frontend.parser.ast.CompUnit;

public class Compiler{
    public static void main(String[] args) {
        try {
            Lexer lexer = Lexer.getInstance();
            lexer.setSource(new FileReader("testfile.txt"));
            ArrayList<Token> tokens = lexer.Tokenize();
            //lexer.outputTokens(tokens);

            Parser parser = Parser.getInstance();
            parser.setTokenStream(tokens);

            CompUnit compUnit = parser.parseCompUnit();

            compUnit.output();
            compUnit.errors();

        } catch (IOException e) {
            e.printStackTrace();
        }
        
        return;
    }
}