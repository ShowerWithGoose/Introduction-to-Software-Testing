package fronened.Lexer;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

public class ErrorList {
    public static ArrayList<Error> errors = new ArrayList<Error>();

    public static void addError(Error error) {
        errors.add(error);
    }

    public static boolean hasErrors() {
        return errors.size() > 0;
    }

    public static void printErrors() throws IOException {
        errors.sort(Comparator.comparingInt(Error::getLine));
        FileWriter writer = new FileWriter("error.txt");
        for (Error error : errors) {
            writer.write(error.getLine() + " " + error.getType() + "\n");
        }
        writer.close();
    }
}
