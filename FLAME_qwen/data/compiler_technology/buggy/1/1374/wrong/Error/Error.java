package Error;

public class Error {
    private int lineNumber;

    private ErrorType errorType;

    public Error(int lineNumber, ErrorType errorType) {
        this.lineNumber = lineNumber;
        this.errorType = errorType;
    }

    public int getLineNum() {
        return lineNumber;
    }

    public ErrorType getErrorType() {
        return errorType;
    }

    @Override
    public String toString(){
        return lineNumber + " " + errorType;
    }
}
