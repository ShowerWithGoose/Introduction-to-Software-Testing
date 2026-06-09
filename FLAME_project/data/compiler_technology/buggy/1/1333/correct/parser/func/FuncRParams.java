package parser.func;

import parser.exp.Exp;

import java.util.ArrayList;

public class FuncRParams {
    private final ArrayList<Exp> exps;

    public FuncRParams() {
        this.exps = new ArrayList<>();
    }

    public void addExp(Exp exp) {
        this.exps.add(exp);
    }

    public String toString() {
        StringBuilder start = new StringBuilder(this.exps.get(0).toString());
        for (int i = 1; i < this.exps.size(); i++) {
            start.append("COMMA ,\n");
            start.append(this.exps.get(i).toString());
        }
        start.append("<FuncRParams>\n");
        return start.toString();
    }
}
