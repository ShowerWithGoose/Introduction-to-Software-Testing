import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;


import frontend.*;
import frontend.Error;

public class Compiler {
    public static void main(String[] args) {
        ArrayList<Error> errors = new ArrayList<>();
        Scanner scanner = null;
        try {
            File file = new File("testfile.txt");
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        Lexer lexer = new Lexer(scanner, errors);
        lexer.run();
        if (errors.isEmpty()) {

            try (FileWriter writer = new FileWriter("lexer.txt")){
                for (Token token : lexer.getTokens()) {
                    writer.write(token.getType() + " " + token.getVal() + "\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        Parser parser = new Parser(lexer.getTokens(), errors);
        Node node = parser.run();
        if (errors.isEmpty()) {
            ArrayList<String> output = new ArrayList<>();
            node.print(output);
            try (FileWriter writer = new FileWriter("parser.txt")){
                for (String s : output) {
                    writer.write(s);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            try (FileWriter writer = new FileWriter("error.txt")) {
                Comparator<Error> comparator = new MyComparator();
                errors.sort(comparator);
                for (Error error : errors) {
                    writer.write(error.getLine() + " " + error.getType() + "\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}