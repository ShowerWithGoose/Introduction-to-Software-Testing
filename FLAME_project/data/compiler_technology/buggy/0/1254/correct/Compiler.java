import frontend.Lexer;
import frontend.Token.Token;

import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String inputFile = "testfile.txt";
        String correctFile = "lexer.txt";
        String errorFile = "error.txt";

        PushbackReader inputFileStream = null;
        try {
            inputFileStream = new PushbackReader(new FileReader(inputFile));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return;
        }

        Lexer lexer = new Lexer(inputFileStream);
        ArrayList<Token> tokens = lexer.getTokens();
        ArrayList<Integer> errors = lexer.getErrors();

        if (errors.isEmpty()) {
            StringBuilder builder = new StringBuilder();
            for (Token token : tokens) {
                builder.append(token.getType().toString() + " " + token.getContent() + "\n");
            }
            OutputStream correctOutPut = new FileOutputStream(correctFile);
            correctOutPut.write(builder.toString().getBytes());
        } else {
            OutputStream errorOutPut = new FileOutputStream(errorFile);
            for (Integer lineNum : errors) {
                errorOutPut.write((lineNum.toString() + " a" + "\n").getBytes());
            }
        }
    }
}
