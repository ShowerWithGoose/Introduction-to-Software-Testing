package frontend;

public class Error {
    private final int lineno;
    private final char type;

    public Error(int lineno, char type) {
        this.lineno = lineno;
        this.type = type;
    }

    public int getLineno() {
        return lineno;
    }

    public char getType() {
        return type;
    }

    public String toString() {
        return lineno + " " + type;
    }
}
