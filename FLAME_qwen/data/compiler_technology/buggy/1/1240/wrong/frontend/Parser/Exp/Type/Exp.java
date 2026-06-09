package frontend.Parser.Exp.Type;

import frontend.Parser.Exp.Type.SameExp.AddExp;

public class Exp {
    public final AddExp addExp;

    public Exp(AddExp addExp)
    {
        this.addExp = addExp;
    }

    @Override
    public String toString()
    {
        return addExp.toString() + "<Exp>\n";
    }
}
