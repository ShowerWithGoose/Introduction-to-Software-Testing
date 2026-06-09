public class ErrorToken {
    private int line;
    private String type;

    public ErrorToken(int line, String type) {
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