package Error;

public class Error {
    private int lineNum;
    private String type;
    private String content;

    public Error(int lineNum, String type,String content) {
        this.lineNum = lineNum;
        this.type = type;
        this.content = content;
    }

    @Override
    public String toString() {
        return lineNum + " " + type;
    }
}
