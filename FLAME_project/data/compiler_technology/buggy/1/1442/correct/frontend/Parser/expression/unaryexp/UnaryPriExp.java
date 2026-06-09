package frontend.Parser.expression.unaryexp;

import frontend.Parser.expression.primaryexp.PrimaryExp;
import frontend.lexer.Tokenlist;

public class UnaryPriExp implements UnaryAll
{
    private PrimaryExp exp;

    public UnaryPriExp(PrimaryExp exp)
    {
        this.exp = exp;
    }

    public UnaryPriExp ParseUnaryPriExp(Tokenlist tokenlist)
    {
        PrimaryExp exp1 = new PrimaryExp(null);
        return new UnaryPriExp(exp1.ParsePrimaryExp(tokenlist));
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.toString());
        return sb.toString();
    }
}
