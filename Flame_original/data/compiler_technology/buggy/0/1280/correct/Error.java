public class Error {
    private final int lineNumber;
    private final int columnNumber;
    private final char errorCode;

    public Error(int lineNumber, int columnNumber, char errorCode) {
        this.lineNumber = lineNumber;
        this.columnNumber = columnNumber;
        this.errorCode = errorCode;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public char getErrorCode() {
        return errorCode;
    }

    public int getColumnNumber() {
        return columnNumber;
    }
}
