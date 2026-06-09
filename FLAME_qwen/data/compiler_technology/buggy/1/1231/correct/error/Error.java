package error;

public class Error implements Comparable<Error> {
    private MyErrorType errorType;
    private int line;

    public Error(MyErrorType errorType, int line) {
        this.errorType = errorType;
        this.line = line;
    }

    public MyErrorType getErrorType() {
        return errorType;
    }

    public int getLine() {
        return line;
    }

    @Override
    public String toString() {
        return line + " " + errorType.getCode();
    }

    @Override
    public int compareTo(Error o) {
        return this.line - o.line;
    }

}
