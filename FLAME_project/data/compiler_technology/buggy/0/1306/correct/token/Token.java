package token;

public class Token {
    private TokenType tokenType;
    private String symbol;

    public Token(TokenType tokenType, String string) {
        this.tokenType = tokenType;
        this.symbol = string;
    }

    public TokenType getTokenType() {
        return tokenType;
    }

    public void setTokenType(TokenType tokenType) {
        this.tokenType = tokenType;
    }

    public String getSymbol() {
        return symbol;
    }

    public void setSymbol(String symbol) {
        this.symbol = symbol;
    }

    @Override
    public String toString() {
        return this.tokenType+" "+this.symbol;
    }
}
