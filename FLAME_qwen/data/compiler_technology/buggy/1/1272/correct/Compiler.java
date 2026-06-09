import fronted.lexer.Lexer;
import fronted.parser.Parser;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";
        String content = null;
        try {
             content = new String(Files.readAllBytes(Paths.get(inputFileName)));
        } catch (IOException e) {
            System.err.println("Can Not Open the Input File!");
        }
        /*System.out.println("i got the input:\n");
        System.out.println(content);
        System.out.println("************\n");*/
        Lexer lexer = new Lexer(content);
        lexer.LexicalAnalyse();
        //lexer.printInformation();
        Parser parser = new Parser(lexer);
        parser.parse();
        parser.printInformation();
    }
}
