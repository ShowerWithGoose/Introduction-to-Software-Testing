public class SyntaxError {
    private String type;
    private int line;

    public SyntaxError(String type, int line) {
        this.type = type;
        this.line = line;
    }

    public String getType() {
        return this.type;
    }

    public int getLine() {
        return this.line;
    }
}
