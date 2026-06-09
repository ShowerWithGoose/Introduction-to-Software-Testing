package error;

public class Error {
    private ErrorType type;
    private int line;

    public Error(ErrorType type, int line) {
        this.type = type;
        this.line = line;
    }

    public ErrorType getType() {
        return type;
    }

    public void setType(ErrorType type) {
        this.type = type;
    }

    public int getLine() {
        return line;
    }

    public void setLine(int line) {
        this.line = line;
    }

    @Override
    public String toString() {
        return String.format("%d %s", line, type);
    }
}
