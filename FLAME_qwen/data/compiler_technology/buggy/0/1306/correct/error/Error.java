package error;

public class Error {
    private ErrorType errorType;
    private int line;

    public ErrorType getErrorType() {
        return errorType;
    }

    public void setErrorType(ErrorType errorType) {
        this.errorType = errorType;
    }

    public int getLine() {
        return line;
    }

    public void setLine(int line) {
        this.line = line;
    }
    public Error(ErrorType errorType, int line) {
        this.errorType = errorType;
        this.line = line;
    }
    @Override
    public String toString() {
        return this.line+" "+this.errorType.toString();
    }
}
