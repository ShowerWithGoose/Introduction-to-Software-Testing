package frontend.error;

public class ErrorInformation {

    private int lineNumber;
    private char errorCode;

    public ErrorInformation(int lineNumber, char errorCode) {
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
