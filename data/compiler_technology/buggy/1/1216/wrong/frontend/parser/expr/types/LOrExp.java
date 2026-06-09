package frontend.parser.expr.types;

import frontend.lexer.Token;

import java.util.ArrayList;

public class LOrExp {
    private final LAndExp firstExp;
    private final ArrayList<LAndExp> exps = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();
    public LOrExp(LAndExp firstExp) {
        this.firstExp = firstExp;
    }
    public void appendLAndExp(Token sep, LAndExp exp) {
        seps.add(sep);
        exps.add(exp);
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(firstExp);
        res.append("<LOrExp>\n");
        for (int i = 0; i < seps.size(); i++) {
            res.append(seps.get(i));
            res.append(exps.get(i));
            res.append("<LOrExp>\n");
        }
        return res.toString();
    }
}
