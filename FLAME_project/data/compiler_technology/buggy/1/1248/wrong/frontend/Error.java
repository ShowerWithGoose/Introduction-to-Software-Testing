package frontend;

public class Error {
    private int lineNum;
    private char code;

    public Error(int lineNum, char code) {
        this.lineNum = lineNum;
        this.code = code;
    }

    public int getLineNum() {
        return this.lineNum;
    }

    public char getCode() {
        return this.code;
    }
}
