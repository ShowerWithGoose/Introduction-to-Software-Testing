package frontend;

public class Token{
    public TokenType type;
    public int linenum;
    public String content;

    public Token(TokenType type, int linenum, String content) {
        this.type = type;
        this.linenum = linenum;
        this.content = content;
    }
}
