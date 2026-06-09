package exception;

public class CompilerError {
    private int index;
    private String message;
    public CompilerError(int index, String message) {
        this.index = index;
        this.message = message;
    }

    public String toString() {
        return index + " " + message;
    }

    public int getIndex() {
        return index;
    }
}
