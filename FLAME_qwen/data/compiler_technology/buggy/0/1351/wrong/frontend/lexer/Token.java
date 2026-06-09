package frontend.lexer;

public class Token {
    private final Type type;
    private final String content;
    private final int lineNo;
    private int charNo;
    public Token(Type type, String content, int lineNo) {
        this.type = type;
        this.content = content;
        this.lineNo = lineNo;
    }

    public Type getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLineNo() {
        return lineNo;
    }

    public int getCharNo() {
        return charNo;
    }

    @Override
    public String toString() {
        return type + " " + content;
    }
}
