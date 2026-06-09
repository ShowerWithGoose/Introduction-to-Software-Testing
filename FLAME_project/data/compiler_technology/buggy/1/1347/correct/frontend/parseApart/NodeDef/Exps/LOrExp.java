package frontend.parseApart.NodeDef.Exps;

import java.util.ArrayList;

public class LOrExp {
    private LOrExp lOrExp = null;
    private ArrayList<LAndExp> andExps = new ArrayList<>();

    public LOrExp() {

    }

    public void addLAndExp(LAndExp lAndExp) {
        andExps.add(lAndExp);
    }

    public void setlOrExp(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public String returnSymbolType() {
        String string = "<LOrExp>";
        return string;
    }
}
