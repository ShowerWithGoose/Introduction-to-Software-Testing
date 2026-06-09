package frontend;

public class Error {
    private String type;
    private int lineNum;

    public Error(String type, int lineNum) {
        this.type = type;
        this.lineNum = lineNum;
    }

    public String getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }
}
