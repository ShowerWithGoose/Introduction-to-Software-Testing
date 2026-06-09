public class Token {
    private String name;
    private String contents;
    private TokenKind kind;

    public Token(String name, String contents, TokenKind kind) {
        this.name     = name;
        this.contents = contents;
        this.kind     = kind;
    }

    public String getContents() {
        return contents;
    }

    public TokenKind getKind() {
        return kind;
    }
}
