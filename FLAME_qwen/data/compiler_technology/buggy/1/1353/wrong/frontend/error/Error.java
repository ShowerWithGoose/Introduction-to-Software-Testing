package frontend.error;

public class Error implements Comparable<Error> {
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
    public String getErrorCode() {
        return errorType.getErrorCode();
    }

    @Override
    public String toString() {
        return lineNum + " " + errorType.getErrorCode() + '\n';
    }

    @Override
    public int compareTo(Error o) {
        return this.lineNum - o.lineNum;
    }
}
