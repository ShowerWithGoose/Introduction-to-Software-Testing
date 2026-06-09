package error_part;

import java.util.TreeSet;

public class ErrorList {
    private static TreeSet<Error> errors = new TreeSet<>();

    public static void addError(Error error) {
        errors.add(error);
    }

    public static String errorOutput() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error);
        }
        return sb.toString();
    }

    public static boolean isEmpty(){
        return errors.isEmpty();
    }
}
