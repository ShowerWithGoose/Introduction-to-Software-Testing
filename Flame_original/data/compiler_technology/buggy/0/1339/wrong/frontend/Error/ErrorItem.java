package frontend.Error;

public class ErrorItem {
    private int lineNum;
    private String type;
    private String content;

    public ErrorItem(int lineNum, String type, String content) {
        this.lineNum = lineNum;
        this.type = type;
        this.content = content;
    }

    public int getLineNum() {
        return lineNum;
    }

    public String getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    @Override
    public String toString() {
        return "Line " + lineNum + " " + type;
    }
}
