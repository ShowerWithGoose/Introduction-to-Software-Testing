import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

import frontend.CustomCLexer;

public class Compiler {
    public static void main(String[] args) throws IOException{
        try {
            FileReader reader = new FileReader("testfile.txt");
            CustomCLexer lexer = new CustomCLexer(reader);
            PrintStream print = new PrintStream("lexer.txt");
            PrintStream error = new PrintStream("error.txt");
            System.setOut(print);
            System.setErr(error);
            lexer.run();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
