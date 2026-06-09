import java.io.IOException;
import frontend.lexer.Lexer;
import frontend.lexer.TokenStream;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer();
        TokenStream tokenStream = new TokenStream(lexer.parse());
    }
}
