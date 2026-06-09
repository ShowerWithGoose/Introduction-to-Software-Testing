import java.io.*;
import java.util.ArrayList;

import frontend.Lexer.Lexer;
import frontend.Logger;
import frontend.Parser.Parser;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        String inputFile = "testfile.txt";
        FileReader fis = new FileReader(inputFile);
        BufferedReader bis = new BufferedReader(fis);
        Lexer lexer = new Lexer(bis);
        Parser parser = new Parser(lexer.getTokens());
        Logger logger = new Logger(parser, lexer);
        logger.printlog();
    }
}