package Lexer;

public class Token {
    private String token;  // Token.Token name

    private String type;  // Token.Token type
    private int lineNumber;

    public Token(String token, int lineNumber) {
        this.token = token;
        this.type = new KeywordManager().getKeywordCategory(token);
        this.lineNumber = lineNumber;
    }

    public Token(String token, String type, int lineNumber) {
        this.token = token;
        this.type = type;
        this.lineNumber = lineNumber;
    }

    public String getTokenContent() {
        return type + " " + token;
    }

    public String getType() {
        if (type != null) {
            return type;
        }
        return null;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public String getToken() {
        return token;
    }
}
