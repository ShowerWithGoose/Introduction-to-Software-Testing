package frontend.parseApart.NodeDef.Exps;

public class Cond {
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public String returnSymbolType() {
        String string = "<Cond>";
        return string;
    }
}
