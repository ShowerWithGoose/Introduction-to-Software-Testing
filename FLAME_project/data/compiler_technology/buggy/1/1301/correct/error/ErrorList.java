package error;

import java.util.TreeSet;

public class ErrorList {
    private static TreeSet<Error> errors = new TreeSet<>();

    public static void addError(Error error) {
        errors.add(error);
    }

    public static int getErrorNum() { return errors.size(); }

    public static String output() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error.output());
        }
        return sb.toString();
    }
}
