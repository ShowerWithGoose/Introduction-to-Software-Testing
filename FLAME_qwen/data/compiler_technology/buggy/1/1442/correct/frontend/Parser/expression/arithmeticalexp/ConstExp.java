package frontend.Parser.expression.arithmeticalexp;

import frontend.lexer.Tokenlist;

public class ConstExp
{
    private String type = "<ConstExp>";
    private AddExp exp;

    public ConstExp(AddExp exp)
    {
        this.exp = exp;
    }

    public ConstExp ParseConstExp(Tokenlist tokenlist)
    {
        AddExp addExp = new AddExp(null, null);
        AddExp exp1 = addExp.ParseAddExp(tokenlist);
        return new ConstExp(exp1);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.toString());
        sb.append(type + "\n");
        return sb.toString();
    }

}
