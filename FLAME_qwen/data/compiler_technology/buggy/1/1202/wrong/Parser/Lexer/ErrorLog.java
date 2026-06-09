package Parser.Lexer;

public class ErrorLog {
    private int lineNum;
    private char type;
    private int pos;

    public ErrorLog(int lineNum, char type, int pos) {
        this.lineNum = lineNum;
        this.type = type;
        this.pos = pos;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lineNum + " " + type);
        return sb.toString();
    }

    public char getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }

    public int getPos() {
        return pos;
    }
}
