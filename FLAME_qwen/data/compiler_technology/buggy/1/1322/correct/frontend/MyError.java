package frontend;

public class MyError {
    private int lineNumber;
    private String errorCode;

    public MyError(int lineNumber, String errorCode) {
        this.lineNumber = lineNumber;
        this.errorCode = errorCode;
    }

    public void setLineNumber(int lineNumber) {
        this.lineNumber = lineNumber;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public void setErrorCode(String errorCode) {
        this.errorCode = errorCode;
    }

    public String getErrorCode() {
        return errorCode;
    }

    public String toString() {
        return lineNumber + " " + errorCode + "\n";
    }
}

