package frontend;

import java.util.ArrayList;

public class ErrorList {
    private static ArrayList<Error> errorList = new ArrayList<>();

    public static void addError(Error error) {
        errorList.add(error);
    }

    public static ArrayList<Error> getErrorList() {
        return errorList; // 获取错误列表
    }
}
