package error;

public class Mistake {
    private int line;
    private ErrorType errorType;

    public Mistake(ErrorType errorType, int line) {
        this.line = line;
        this.errorType = errorType;
    }

    public String toString() {
        return line + " " + errorType.toString();
    }
}
