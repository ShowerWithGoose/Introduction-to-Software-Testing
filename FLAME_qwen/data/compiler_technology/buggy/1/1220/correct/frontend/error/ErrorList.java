package frontend.error;

import java.util.*;

public class ErrorList {
    public static ArrayList<Error> errorList = new ArrayList<>();

    public static TreeSet<Error> set = new TreeSet<>(Comparator.comparingInt(Error::getLineNum));


    public static String printErrorList() {
        String errListString = "";
        for (Error error: errorList) {
            errListString += error.getLineNum() + " " + error.getType() + "\n";
        }
        return errListString;
    }

    public static void addErrorList(Error error) {
        set.addAll(errorList);
        set.add(error);
        errorList = new ArrayList<>(set);
    }

    public static Boolean isEmpty() {
        return errorList.isEmpty();
    }
}
