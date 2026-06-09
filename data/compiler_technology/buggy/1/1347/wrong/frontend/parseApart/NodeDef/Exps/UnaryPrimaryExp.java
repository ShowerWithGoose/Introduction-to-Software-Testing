package frontend.parseApart.NodeDef.Exps;

public class UnaryPrimaryExp extends UnaryExp {
    private PrimaryExp primaryExp;

    public UnaryPrimaryExp() {}

    public void setPrimaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public String returnSymbolType() {
        String string = "<UnaryExp>";
        return string;
    }
}
