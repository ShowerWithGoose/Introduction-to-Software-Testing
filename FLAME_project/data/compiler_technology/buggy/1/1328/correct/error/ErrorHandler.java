package error;

import utils.MyIO;

import java.util.ArrayList;
import java.util.Collections;

public class ErrorHandler {
    private static ErrorHandler errorHandler = new ErrorHandler();

    public static ErrorHandler getInstance() {
        return errorHandler;
    }

    private ArrayList<Error> errors = new ArrayList<>();

    public void addError(Error newError) {
        errors.add(newError);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }

    public void printErrors() {
        Collections.sort(errors);
        for (Error error : errors) {
            MyIO.writeError(error.toString());
        }
    }
}
