package frontend.parseApart.NodeDef.Exps;

import java.util.ArrayList;

public class AddExp {
    private AddExp addExp;
    private ArrayList<MulExp> mulExps;
    private ArrayList<String> ops;

    public AddExp() {
        this.mulExps = new ArrayList<>();
        this.ops = new ArrayList<>();
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setMulExps(MulExp mulExp) {
        this.mulExps.add(mulExp);
    }

    public void setOps(String s) {
        this.ops.add(s);
    }

    public String returnSymbolType() {
        String string = "<AddExp>";
        return string;
    }
}
