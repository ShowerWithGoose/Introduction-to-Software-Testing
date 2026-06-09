import error.ErrorType;
import frontend.tokenLexer.Lexer;
import frontend.tokenLexer.Token;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Compiler {
    public static void main(String[] args) throws IOException {
        String inPath = "testfile.txt";
        String outPath = "lexer.txt";
        String errorPath = "error.txt";
        FileOutputStream outputStream = new FileOutputStream(outPath);
        FileOutputStream errorPutStream = new FileOutputStream(errorPath);
        Scanner scanner = new Scanner(new FileInputStream(inPath), StandardCharsets.UTF_8);
        //System.out.println(scanner.toString());
        Lexer lexer = new Lexer(scanner);
        Token token = lexer.getNextToken();
        while (token != null) {
            if (token.getErrorType() == ErrorType.no) {
                //System.out.println(token.getTokenType().toString());
                String outString = token.getTokenType().toString() + " " + token.getToken() + "\n";
                outputStream.write(outString.getBytes(StandardCharsets.UTF_8));
            } else {
                String errorString = token.getLine() + " " + token.getErrorType().toString();
                errorPutStream.write(errorString.getBytes(StandardCharsets.UTF_8));
            }
            token = lexer.getNextToken();
        }

    }


}