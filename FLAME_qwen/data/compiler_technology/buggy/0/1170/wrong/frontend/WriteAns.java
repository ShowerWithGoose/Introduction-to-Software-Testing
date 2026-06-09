package frontend;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import frontend.Lexer.Token;;

public class WriteAns {
    private static String lexerfile = "lexer.txt";

    public static void WriteAnswer(List<Token> tokens) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(lexerfile))) {
            for (Token token : tokens) {
                bw.write(token.toString());
            }
        } catch (IOException e) {
            System.err.println("could not open + " + lexerfile);
        }
    }
}