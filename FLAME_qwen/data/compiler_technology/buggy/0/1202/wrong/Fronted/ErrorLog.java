package Fronted;

public class ErrorLog {
    public int lineNum;
    public char type;

    public ErrorLog(int lineNum,char type) {
        this.lineNum = lineNum;
        this.type = type;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lineNum+ " " + type);
        return sb.toString();
    }

    public char getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }
}
