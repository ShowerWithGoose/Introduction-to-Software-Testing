package frontend;

public class Token {
    private LexType type;
    private String content;
    private int lineno;

    public Token(LexType type, String content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }

    public LexType getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLineno() {
        return lineno;
    }
}
