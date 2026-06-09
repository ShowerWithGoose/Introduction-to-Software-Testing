package error;

import java.util.ArrayList;

public class ErrorList {
    private ArrayList<Error> errors = new ArrayList<>();

    public void addError(Error e) {
        errors.add(e);
    }

    // 检查 ErrorList 是否为空
    public boolean isEmpty() {
        return errors.isEmpty();
    }

    // 获取错误数量
    public int size() {
        return errors.size();
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
