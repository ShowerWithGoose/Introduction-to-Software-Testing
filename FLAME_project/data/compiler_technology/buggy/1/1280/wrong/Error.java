public class Error implements Comparable<Error> {
    private final int lineNumber;
    private final int columnNumber;
    private final char errorCode;

    public Error(int lineNumber, int columnNumber, char errorCode) {
        this.lineNumber = lineNumber;
        this.columnNumber = columnNumber;
        this.errorCode = errorCode;
    }

    @Override
    public int compareTo(Error error) {
        if (this.lineNumber > error.lineNumber) {
            return 1;
        } else if (this.lineNumber < error.lineNumber) {
            return -1;
        } else {
            if (this.errorCode > error.errorCode) {
                return 1;
            } else if (this.errorCode < error.errorCode) {
                return -1;
            }
        }
        return 0;
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
