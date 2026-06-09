package error;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Error {
    private char errorType;
    private int lineNum;
    
    private static List<Error> errorList = new ArrayList<>();

    public Error() {}
    public Error(char errorType, int lineNum) {
        this.errorType = errorType;
        this.lineNum = lineNum;
    }

    public static void addError(int lineNum, char errorType) {
        errorList.add(new Error(errorType, lineNum));
        sortErrors();
    }

    private static void sortErrors() {
        Collections.sort(errorList, new Comparator<Error>() {
            @Override
            public int compare(Error e1, Error e2) {
                return Integer.compare(e1.lineNum, e2.lineNum);
            }
        });
    }

    public static List<Error> getErrorList() {
        return errorList;
    }

    public char getErrorType() {
        return errorType;
    }

    public int getLineNum() {
        return lineNum;
    }
}
