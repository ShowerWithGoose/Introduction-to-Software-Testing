package frontend.parser.expr.types;

import frontend.lexer.Token;

import java.util.ArrayList;

public class LAndExp {
    private final ArrayList<EqExp> exps = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();
    public LAndExp(EqExp firstExp) {
        this.exps.add(firstExp);
    }
    public void appendEqExp(Token sep, EqExp exp) {
        seps.add(sep);
        exps.add(exp);
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(exps.get(0));
        res.append("<LAndExp>\n");
        for (int i = 0; i < seps.size(); i++) {
            res.append(seps.get(i));
            res.append(exps.get(i + 1));
            res.append("<LAndExp>\n");
        }
        return res.toString();
    }
}
