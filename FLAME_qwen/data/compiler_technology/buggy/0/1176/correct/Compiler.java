import java.io.*;
import frontend.Lexer;

public class Compiler {
    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        String outputFile = "lexer.txt";
        String errorFile = "error.txt";
        Lexer lexer = null;
        try {
            lexer = Lexer.getInstance();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        while(!lexer.end()){
            lexer.next();
        }

        try {
            lexer.output();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}