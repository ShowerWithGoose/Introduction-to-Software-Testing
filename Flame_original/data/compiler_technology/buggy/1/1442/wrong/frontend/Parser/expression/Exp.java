package frontend.Parser.expression;

import frontend.Parser.expression.arithmeticalexp.AddExp;
import frontend.Parser.expression.arithmeticalexp.ConstExp;
import frontend.lexer.Tokenlist;

public class Exp
{
    private String type = "<Exp>";
    private AddExp exp;

    public Exp(AddExp exp)
    {
        this.exp = exp;
    }

    public Exp ParseExp(Tokenlist tokenlist)
    {
        AddExp addExp = new AddExp(null, null);
        AddExp exp1 = addExp.ParseAddExp(tokenlist);
        return new Exp(exp1);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.toString());
        sb.append(type + "\n");
        return sb.toString();
    }
}
