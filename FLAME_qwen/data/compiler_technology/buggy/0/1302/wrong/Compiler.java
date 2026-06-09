import frontend.Error;
import frontend.LexType;
import frontend.Lexer;
import frontend.Token;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PushbackInputStream;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String inputFile = "testfile.txt";
        String outputFile = "lexer.txt";
        String errorFile = "error.txt";
        PushbackInputStream inputStream = new PushbackInputStream(new FileInputStream(inputFile));
        Lexer lexer = new Lexer(inputStream);
        ArrayList<Token> tokens = lexer.getTokens();
        ArrayList<Error> errors = lexer.getErrors();
        if (!errors.isEmpty()) {
            try (FileWriter fw = new FileWriter(errorFile)) {
                for (Error error : errors) {
                    fw.write(error.getLineNum() + " " + error.getType() + "\n");
                }
            }
        } else {
            try (FileWriter fw = new FileWriter(outputFile)) {
                for (Token token : tokens) {
                    fw.write(token.getType() + " " + token.getValue() + "\n");
                }
            }
        }
        inputStream.close();
    }
}
