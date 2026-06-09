package frontend;
public class Error {
    private char type;
    private int lineNum;
    public Error(char type, int lineNum) {
        this.type = type;
        this.lineNum = lineNum;
    }

    public char getType() {
        return this.type;
    }

    public int getLineNum() {
        return this.lineNum;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lineNum + " " + this.type + "\n");
        return sb.toString();
    }
}
