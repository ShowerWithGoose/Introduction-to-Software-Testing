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

    public void setLine(int line) {
        this.line = line;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}
