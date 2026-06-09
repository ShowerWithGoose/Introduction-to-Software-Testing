package error;

import java.util.TreeSet;

public class ErrorList {
    private static ErrorList instance = new ErrorList();
    private TreeSet<Error> errors = new TreeSet<>();

    private ErrorList() {
    }

    public static ErrorList getInstance() {
        return instance;
    }

    public void addError(Error error) {
        errors.add(error);
    }

    public static void addError(MyErrorType errorType, int line) {
        Error error = new Error(errorType, line);
        getInstance().addError(error);
    }

    public static boolean hasError() {
        return !getInstance().errors.isEmpty();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error.toString()).append("\n");
        }
        return sb.toString();
    }
}
