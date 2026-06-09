package frontend.ERROR;

public class Error {
    private ErrorType errorType;
    private int row;

    public Error(ErrorType errorType, int row) {
        this.errorType = errorType;
        this.row = row;
    }

    public ErrorType getErrorType() {
        return errorType;
    }

    public int getRow() {
        return row;
    }
}
