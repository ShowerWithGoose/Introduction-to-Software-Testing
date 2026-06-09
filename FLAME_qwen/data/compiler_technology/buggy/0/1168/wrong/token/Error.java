package token;

public class Error {
    private int lineNumber;
    private String errorType;

    public Error(int lineNumber, String errorType) {
        this.lineNumber = lineNumber;
        this.errorType = errorType;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public String getErrorType() {
        return errorType;
    }
}