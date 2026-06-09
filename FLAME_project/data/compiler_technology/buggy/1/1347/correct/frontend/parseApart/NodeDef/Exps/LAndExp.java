package frontend.parseApart.NodeDef.Exps;

import java.util.ArrayList;

public class LAndExp {
    private LAndExp lAndExp = null;
    private ArrayList<EqExp> eqExps = new ArrayList<>();
    public LAndExp() {

    }

    public void setEqExps(EqExp eqExp) {
         this.eqExps.add(eqExp);
    }

    public void setlAndExp(LAndExp lAndExp) {
        this.lAndExp = lAndExp;
    }

    public String returnSymbolType() {
        String string = "<LAndExp>";
        return string;
    }
}
