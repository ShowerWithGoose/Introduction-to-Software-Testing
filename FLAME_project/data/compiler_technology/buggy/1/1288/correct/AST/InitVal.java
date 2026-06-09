package AST;

import java.util.ArrayList;

public class InitVal {
    private Exp exp;
    private ArrayList<Exp> exps = new ArrayList<>();
    private StringConst stringConst;
    public InitVal(Exp exp, ArrayList<Exp> exps, StringConst stringConst) {
        this.exp = exp;
        this.exps=(exps);
        this.stringConst = stringConst;
    }
}
