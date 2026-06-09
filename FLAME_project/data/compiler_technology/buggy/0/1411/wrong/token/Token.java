package token;

public class Token {
    private final TokenName name;
    private final String content;
    private final Integer lineNumber;
    public Token(TokenName name, String content, Integer lineNumber) {
        this.name = name;
        this.content = content;
        this.lineNumber = lineNumber;
    }
    public TokenName getName() {
        return this.name;
    }
    public String getContent() {
        return this.content;
    }

    public Integer getLineNumber() {
        return lineNumber;
    }
    public String toString() {
        return String.format("%s %s", this.name, this.content);
    }
}
