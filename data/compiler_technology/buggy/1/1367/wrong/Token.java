public class Token {
    private String type;
    private String name;
    private int lineNum;

    public Token(String type, String name, int lineNum) {
        this.type = type;
        this.name = name;
        this.lineNum = lineNum;
    }

    public String getType() {
        return type;
    }

    public String getName() {
        return name;
    }

    public int getLineNum() {
        return lineNum;
    }

    public String toString() {
        return type + " " + name;
    }
}