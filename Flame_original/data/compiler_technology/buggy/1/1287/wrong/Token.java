public class Token extends Node{
    private LexType lexType;
    private String string;
    private int lineNum;

    public Token(LexType lexType, String s, int lineNum) {
        this.string = s;
        this.lexType = lexType;
        this.lineNum = lineNum;
    }

    public LexType getLexType() {
        return lexType;
    }

    public String toString() {
        return lexType.toString() + " " + string;
    }

    public int getLineNum() {
        return lineNum;
    }
}
