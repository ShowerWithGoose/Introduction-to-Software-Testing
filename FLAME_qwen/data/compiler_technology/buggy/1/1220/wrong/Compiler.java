import frontend.error.ErrorList;
import frontend.lexer.*;
import frontend.parser.CompUnit;
import frontend.parser.CompUnitParser;

import java.io.*;

public class Compiler {

    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        String outputFile = "parser.txt";
        String errorFile = "error.txt";
        //System.out.println("Current working directory: " + System.getProperty("user.dir"));

        InputStream inputFileStream = null;
        try {
            inputFileStream = new FileInputStream(inputFile);
        } catch (FileNotFoundException e) {
            System.err.println("Can't open file: " + inputFile);
        }

        KernelLexer kernelLexer = new KernelLexer(inputFileStream);
        TokenLexer tokenLexer = new TokenLexer(kernelLexer);
        CompUnitParser compUnitParser = new CompUnitParser(tokenLexer.getTokenList());
        CompUnit compUnit = compUnitParser.parseCompUnit();

        try {
            OutputStream outputStream = new FileOutputStream(outputFile);
            try {
                outputStream.write(compUnit.syntaxPrint().getBytes());
            } catch (IOException e) {
                System.err.println("Can not write file: " + outputFile);
            }

            if (!ErrorList.isEmpty()){
                outputStream = new FileOutputStream(errorFile);
                try {
                    outputStream.write(ErrorList.printErrorList().getBytes());
                    //System.out.println(ErrorList.printErrorList().getBytes());
                } catch (IOException e) {
                    System.err.println("Can not write file: " + errorFile);
                }
            }

        } catch (FileNotFoundException e) {
            System.err.println("Can not open file: " + outputFile + " / " + errorFile);
        }
    }
}
