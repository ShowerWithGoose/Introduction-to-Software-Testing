package error;

import java.util.ArrayList;

public class ErrorSave {
    private static ArrayList<Error> errors = new ArrayList<>();

    public static ArrayList<Error> getErrors() {
        return errors;
    }

    public static void setErrors(ArrayList<Error> errors) {
        ErrorSave.errors = errors;
    }
}
