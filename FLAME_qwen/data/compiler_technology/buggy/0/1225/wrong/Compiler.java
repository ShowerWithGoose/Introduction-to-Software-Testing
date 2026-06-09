import frontend.lexer.Lexer;
import utils.Printer;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PushbackInputStream;

public class Compiler {
    public static void main(String[] args) throws IOException {
        PushbackInputStream pushbackInputStream = new PushbackInputStream(new FileInputStream("testfile.txt"), 16);
        Lexer lexer = new Lexer(pushbackInputStream);

        lexer.solve();
        Printer.solve(lexer.isCorrect());
        pushbackInputStream.close();
    }
}
