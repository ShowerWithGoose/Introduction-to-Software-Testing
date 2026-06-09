package error;

public class ErrorCode {
    private ErrorType type;
    private int lineNumber;

    public ErrorCode(ErrorType type, int lineNumber) {
        this.type = type;
        this.lineNumber = lineNumber;
    }

    public String toString() {
        return lineNumber + " " + type.getCode();
    }
}
