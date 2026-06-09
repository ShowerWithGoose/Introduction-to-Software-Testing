package frontend.parser.expression;

import frontend.parser.expression.primary.PExp;
import frontend.parser.expression.unary.UExp;

public class PrimaryExp implements UExp {
    private final String name = "<PrimaryExp>";
    private PExp pExp;

    public PrimaryExp(PExp pExp) {
        this.pExp = pExp;
    }

    public int getLineno() {
        return pExp.getLineno();
    }

    public String getOutPut() {
        return pExp.getOutPut() + name + "\n";
    }

    public String getError() {
        return pExp.getError();
    }
}
