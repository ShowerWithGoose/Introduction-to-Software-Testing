import java.io.*;
import java.util.ArrayList;

import frontend.Error;
import frontend.lexer.Lexer;
import frontend.lexer.Token;
import frontend.parser.Parser;

public class Compiler {
    public static void main(String[] args) throws Exception {

        Error error = new Error();

        Lexer myLexer = new Lexer("testfile.txt", error);

        ArrayList<Token> tokenList = myLexer.lexer();

        Parser myParser = new Parser(tokenList, error);

        ArrayList<String> output = myParser.parseCompUnit();

        Boolean isCorrect = myParser.isCorrect();

        if (isCorrect) {
            try (FileWriter writer = new FileWriter("parser.txt", false)) {
                writer.write("");

                for (String string : output) {
                    writer.write(string);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            error.write2txt();
        }

    }
}