package frontend;

public class MyError {
    private int line;
    private String errorType;


    public MyError(int line, String string) {
        this.line = line;
        this.errorType = string;
    }

    public String getMessage() {
        return line + " " + errorType;
    }
}
