import frontend.Lexer;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Compiler {
    public static void main(String[] args) {
        String inputName = "testfile.txt";
        String outputName = "lexer.txt";
        String errorName = "error.txt";
        InputStream inputStream = null;
        OutputStream outputStream = null;
        OutputStream errorStream = null;

        boolean ifPrint = true;
        try {
            inputStream = new FileInputStream(inputName);
            outputStream = new FileOutputStream(outputName);
            errorStream = new FileOutputStream(errorName);
            Lexer lexer = new Lexer(inputStream);
            lexer.tokenize();
            if (ifPrint) {
                if (lexer.isError()) {
                    lexer.printError(outputStream);
                } else {
                    lexer.printTokens(errorStream);
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error!!");
        } catch (IOException e) {
            System.out.println("Error!!");
        }


    }
}
