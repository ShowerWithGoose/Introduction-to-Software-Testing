package frontend;

public class MyError {
    private int line;
    private ErrorType errorType;


    public MyError(int line, ErrorType errorType) {
        this.line = line;
        this.errorType = errorType;
    }

    public String getMessage() {
        return line + " " + errorType;
    }
}
