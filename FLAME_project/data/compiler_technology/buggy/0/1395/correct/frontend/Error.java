package frontend;

public class Error {
    private int line;
    private String message;

    public Error(int line, String message) {
        this.line = line;
        this.message = message;
    }

    public int getLine() {
        return line;
    }

    public String getMessage() {
        return message;
    }
}
