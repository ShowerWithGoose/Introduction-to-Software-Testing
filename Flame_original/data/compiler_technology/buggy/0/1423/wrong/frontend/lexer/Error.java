package frontend.lexer;

/**
 * @author
 * 保存错误信息（TODO: 不应该只在 Lexer 下，待重构）
 */
public class Error {
    private ErrorType errorType;
    private int lineNum;

    public Error(ErrorType errorType, int lineNum) {
        this.errorType = errorType;
        this.lineNum = lineNum;
    }

    public ErrorType getErrorType() {
        return errorType;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void setErrorType(ErrorType errorType) {
        this.errorType = errorType;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }
}
