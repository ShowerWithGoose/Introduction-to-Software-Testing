package error;

import utils.InOut;
import utils.Tools;

import java.util.ArrayList;

public class ErrorHandler {
    public static final ErrorHandler ERROR_HANDLER = new ErrorHandler();
    private final ArrayList<Error> errorList;

    private ErrorHandler() {
        errorList = new ArrayList<>();
    }

    public void addError(Error error) {
        errorList.add(error);
    }

    public void writeErrors() {
        if (!errorList.isEmpty()) {
            InOut.writeError(Tools.arrayListToString(errorList));
        }
    }
}
