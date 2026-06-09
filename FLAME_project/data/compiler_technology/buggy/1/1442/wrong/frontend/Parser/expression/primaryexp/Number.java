package frontend.Parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class Number implements PrimaryAllExp
{
    private String type = "<Number>";
    private Token intconst;

    public Number(Token intconst)
    {
        this.intconst = intconst;
    }

    public Number ParseIntConst(Tokenlist tokenlist)
    {
        return new Number(tokenlist.getToken());
//        return new Number(Integer.parseInt(tokenlist.getToken().getContent()));
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(intconst.toString());
        sb.append(type + "\n");
        return sb.toString();
    }
}
