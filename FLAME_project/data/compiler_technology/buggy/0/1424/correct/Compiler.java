import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;



import frontend.Error;
import frontend.Lexer;
import frontend.Token;

public class Compiler {
    public static void main(String[] args) {
        Scanner scanner = null;
        try {
            File file = new File("testfile.txt");
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        Lexer lexer = new Lexer(scanner);
        if (lexer.run()) {
            ArrayList<Error> errors = lexer.getErrors();
            try (FileWriter writer = new FileWriter("error.txt")) {
                for (Error error : errors) {
                    writer.write(error.getLine() + " " + error.getType() + "\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            ArrayList<Token> tokens = lexer.getTokens();
            try (FileWriter writer = new FileWriter("lexer.txt")){
                for (Token token : tokens) {
                    writer.write(token.getType().toString() + " " + token.getVal() + "\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}