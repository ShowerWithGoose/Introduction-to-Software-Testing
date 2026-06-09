package frontend.lexer;

import java.util.ArrayList;

/**
 * @author
 * 错误表
 */
public class ErrorList {
    private ArrayList<Error> errors;

    public ErrorList() {
        this.errors = new ArrayList<>();
    }

    /**
     * 将错误加到错误处理表中
     * @param error 错误
     */
    public void addError(Error error) {
        this.errors.add(error);
    }

    /**
     * 格式化输出错误表信息（每个 error 的行号和类别码形式）
     * @return 单词表的格式化输出
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error.getLineNum() + " " + error.getErrorType().getTypeCode() + "\n");
        }
        return sb.toString();
    }

    /**
     * 判断错误表是否为空
     * @return 错误表是否为空
     */
    public boolean isEmpty() {
        return errors.isEmpty();
    }
}
