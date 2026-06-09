package error;

/**
 * @author
 * @Description:
 * @date 2024/9/29 17:13
 */
public class Error {
    private int lineNumber;
    private ErrorType type;

    public Error(int lineNumber, ErrorType type) {
        this.lineNumber = lineNumber;
        this.type = type;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public void setLineNumber(int lineNumber) {
        this.lineNumber = lineNumber;
    }

    public ErrorType getType() {
        return type;
    }

    public void setType(ErrorType type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return lineNumber + " " + type.toString() + "\n";
    }
}
