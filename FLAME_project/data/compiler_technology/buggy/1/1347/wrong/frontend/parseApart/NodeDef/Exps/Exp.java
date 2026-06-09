package frontend.parseApart.NodeDef.Exps;

public class Exp {
    private AddExp addExp;

    public Exp() {

    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String returnSymbolType() {
        String string = "<Exp>";
        return string;
    }
}
