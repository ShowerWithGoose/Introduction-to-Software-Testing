package error;

import java.util.Collections;
import java.util.Set;
import java.util.TreeSet;

public class ErrorTable {
    private static final Set<Error> errors = new TreeSet<>();

    private ErrorTable() {}

    // 添加错误到错误集合
    public static void addError(Error error) {
        errors.add(error);
    }

    public static Set<Error> getErrors() {
        return Collections.unmodifiableSet(errors);
    }

    // 输出所有错误信息
    public static String output() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error.output());
        }
        return sb.toString();
    }

    // 清除所有错误，便于重置
    public static void clear() {
        errors.clear();
    }
}
