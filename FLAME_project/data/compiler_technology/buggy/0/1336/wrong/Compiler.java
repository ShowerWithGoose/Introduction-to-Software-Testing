import frontend.Lexer;
import frontend.Error;
import frontend.Token;
import frontend.TokenType;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) {
        try {
            BufferedReader in = new BufferedReader(new FileReader("testfile.txt"));
            BufferedWriter out = new BufferedWriter(new FileWriter("lexer.txt"));
            BufferedWriter errorOut = new BufferedWriter(new FileWriter("error.txt"));
            Lexer lexer = new Lexer(in);
            ArrayList<Token> tokens = new ArrayList<>();
            Token curToken = lexer.getNextToken();
            while (curToken.getType() != TokenType.EOF) {
                tokens.add(curToken);
                curToken = lexer.getNextToken();
            }
            ArrayList<Error> errors = lexer.getErrors();
            if (errors.isEmpty()) {
                for (Token token : tokens) {
                    out.write(token.toString() + "\n");
                }
            } else {
                for (Error error : errors) {
                    errorOut.write(error.toString() + "\n");
                }
            }
            in.close();
            out.close();
            errorOut.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
