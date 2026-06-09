package frontend.error;

import java.util.ArrayList;

public class ErrorList {
    private final ArrayList<Error> errors = new ArrayList<>();
    private static ErrorList errorList;

    private ErrorList() {}

    public static ErrorList getInstance() {
        if (errorList == null) {
            errorList = new ErrorList();
        }
        return errorList;
    }

    public void addError(String type, int lineNum) {
        for (Error error : errors) {
            if (error.getLineNum() == lineNum) {
                return;
            }
        } // 一行只有一个错误
        errors.add(new Error(type, lineNum));
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }

    public boolean isEmpty() {
        return errors.isEmpty();
    }

    /**
     * 将error按照行号从小到大排序
     */
    public void sort() {
        errors.sort((a, b) -> a.getLineNum() - b.getLineNum());
    }
}
