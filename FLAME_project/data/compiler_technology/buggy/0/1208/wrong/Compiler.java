import frontend.Lexer;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {

    public static void main(String[] args) {
        String path = "testfile.txt";
        try {
            String source = Files.readString(Paths.get(path));
            Lexer lexer = new Lexer(source);
            while (lexer.next());
            lexer.output();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
