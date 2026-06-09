package Analyzer.ERROR;

public class Error {
    private ErrorType errorType;
    private int col;

    public Error(ErrorType errorType, int col) {
        this.errorType = errorType;
        this.col = col;
    }

    public ErrorType getErrorType() {
        return errorType;
    }

    public void setErrorType(ErrorType errorType) {
        this.errorType = errorType;
    }

    public int getCol() {
        return col;
    }

    public void setCol(int col) {
        this.col = col;
    }
}
