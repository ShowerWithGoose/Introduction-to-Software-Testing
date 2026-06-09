package frontend;

public class Token {
    private String type;
    private String string;
    private int posLine;

    public Token(String type, String s, int pos) {
        this.type = type;
        this.string = s;
        this.posLine = pos;
    }

    public Token(String type) {
        this.type = type;
        this.string = type;
        this.posLine = -1;
    }

    public String getType() {
        return type;
    }

    public String getString() {
        return string;
    }

    public int getPosLine() {
        return posLine;
    }
    public String printToken() {
        return (type + " " + string + "\n");
    }
}
