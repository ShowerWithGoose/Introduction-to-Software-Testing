import Block.CompUnitBlock;
import frontend.Lexer;
import Error.*;


import Tool.*;
import frontend.Parser;

import java.io.File;

public class Compiler {


    public static void main(String[] args) {
        ErrorHandler.resetFile();
        String input = FileController.readFileToString("testfile.txt");
        System.out.println(input);
        Lexer lexer = new Lexer(input);
        lexer.analyze();

        System.out.println("=========");
        Parser parser = Parser.getInstance();
        parser.initialize(lexer.getTokenList());
        parser.analyze();
        CompUnitBlock compUnitBlock = parser.getCompUnitBlock();
        compUnitBlock.print();

        ErrorHandler.sort();
        ErrorHandler.writeToFile();
        FileController.closeAllFile();
    }
}
