package frontend.error;

public class TokenError {
    private int line;
    private char error;

    public TokenError(int line, char error) {
        this.line = line + 1;
        this.error = error;
    }

    public int getLine() {
        return line;
    }

    public char getError() {
        return error;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(line + " " + error + "\n");
        return sb.toString();
    }
}
