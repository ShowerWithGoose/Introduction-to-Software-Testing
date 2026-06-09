package frontend;

public class Token
{
    public TokenType type;
    public String value;
    public int lineNo;

    public Token(TokenType type, String value, int lineNo)
    {
        this.type = type;
        this.value = value;
        this.lineNo = lineNo;
    }
}
