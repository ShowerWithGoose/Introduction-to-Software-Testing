import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import frontend.Lexer.Lexer;
import frontend.Logger;
import frontend.Parser.Parser;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        String inputFile = "testfile.txt";
        FileInputStream fis = new FileInputStream(inputFile);
        BufferedInputStream bis = new BufferedInputStream(fis);
        Lexer lexer = new Lexer(bis);
        Parser parser = new Parser(lexer.getTokens());
        Logger logger = new Logger(parser, lexer);
        logger.printlog();
    }
}