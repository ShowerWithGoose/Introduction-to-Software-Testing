public class CompError {
    private int lineNumber;

    private Character errorType;

    public CompError(int lineNumber, Character errorType) {
        this.lineNumber = lineNumber;
        this.errorType = errorType;
    }


    public int getLineNumber() {
        return lineNumber;
    }

    public void setLineNumber(int lineNumber) {
        this.lineNumber = lineNumber;
    }

    public Character getErrorType() {
        return errorType;
    }

    public void setErrorType(Character errorType) {
        this.errorType = errorType;
    }
}
