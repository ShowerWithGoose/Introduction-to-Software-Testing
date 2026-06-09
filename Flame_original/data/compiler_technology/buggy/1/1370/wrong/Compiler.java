import java.io.FileNotFoundException;
import frontend.Lexer;
import frontend.GiveTokener;
import frontend.Parser;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        Lexer lexer = new Lexer("testfile.txt");
        GiveTokener.getInstance().giveLexer(lexer);
        Parser parser = new Parser();
        parser.parser();
    }
}