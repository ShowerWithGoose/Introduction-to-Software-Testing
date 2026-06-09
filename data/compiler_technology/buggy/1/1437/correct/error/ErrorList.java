package error;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class ErrorList {
    private static ErrorList instance;
    private List<Error> errors = new ArrayList<>();

    public static ErrorList getInstance() {
        if (instance == null) {
            instance = new ErrorList();
        }
        return instance;
    }

    public List<Error> getErrors() {
        return errors;
    }

    public void addError(Error error) {
        errors.add(error);
    }

    public void sortErrors() {
        errors.sort(Comparator.comparingInt(Error::getLine));
    }

    public String getErrorsAsString() {
        StringBuilder builder = new StringBuilder();
        for (Error error : errors) {
            builder.append(error.toString());
        }
        return builder.toString();
    }
}
