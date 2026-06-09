import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

import frontend.CustomCLexer;
import frontend.Errorlist;
import frontend.Parser;

public class Compiler {
    public static void main(String[] args) throws IOException{
        try {
            FileReader reader = new FileReader("testfile.txt");
            Errorlist errors = new Errorlist();
            CustomCLexer lexer = new CustomCLexer(reader, errors);
            
            PrintStream print = new PrintStream("parser.txt");
            PrintStream error = new PrintStream("error.txt");
            System.setOut(print);
            System.setErr(error);
            lexer.run();

            Parser parser = new Parser(lexer.gettokens(), errors);
            parser.compileunit();
            errors.printall();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
