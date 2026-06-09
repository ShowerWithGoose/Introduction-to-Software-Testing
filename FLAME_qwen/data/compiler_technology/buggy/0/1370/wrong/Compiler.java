import java.io.FileNotFoundException;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        Lexer lexer = new Lexer("testfile.txt");
        lexer.lexer();
    }
}