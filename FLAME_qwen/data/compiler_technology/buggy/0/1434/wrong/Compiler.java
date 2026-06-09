import java.io.IOException;
import frontend.Lexer;
public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer();
        lexer.getTokenList();
    }
}
