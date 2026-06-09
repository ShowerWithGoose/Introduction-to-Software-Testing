package nodes;

public class Token implements SyntaxNode {
    private TokenType type;

    public TokenType getType() {
        return type;
    }

    private String value;

    public String getValue() {
        return value;
    }

    protected int lineNum;

    public int getLineNum() {
        return lineNum;
    }

    private int content;

    public Token(TokenType type, String value, int lineNum, int content) {
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
        this.content = content;
    }

    @Override
    public String toString() {
        return lineNum + " " + type.toString() + " " + value;
    }

    @Override
    public String syntaxPrinter() {
        return type.toString() + " " + value + "\n";
    }

    @Override
    public boolean parse() {
        return true;
    }
}
