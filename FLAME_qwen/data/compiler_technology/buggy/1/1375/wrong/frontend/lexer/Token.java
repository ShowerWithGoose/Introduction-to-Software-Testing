package frontend.lexer;

public class Token{
    public TokenType type;
    public int linenum;
    public String content;

    public Token(TokenType type, int linenum, String content) {
        this.type = type;
        this.linenum = linenum;
        this.content = content;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.type + " " + this.content + "\n");
        return sb.toString();
    }
}
