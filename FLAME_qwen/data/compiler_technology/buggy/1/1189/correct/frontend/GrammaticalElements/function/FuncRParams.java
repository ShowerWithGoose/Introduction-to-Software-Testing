package frontend.GrammaticalElements.function;

import frontend.GrammaticalElements.expression.Exp;
import frontend.Token;

import java.util.ArrayList;

public class FuncRParams {
    private final String name = "<FuncRParams>";
    private Exp firstExp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;

    public FuncRParams(Exp firstExp, ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.firstExp = firstExp;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstExp.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i).toString());
            sb.append(exps.get(i).toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
