package Token;

public class Token {
    public TokenTypes type;
    public int line;
    public String content;
    public Token(TokenTypes type, int line, String content) {
        this.type = type;
        this.line = line;
        this.content = content;
    }
    public String toString() {
        return type.toString() + " " + content + "\n";
    }
}
