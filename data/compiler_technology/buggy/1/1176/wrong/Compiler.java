import java.io.*;
import frontend.Lexer;
import frontend.Parser;

public class Compiler {
    public static void main(String[] args) {
        Lexer lexer;
        try {
            lexer = Lexer.getInstance();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        while(!lexer.end()){
            lexer.next();
        }

        Parser parser;
        parser = Parser.getInstance();
        parser.analyze();

        try {
            parser.output();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}