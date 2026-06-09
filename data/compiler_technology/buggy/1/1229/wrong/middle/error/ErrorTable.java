package middle.error;

import java.util.TreeSet;

public class ErrorTable {
    private ErrorTable() {}

    //private static TreeSet<Error> errors = new TreeSet<>();
    //说了一行只会有一个错误，所以可以用set
    private static TreeSet<Error> errors = new TreeSet<>();

    public static void addError(Error error) {
        errors.add(error);
    }

    public static TreeSet<Error> getErrors() {
        return errors;
    }

    public static Boolean hasError(){
        return errors.isEmpty();
    }

    public static String output() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error.output());
        }
        return sb.toString();
    }
}
