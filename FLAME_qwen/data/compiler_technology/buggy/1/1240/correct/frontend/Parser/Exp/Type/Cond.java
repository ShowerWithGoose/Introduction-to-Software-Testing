package frontend.Parser.Exp.Type;

import frontend.Parser.Exp.Type.SameExp.LOrExp;

public class Cond {
    public final LOrExp lOrExp;

    public Cond(LOrExp lOrExp)
    {
        this.lOrExp = lOrExp;
    }

    @Override
    public String toString()
    {
        return lOrExp.toString() + "<Cond>\n";
    }
}
