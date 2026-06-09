import frontend.Error.ErrorItem;
import frontend.Lexer;
import frontend.Token;

import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        String outputFile = "lexer.txt";
        String errorFile = "error.txt";
        try {
            InputStream inputStream = new FileInputStream(inputFile);
            OutputStream outputStream = new FileOutputStream(outputFile);
            OutputStream errorStream = new FileOutputStream(errorFile);
            Lexer lexer = new Lexer(inputStream);
            ArrayList<ErrorItem> errors = lexer.getErrorList();
            if (errors.isEmpty()) {
                ArrayList<Token> tokens = lexer.getTokenList();
                if (tokens.isEmpty()) {
                    System.err.println("No tokens found in " + inputFile);
                    return;
                }
                for (Token token : tokens) {
                    outputStream.write((token.toString() + "\n").getBytes());
                }
            } else {
                for (ErrorItem error : errors) {
                    errorStream.write((error.toString() + "\n").getBytes());
                }
            }
            inputStream.close();
            outputStream.close();
            errorStream.close();
        } catch (Exception e) {
            System.err.println("Can not open the files: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
