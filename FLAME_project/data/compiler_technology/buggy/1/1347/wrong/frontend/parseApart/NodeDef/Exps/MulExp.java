package frontend.parseApart.NodeDef.Exps;

import java.util.ArrayList;

public class MulExp {
    private ArrayList<UnaryExp> unaryExps;
    private ArrayList<String> ops;
    private MulExp mulExp;

    public MulExp() {
        this.unaryExps = new ArrayList<>();
        this.ops = new ArrayList<>();
    }

    public void setUnaryExps(UnaryExp unaryExp) {
        this.unaryExps.add(unaryExp);
    }

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public void setOps(String s) {
        this.ops.add(s);
    }

    public String returnSymbolType() {
        String string = "<MulExp>";
        return string;
    }
}
