import java.io.FileReader;
import java.io.IOException;
import java.util.List;

import frontend.Lexer;
import frontend.Token;

public class Compiler{
    public static void main(String[] args) {
        try {
            Lexer lexer = Lexer.getInstance();
            lexer.setSource(new FileReader("testfile.txt"));
            List<Token> tokens = lexer.Tokenize();
            lexer.outputTokens(tokens);

        } catch (IOException e) {
            e.printStackTrace();
        }
        
        return;
    }
}