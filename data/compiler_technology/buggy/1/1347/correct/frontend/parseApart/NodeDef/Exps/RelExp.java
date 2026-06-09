package frontend.parseApart.NodeDef.Exps;

import java.util.ArrayList;

public class RelExp {
    private ArrayList<AddExp> addExps = new ArrayList<>();
    private RelExp relExp;
    private ArrayList<String> ops = new ArrayList<>();

    public RelExp() {

    }

    public void setAddExps(AddExp addExp) {
        this.addExps.add(addExp);
    }

    public void setOps(String s) {
        this.ops.add(s);
    }

    public void setRelExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public String returnSymbolType() {
        String string = "<RelExp>";
        return string;
    }
}
