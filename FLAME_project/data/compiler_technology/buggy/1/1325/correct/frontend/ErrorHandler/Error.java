package frontend.ErrorHandler;

public class Error {
    private int line;
    private String errorCode;

    public Error(String errorCode, int line) {
        this.line = line;
        this.errorCode = errorCode;
    }

    public int getLine() {
        return line;
    }

    public String getErrorCode() {
        return errorCode;
    }
}
