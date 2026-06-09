import java.io.*;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
        Lexer myLexer = new Lexer("testfile.txt");
        List<Token> tokens = myLexer.lexer();

        try (FileWriter writer = new FileWriter("lexer.txt", true)) {
            for (Token token: tokens) {
                writer.write(token.toString());
                writer.write('\n');
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}