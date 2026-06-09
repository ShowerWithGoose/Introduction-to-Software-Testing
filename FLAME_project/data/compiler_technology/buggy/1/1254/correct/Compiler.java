import frontend.Error;
import frontend.Lexer.Lexer;
import frontend.Lexer.Token.TokensIterator;
import frontend.Parser.Parser;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String inputFile = "testfile.txt";
        String correctFile = "parser.txt";
        String errorFile = "error.txt";

        PushbackReader inputFileStream = null;
        try {
            inputFileStream = new PushbackReader(new FileReader(inputFile));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return;
        }

        ArrayList<Error> errors = Error.getErrors();

        Lexer lexer = new Lexer(inputFileStream);
        TokensIterator iterator = new TokensIterator(lexer.getTokens());

        Parser parser = new Parser(iterator);

        if (errors.isEmpty()) {
            OutputStream correctOutPut = new FileOutputStream(correctFile);
            correctOutPut.write((parser.getCompUnit().toString()).getBytes());
        } else {
            OutputStream errorOutPut = new FileOutputStream(errorFile);
            Collections.sort(errors);
            StringBuilder sb = new StringBuilder();
            for (Error error : errors) {
                sb.append(error.toString());
            }
            errorOutPut.write(sb.toString().getBytes());
        }
    }
}
