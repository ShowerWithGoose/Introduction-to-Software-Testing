import frontend.SourceFileLexer;
import frontend.error.ErrorSet;
import frontend.lexer.MyLexer;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        /* input file */
        String inputFile = "testfile.txt";
        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream(inputFile);
        } catch (FileNotFoundException e) {
            System.err.println("Cannot open " + e);
        }

        /* run lexer */
        SourceFileLexer sourceFIleLexer = new SourceFileLexer(inputStream);
        MyLexer myLexer = new MyLexer(sourceFIleLexer);

        /* output token list */
        String outputFile = "lexer.txt";
        String errorFile = "error.txt";
        OutputStream outputStream;
        try {
            if (ErrorSet.getInstance().getErrors().isEmpty()) {
                outputStream = new FileOutputStream(outputFile);
                try {
                    outputStream.write(myLexer.getTokenList().toString().getBytes());
                } catch (IOException e) {
                    System.err.println("Cannot write to " + outputFile);
                }
            }else {
                outputStream = new FileOutputStream(errorFile);
                try {
                    outputStream.write(ErrorSet.getInstance().outputErrors().getBytes());
                }catch (IOException e) {
                    System.err.println("Cannot write to " + errorFile);
                }
            }
        } catch (FileNotFoundException e) {
            System.err.println("Cannot open " + e);
        }
    }
}
