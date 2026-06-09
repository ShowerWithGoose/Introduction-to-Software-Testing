package frontend;

public class Error {
    private final int row_line;
    private final ErrorType errorType;

    public Error(int row_line, ErrorType errorType) {
        this.row_line = row_line;
        this.errorType = errorType;
    }

    public int getRow_line() {
        return row_line;
    }

    public ErrorType getErrorType() {
        return errorType;
    }
}
