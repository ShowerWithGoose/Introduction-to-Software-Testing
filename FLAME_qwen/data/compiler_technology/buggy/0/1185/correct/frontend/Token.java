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

    public String getType() {
        return type;
    }

    public String getString() {
        return string;
    }

    public void printToken() {
        System.out.print(type + " " + string + "\n");
    }
}
