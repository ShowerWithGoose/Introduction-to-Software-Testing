package frontend;

public class Token {
    private final TokenType tokentype;
    private final String content;
    private final Integer lineno;

    public Token(TokenType tokentype, String word, Integer lineno) {
        this.tokentype = tokentype;
        this.content = word;
        this.lineno = lineno;
    }

    public String getContent() {
        return content;
    }

    public TokenType getTokentype() {
        return tokentype;
    }

    public Integer getLineno() {
        return lineno;
    }


}
