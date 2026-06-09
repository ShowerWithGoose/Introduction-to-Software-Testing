package error;

public class Error {
    public int line;
    public char errCode;

    public Error(int line, char errCode) {
        this.line = line;
        this.errCode = errCode;
    }

    @Override
    public String toString() {
        return String.format("%d %c", line, errCode);
    }
}
