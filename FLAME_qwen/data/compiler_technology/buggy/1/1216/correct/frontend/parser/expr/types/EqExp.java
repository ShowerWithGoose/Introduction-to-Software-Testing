package frontend.parser.expr.types;

import frontend.lexer.Token;

import java.util.ArrayList;

public class EqExp {
    private final ArrayList<RelExp> exps = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();
    public EqExp(RelExp firstExp) {
        this.exps.add(firstExp);
    }
    public void appendRelExp(Token sep, RelExp exp) {
        seps.add(sep);
        exps.add(exp);
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(exps.get(0));
        res.append("<EqExp>\n");
        for (int i = 0; i < seps.size(); i++) {
            res.append(seps.get(i));
            res.append(exps.get(i + 1));
            res.append("<EqExp>\n");
        }
        return res.toString();
    }
}
