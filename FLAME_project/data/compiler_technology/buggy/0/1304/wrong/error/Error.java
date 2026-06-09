package error;

public class Error {
    private final int line;
    private final ErrorType exceptionType;

    public Error(int line, ErrorType exceptionType) {
        this.line = line;
        this.exceptionType = exceptionType;
    }

    @Override
    public String toString() {
        return line + " " + exceptionType;
    }
}
