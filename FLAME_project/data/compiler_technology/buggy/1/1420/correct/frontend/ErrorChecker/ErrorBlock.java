package frontend.ErrorChecker;

public class ErrorBlock {
    private int lineNumber;  // 错误的行号
    private String errorCode;  // 错误码，例如 'i' 或 'a'

    // 构造函数
    public ErrorBlock(int lineNumber, String errorCode) {
        this.lineNumber = lineNumber;
        this.errorCode = errorCode;
    }

    // 获取错误的行号
    public int getLineNumber() {
        return lineNumber;
    }

    // 获取错误码
    public String getErrorCode() {
        return errorCode;
    }

    // 将错误信息格式化为输出字符串
    @Override
    public String toString() {
        return lineNumber + " " + errorCode;
    }
}
