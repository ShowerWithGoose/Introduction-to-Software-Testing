package frontend.error;

import java.util.ArrayList;

public class ErrorList {
    public static ArrayList<Error> errorList = new ArrayList<>();

    public static String printErrorList() {
        String errListString = "";
        for (Error error: errorList) {
            errListString += error.getLineNum() + " " + error.getType() + "\n";
        }
        return errListString;
    }

    public static void addErrorList(Error error) {
        errorList.add(error);
    }

    public static Boolean isEmpty() {
        return errorList.isEmpty();
    }
}
