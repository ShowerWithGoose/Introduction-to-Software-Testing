package frontend.parseApart.NodeDef.Exps;

import java.util.ArrayList;

public class FuncRParams {
    private ArrayList<Exp> exps = new ArrayList<>();

    public FuncRParams() {}

    public void setExps(Exp exp) {
        this.exps.add(exp);
    }

    public String returnSymbolType() {
        String string = "<FuncRParams>";
        return string;
    }
}
