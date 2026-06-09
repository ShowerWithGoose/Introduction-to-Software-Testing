package frontend;

public class Token {
    TokenType type;
    String content;
    int lineno;

    public Token(){

    }

    public Token(TokenType type, String content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }

    public TokenType getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLineno() {
        return lineno;
    }


    public String toString() {
        return type + " " + content;
    }
}
