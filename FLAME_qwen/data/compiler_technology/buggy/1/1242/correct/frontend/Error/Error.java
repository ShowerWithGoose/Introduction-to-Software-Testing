package frontend.Error;

public class Error {
    private int line;

    private char type;

    public Error(int line,char type) {
        this.line = line;
        this.type = type;
    }

    public int GetLine() {
        return line;
    }

    public char GetType() {
        return type;
    }

    @Override
    public String toString() {
        return line + " " + type;
    }
}
