package frontend.Error;

import frontend.Config;

import java.io.BufferedWriter;
import java.util.ArrayList;

import java.util.Comparator;
import java.util.TreeSet;

public class ErrorHandler {
    private final TreeSet<Error> errors;

    private final BufferedWriter errWriter = Config.ERROR_WRITER;

    public ErrorHandler() {
        this.errors = new TreeSet<>(new Comparator<Error>() {
            @Override
            public int compare(Error o1, Error o2) {
                if (o1.getLine() == o2.getLine() && o1.getType() == o2.getType()) {
                    return 0;
                }
                if (o1.getLine() < o2.getLine()) {
                    return -1;
                } else if (o1.getLine() > o2.getLine()) {
                    return 1;
                } else {
                    if (o1.getType() < o2.getType()) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        });
    }

    public void addError(char type, int line) {
        this.errors.add(new Error(type, line));
    }

    public void printErrors() {
        try {
            for (Error error : this.errors) {
                this.errWriter.write(error.getLine() + " " + error.getType() + "\n");
            }
        } catch (Exception e) {
            throw new RuntimeException("Error writing to error file");
        }
    }

}
