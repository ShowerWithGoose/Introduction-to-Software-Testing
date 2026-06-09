package frontend.Parser.expression.primaryexp;

import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class PrimaryExp
{
    private String type = "<PrimaryExp>";
    private PrimaryAllExp exp;

    public PrimaryExp(PrimaryAllExp exp)
    {
        this.exp = exp;
    }

    public PrimaryExp ParsePrimaryExp(Tokenlist tokenlist)
    {
        Token token = tokenlist.getToken();
        PrimaryAllExp exp1;
        if (token.getType() == Token.Type.LPARENT)
        {
            ExpPrim expPrim = new ExpPrim(null, null, null);
            //tokenlist.ReadNext();
            exp1 = expPrim.ParseExpPrim(tokenlist);
            //tokenlist.ReadNext();
            //tokenlist.ReadNext();
        }
        else if (token.getType() == Token.Type.IDENFR)
        {
            LVal lVal = new LVal(null, null, null, null);
            exp1 = lVal.ParseLVal(tokenlist);
            //tokenlist.ReadNext();
        }
        else if (token.getType() == Token.Type.INTCON)
        {
            Number number = new Number(null);
            exp1 = number.ParseIntConst(tokenlist);
            tokenlist.ReadNext();
        }
        else
        {
            Character character = new Character(null);
            exp1 = character.ParseCharConst(tokenlist);
            tokenlist.ReadNext();
        }
        return new PrimaryExp(exp1);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.toString());
        sb.append(type + "\n");
        return sb.toString();
    }
}
