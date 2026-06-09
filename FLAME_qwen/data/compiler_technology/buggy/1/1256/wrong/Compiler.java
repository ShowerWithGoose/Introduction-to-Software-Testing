import java.io.IOException;
import fronened.Lexer.Lexer;
import fronened.Lexer.TokenIterator;
import fronened.Parser.Parser;

public class Compiler {
    public static void main(String[] args) {
        Read read = new Read();
        try {
            read.read("testfile.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Lexer lexer = new Lexer(read.getCode());
        TokenIterator iterator = lexer.iterator();
        Parser parser = new Parser(iterator);
        parser.parse();
        try {
            parser.print();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}