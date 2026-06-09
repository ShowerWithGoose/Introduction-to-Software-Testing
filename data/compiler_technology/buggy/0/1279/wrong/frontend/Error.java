package frontend;

public class Error {
    private int lineNumber;
    private char errorCode;

    public Error(int lineNumber, char errorCode) {
        this.lineNumber = lineNumber;
        this.errorCode = errorCode;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public char getErrorCode() {
        return errorCode;
    }
}
