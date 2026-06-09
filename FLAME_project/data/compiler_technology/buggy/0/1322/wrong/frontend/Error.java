package frontend;

public class Error {
    private int lineNumber;
    private String errorCode;

    public Error(int lineNumber, String errorCode) {
        this.lineNumber = lineNumber;
        this.errorCode = errorCode;
    }

    public String toString() {
        return lineNumber + " " + errorCode;
    }
}

