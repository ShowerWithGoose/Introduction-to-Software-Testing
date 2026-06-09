import frontend.Lexer;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Compiler {
    public static final boolean DEBUG = true;

    public static void main(String[] args) throws FileNotFoundException {
        if (DEBUG) {
            debug();
        }
    }

    private static void debug() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("./testfile.txt"));
        String source = "";
        while (scanner.hasNext()) {
            source += scanner.nextLine() + '\n';
        }
        Lexer lexer = Lexer.INSTANCE;
        ArrayList<String> output = new ArrayList<>();
        boolean ret = lexer.init(source);
        while (ret) {
            output.add(String.format("%s %s", lexer.getLexType(), lexer.getToken()));
            ret = lexer.next();
        }
        if (lexer.isError()) {
            try (PrintStream file = new PrintStream("./error.txt")) {
                for (Lexer.ErrorLog errorLog : lexer.getErrorList()) {
                    file.println(errorLog);
                }
            }
        } else {
            try (PrintStream file = new PrintStream("./lexer.txt")) {
                for (String str : output) {
                    file.println(str);
                }
            }
        }
    }
}