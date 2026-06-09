package frontend;

import java.util.ArrayList;

public class ErrorList {
    private ArrayList<Error> errors;

    private ErrorList() {
        this.errors = new ArrayList<>();
    }

    private static ErrorList errorList = new ErrorList();

    public static ErrorList getErrorList() {
        if (errorList == null) {
            errorList = new ErrorList();
        }
        return errorList;
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
