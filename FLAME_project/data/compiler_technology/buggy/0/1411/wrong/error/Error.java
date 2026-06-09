package error;

public class Error {
    private final int lineNumber;
    private final char type;
    public Error(int lineNumber, char type) {
        this.lineNumber = lineNumber;
        this.type = type;
    }
    public String toString() {
        return String.format("%d %c", this.lineNumber, this.type);
    }
}
