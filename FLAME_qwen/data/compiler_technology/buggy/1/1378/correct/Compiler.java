import pac.Lexer;
import pac.Parser;


import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) {
        InputStream in = System.in;
        OutputStream out, err;
        try {
            in = Files.newInputStream(Paths.get("testfile.txt"));
            out = Files.newOutputStream(Paths.get("lexer.txt"));
            err = Files.newOutputStream(Paths.get("error.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Lexer lexer = new Lexer(in);
        lexer.work();
        //lexer.print(out, err);
        try {
            out = Files.newOutputStream(Paths.get("parser.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Parser parser = new Parser(lexer.getLexer(), lexer.getLineList(),lexer.getError());
        parser.work();
        parser.print(out, err);
    }
}