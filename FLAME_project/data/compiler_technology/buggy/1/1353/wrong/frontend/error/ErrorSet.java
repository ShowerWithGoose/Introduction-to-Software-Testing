package frontend.error;

import java.util.TreeSet;

public class ErrorSet {
    private TreeSet<Error> errors;

    private ErrorSet() {
        this.errors = new TreeSet<>();
    }
    private static ErrorSet instance;
    public static synchronized ErrorSet getInstance() {
        if (instance == null) {
            instance = new ErrorSet();
        }
        return instance;
    }

    public TreeSet<Error> getErrors() {
        return errors;
    }
    public void addError(Error error) {
        errors.add(error);
    }

    public String outputErrors() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error.toString());
        }
        return sb.toString();
    }
}
