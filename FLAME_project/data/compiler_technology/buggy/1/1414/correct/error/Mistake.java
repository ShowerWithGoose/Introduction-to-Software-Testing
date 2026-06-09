package error;

public class Mistake implements Comparable {
    private int line;
    private ErrorType errorType;

    public Mistake(ErrorType errorType, int line) {
        this.line = line;
        this.errorType = errorType;
    }

    public String toString() {
        return line + " " + errorType.toString();
    }

    @Override
    public int compareTo(Object o) {
        return this.line - ((Mistake)o).line;
    }
}
