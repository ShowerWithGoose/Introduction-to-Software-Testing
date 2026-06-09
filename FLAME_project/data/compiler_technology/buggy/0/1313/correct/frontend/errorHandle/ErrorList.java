package frontend.errorHandle;

import java.util.ArrayList;
import java.util.List;

/**
 * 错误信息列表
 */
public class ErrorList {

    private List<Error> errors;

    public ErrorList() {
        this.errors = new ArrayList<>();
    }

    public void add(Error error) {
        this.errors.add(error);
    }

    public List<Error> getErrors() { return this.errors; }

    @Override
    public String toString() { // 输出为指定格式
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) { // 注意输出时行号从1开始
            sb.append(error.getErrorRow() + 1).append(" ").append(error.getErrorType()).append("\n");
        }
        return sb.toString();
    }
}
