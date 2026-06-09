package frontend;

public class Error {
    private int lineNum;
    private ErrorType errorType;

    public Error(int lineNum, ErrorType errorType) {
        this.lineNum = lineNum;
        this.errorType = errorType;
    }

    public int getLineNum() {
        return lineNum;
    }

    public ErrorType getErrorType() {
        return errorType;
    }
}
