package frontend.parser.expression;

import frontend.parser.expression.unary.UExp;

public class UnaryExp {
    private final String name = "<UnaryExp>";
    private UExp uExp;

    public UnaryExp(UExp uExp) {
        this.uExp = uExp;
    }

    public int getLineno() {
        return uExp.getLineno();
    }

    public String getOutPut() {
        return uExp.getOutPut() + name + "\n";
    }

    public String getError() {
        return uExp.getError();
    }
}
