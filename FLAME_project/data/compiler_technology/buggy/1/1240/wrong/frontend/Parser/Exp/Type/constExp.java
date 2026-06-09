package frontend.Parser.Exp.Type;

import frontend.Parser.Exp.Type.SameExp.AddExp;

public class constExp {
    public final AddExp addExp;

    public constExp(AddExp addExp)
    {
        this.addExp = addExp;
    }

    @Override
    public String toString()
    {
        return addExp.toString() + "<ConstExp>\n";
    }
}
