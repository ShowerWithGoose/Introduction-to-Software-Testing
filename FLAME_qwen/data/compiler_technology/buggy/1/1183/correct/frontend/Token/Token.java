package frontend.Token;

public class Token {
    private String name;
    private int number;
    private int lineNum;
    private LexType lexType;

    public Token(String name, int number, int lineNum, LexType lexType) {
        this.name = name;
        this.number = number;
        this.lineNum = lineNum;
        this.lexType = lexType;
    }

    public String getName() {
        return name;
    }

    public int getNumber() {
        return number;
    }

    public int getLineNum() {
        return lineNum;
    }

    public LexType getLexType() {
        return lexType;
    }

    @Override
    public String toString() {
        return lexType.toString() + ' ' + name;
    }
}
