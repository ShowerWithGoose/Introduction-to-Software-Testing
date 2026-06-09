import frontend.Lexer;

import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) throws Exception {
        String text = new String(Files.readAllBytes(Paths.get("testfile.txt")));
        Lexer lexer = new Lexer(text);
        lexer.printTokens();
    }
}
