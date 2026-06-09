package frontend;

import java.io.BufferedWriter;
import java.util.ArrayList;

import java.io.FileWriter;
import java.util.Comparator;

public class ErrorHandler {
    private final ArrayList<Error> errors;

    private final BufferedWriter errWriter = Config.ERROR_WRITER;

    public ErrorHandler() {
        this.errors = new ArrayList<>();
    }

    public void addError(char type, int line) {
        this.errors.add(new Error(type, line));
    }

    public void printErrors() {
        errors.sort(new Comparator<Error>() {
            @Override
            public int compare(Error o1, Error o2) {
                return o1.getLine() - o2.getLine();
            }
        });
        try {
            for (Error error : this.errors) {
                this.errWriter.write(error.getLine() + " " + error.getType() + "\n");
            }
        } catch (Exception e) {
            throw new RuntimeException("Error writing to error file");
        }
    }

}
