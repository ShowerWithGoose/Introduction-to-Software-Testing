package frontend.error;

public class Error {
    private int lineNum;
    private char errorType;
    public Error(int lineNum, char errorType) {
        this.errorType = errorType;
        this.lineNum = lineNum;
    }

    public int getLineNum() {
        return lineNum;
    }

    public char getErrorType() {
        return errorType;
    }
}
