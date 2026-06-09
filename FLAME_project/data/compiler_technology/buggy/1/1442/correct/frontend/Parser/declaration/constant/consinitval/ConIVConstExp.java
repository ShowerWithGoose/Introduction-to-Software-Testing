package frontend.Parser.declaration.constant.consinitval;

import frontend.Parser.expression.arithmeticalexp.ConstExp;
import frontend.lexer.Tokenlist;

public class ConIVConstExp implements ConstAllInitVal
{
    private ConstExp constExp;

    public ConIVConstExp(ConstExp constExp)
    {
        this.constExp = constExp;
    }

    public ConIVConstExp ParseConIVConstExp(Tokenlist tokenlist)
    {
        ConstExp constExp1 = new ConstExp(null);
        ConstExp constExp2 = constExp1.ParseConstExp(tokenlist);
        return new ConIVConstExp(constExp2);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(constExp.toString());
        return sb.toString();
    }
}
