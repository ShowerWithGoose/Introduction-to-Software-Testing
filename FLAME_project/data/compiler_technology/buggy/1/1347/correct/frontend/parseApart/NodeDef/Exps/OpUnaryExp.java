package frontend.parseApart.NodeDef.Exps;

import java.util.ArrayList;

public class OpUnaryExp extends  UnaryExp{
    private ArrayList<String> ops;
    private UnaryExp unaryExp;

    public OpUnaryExp(ArrayList<String> ops, UnaryExp unaryExp) {
        this.ops = ops;
        this.unaryExp = unaryExp;
    }

    public String returnSymbolType() {
        String string = "<UnaryExp>";
        return string;
    }
}
