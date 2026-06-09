package frontend;

public class Error {
    private int line;
    private String type;
    public Error(int line, String type) {
        this.line = line;
        this.type = type;
    }

    public int getLine() {
        return line;
    }

    public String getType() {
        return type;
    }
}
