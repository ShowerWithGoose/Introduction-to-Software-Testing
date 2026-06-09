package frontend.Parser.expression.primaryexp;

import frontend.Parser.expression.AllExp;
import frontend.Parser.expression.Exp;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class LVal implements PrimaryAllExp
{
    private String type = "<LVal>";

    private Token ident;

    private Token lbrack;
    private Token rbrack;
    private Exp exp;

    public LVal(Token ident, Token lbrack, Token rbrack, Exp exp)
    {
        this.ident = ident;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
        this.exp = exp;
    }

    public LVal ParseLVal(Tokenlist tokenlist)
    {
        Token ident1 = tokenlist.getToken();
        Exp exp1 = new Exp(null);
        Exp exp2 = null;
        tokenlist.ReadNext();
        Token lbrack = null;
        Token rbrack = null;
        if (tokenlist.getToken().getType() == Token.Type.LBRACK)
        {
            lbrack = tokenlist.getToken();
            tokenlist.ReadNext();
            exp2 = exp1.ParseExp(tokenlist);
            //tokenlist.ReadNext();
            if (tokenlist.getToken().getType() != Token.Type.RBRACK)
            {
                Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'k'));
                System.out.println("LVal + 缺少一个右中括号");
            }
            else
            {
                rbrack = tokenlist.getToken();
                tokenlist.ReadNext();
            }
        }
        return new LVal(ident1, lbrack, rbrack, exp2);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (exp != null)
        {
            sb.append(lbrack.toString());
            sb.append(exp.toString());
            sb.append(rbrack.toString());
        }
        sb.append(type + "\n");
        return sb.toString();
    }
}
