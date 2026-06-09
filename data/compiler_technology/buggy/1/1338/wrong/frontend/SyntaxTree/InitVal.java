package frontend.SyntaxTree;

import java.util.ArrayList;

public class InitVal {
    private ArrayList<Exp> exps;
    private String stringConst;

    public InitVal() {
        this.exps = new ArrayList<>();
    }

    public void addExp(Exp exp) {
        this.exps.add(exp);
    }

    public void setStringConst(String stringConst) {
        this.stringConst = stringConst;
    }
}
