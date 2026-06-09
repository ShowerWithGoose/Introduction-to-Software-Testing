package frontend.parseApart.NodeDef.Exps;

public class PrimaryExpExp extends PrimaryExp {
    private Exp exp;

    public PrimaryExpExp() {}

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public String returnSymbolType() {
        String string = "<PrimaryExp>";
        return string;
    }
}
