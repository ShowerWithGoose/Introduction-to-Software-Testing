package frontend;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.*;

/**
 * ErrorHandler 负责集中管理编译过程中产生的错误信息。
 */
public class ErrorHandler {
    // 使用 Set 存储错误，利用 Error 类的 equals 和 hashCode 方法去重
    private Set<Error> errors;

    /**
     * 构造函数，初始化错误集合。
     */
    public ErrorHandler() {
        this.errors = new HashSet<>();
    }

    /**
     * 添加错误信息到错误集合。
     *
     * @param lineNumber 行号
     * @param errorCode  错误代码
     */
    public void addError(int lineNumber, char errorCode) {
        errors.add(new Error(lineNumber, errorCode));
    }

    /**
     * 获取所有的错误信息集合。
     *
     * @return 错误集合
     */
    public Set<Error> getErrors() {
        return errors;
    }

    /**
     * 将错误信息按照行号和错误代码排序，并输出到指定的 Writer。
     *
     * @param writer 目标 Writer，例如文件写入器
     * @throws IOException 如果写入过程中发生错误
     */
    public void reportErrors(BufferedWriter writer) throws IOException {
        // 将 Set 转换为 List 以便排序
        List<Error> sortedErrors = new ArrayList<>(errors);
        // 按照行号和错误代码排序
        sortedErrors.sort(Comparator
                .comparingInt(Error::getLineNumber)
                .thenComparing(Error::getErrorCode));

        for (Error e : sortedErrors) {
            writer.write(e.getLineNumber() + " " + e.getErrorCode());
            writer.write(System.lineSeparator());
        }
        writer.flush();
    }

    /**
     * 判断是否存在错误。
     *
     * @return 如果存在错误返回 true，否则返回 false
     */
    public boolean hasErrors() {
        return !errors.isEmpty();
    }

    /**
     * 清空所有错误信息。
     */
    public void clearErrors() {
        errors.clear();
    }
}
