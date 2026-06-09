package error;

public class Error {
    private int lineNum;
    private String errorType;

    public Error(int lineNum, String errorType) {
        this.lineNum = lineNum;
        this.errorType = errorType;
    }

    public int getLineNum() {
        return lineNum;
    }

    public String getErrorType() {
        return errorType;
    }

    public String toString() {
        return lineNum + " " + errorType + "\n";
    }
}
