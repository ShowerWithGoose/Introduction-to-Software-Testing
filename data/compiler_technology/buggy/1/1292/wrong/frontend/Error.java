package frontend;

public class Error {
    private int lineNum;
    private String type;
    private int typenum;

    public Error(int lineNum, String type) {
        this.lineNum = lineNum;
        this.type = type;
        if (type.equals("a")) {
            this.typenum = 0;
        } else {
            this.typenum = 1;
        }
    }

    public int getLineNum() {
        return lineNum;
    }

    public String getType() {
        return type;
    }

    public int getTypenum() {
        return typenum;
    }
}
