package frontend.Token;

public class Token {
    private final TokenType type;
    private final String content;
    private final int lineNum;

    public Token(TokenType type, String content, int lineNum) {
        this.type = type;
        this.content = content;
        this.lineNum = lineNum;
    }

    public Token(String content, int lineNum) {
        this.type = TokenType.keyWordMap.get(content);
        this.content = content;
        this.lineNum = lineNum;
    }

    public String getContent() {
        return content;
    }

    public int getLineNum() {
        return lineNum;
    }

    public TokenType getType() {
        return type;
    }
}
