package frontend.SyntaxTree;

import java.util.ArrayList;

public class FuncRParams {
    private ArrayList<Exp> exps;

    public FuncRParams() {
        exps = new ArrayList<Exp>();
    }

    public void addExp(Exp exp) {
        exps.add(exp);
    }
}
