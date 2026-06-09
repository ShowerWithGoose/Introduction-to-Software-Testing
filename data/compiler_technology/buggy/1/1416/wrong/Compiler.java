import frontend.Lexer;
import frontend.Parser;
import frontend.Visitor;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        String FILENAME = "testfile.txt";
        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream(FILENAME);
        } catch (FileNotFoundException e) {
            System.err.println("Can't read " + e.getMessage());
            return;
        }
        Lexer lexer = new Lexer(inputStream);
        lexer.deal();

        Parser parser = new Parser(lexer.getTokens());
        parser.CompUnit();

        Visitor visitor = new Visitor(parser.getMainTree(), parser.getErrors());
        visitor.visitCompUnit();
        visitor.Output();
    }
}