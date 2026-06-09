package Front;

public class Token
{
    private final String token;
    private int number = 0;
    private final int lineNum;
    private final lexToken type;

    public Token(String tokenStr, int line, lexToken tokenType)
    {
        this.token = tokenStr;
        this.lineNum = line;
        this.type = tokenType;
        if (type == lexToken.INTCON)
        {
            this.number = Integer.parseInt(tokenStr);
        }
    }

    public String getValue()
    {
        return token;
    }

    public int getLine()
    {
        return lineNum;
    }

    public lexToken getType()
    {
        return type;
    }

    public String information()
    {
        String inf = type.toString() + ' ' + token;
        return inf;
    }

    public enum lexToken
    {
        IDENFR, INTCON, STRCON, CHRCON,
        CONSTTK, INTTK, CHARTK, VOIDTK,
        IFTK, ELSETK, FORTK, BREAKTK, CONTINUETK,
        NOT, AND, OR,
        MAINTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK,
        PLUS, MINU, MULT, DIV, MOD,
        LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
        SEMICN, COMMA,
        LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE
    }
}
