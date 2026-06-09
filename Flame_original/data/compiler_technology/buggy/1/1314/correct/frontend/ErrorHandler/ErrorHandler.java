package frontend.ErrorHandler;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ErrorHandler {
    private static ErrorHandler instance;
    private ArrayList<Error> errorList;

    private ErrorHandler() {
        errorList = new ArrayList<>();
    }

    public static ErrorHandler getInstance() {
        if (instance == null) {
            instance = new ErrorHandler();
        }
        return instance;
    }

    public void addError(Error error) {
        errorList.add(error);
    }

    public ArrayList<Error> getErrors() {
        return errorList;
    }
    public void printErrors() {
        for (Error error : errorList) {
            System.out.println(error);
        }
    }
    public void sortErrorsByLine() {
        errorList.sort(Comparator.comparingInt(Error::getLineNum));
    }
}
