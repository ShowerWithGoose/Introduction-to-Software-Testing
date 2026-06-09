package frontend;

public class Error {
    private char type;
    private int line;

    public Error(char type, int line) {
        this.type = type;
        this.line = line;
    }

    public char getType() {
        return type;
    }

    public int getLine() {
        return line;
    }
}
