package frontend.parseApart.NodeDef.Exps;

public class PrimaryLVal extends  PrimaryExp {
    private LVal lVal;

    public PrimaryLVal() {}

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public String returnSymbolType() {
        String string = "<PrimaryExp>";
        return string;
    }
}
