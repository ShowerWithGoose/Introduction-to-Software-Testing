package frontend;

public class MyError {
    private String msg;
    private int line;

    public MyError(String msg, int line) {
        this.msg = msg;
        this.line = line;
    }

    public String getMsg() {
        return msg;
    }

    public int getLine() {
        return line;
    }
}
