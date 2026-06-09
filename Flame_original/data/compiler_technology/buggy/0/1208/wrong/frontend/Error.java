package frontend;

public class Error {
    private int lineno;
    private char type;

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
}
