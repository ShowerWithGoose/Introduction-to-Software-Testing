import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;

public class Compiler {

    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        try {
            Lexer lexer = new Lexer(inputFile);
            lexer.analyze();
            lexer.close();

            //语法分析
            Grammar grammar = new Grammar(lexer.getWords());
            grammar.analyze();

            //output
            ArrayList<Error> errors = new ArrayList<>();
            errors.addAll(lexer.getErrors());
            errors.addAll(grammar.getErrors());
            if (errors.isEmpty()) {
                System.setOut(new PrintStream("parser.txt"));
                for (String s : grammar.getOutStr()) {
                    System.out.printf("%s%n", s);
                }
            } else {
                Collections.sort(errors);
                System.setOut(new PrintStream("error.txt"));
                for (Error error : errors) {
                    System.out.printf("%d %c%n", error.getLineNumber(), error.getErrorCode());
                }
            }
            System.setOut(new PrintStream("parser.txt"));
            for (String s : grammar.getOutStr()) {
                System.out.printf("%s%n", s);
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
