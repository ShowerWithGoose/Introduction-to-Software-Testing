package frontend.parseApart.NodeDef.Exps;

public class ConstExp {
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String returnSymbolType() {
        String string = "<ConstExp>";
        return string;
    }

}
