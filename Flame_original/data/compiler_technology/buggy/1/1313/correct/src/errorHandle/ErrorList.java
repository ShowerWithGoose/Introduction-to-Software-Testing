package src.errorHandle;

import java.util.ArrayList;
import java.util.Comparator;
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

    public void addAll(List<Error> list) { // 批量添加另一个列表的内容
        errors.addAll(list);
    }

    public List<Error> getErrors() { return this.errors; }

    public void sort() { // 按照行号优先，列号次序进行排序
        errors.sort(Comparator.comparingInt(Error::getErrorRow)
                .thenComparingInt(Error::getErrorCol));
    }

    @Override
    public String toString() { // 输出为指定格式
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) { // 注意输出时行号从1开始
            sb.append(error.getErrorRow() + 1).append(" ").append(error.getErrorType()).append("\n");
        }
        return sb.toString();
    }
}
