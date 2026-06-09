package frontend.parseApart.NodeDef.Exps;

import java.util.ArrayList;

public class EqExp {
    private EqExp eqExp;
    private ArrayList<RelExp> relExps = new ArrayList<>();
    private ArrayList<String> ops = new ArrayList<>();

    public EqExp() {

    }

    public void setRelExps(RelExp relExp) {
        this.relExps.add(relExp);
    }

    public void setOps(String s) {
        this.ops.add(s);
    }

    public void setEqExp(EqExp eqExp) {
        this.eqExp = eqExp;
    }

    public String returnSymbolType() {
        String string = "<EqExp>";
        return string;
    }
}
