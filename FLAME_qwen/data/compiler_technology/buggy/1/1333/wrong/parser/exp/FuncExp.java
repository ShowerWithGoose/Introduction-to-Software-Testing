package parser.exp;

import parser.func.FuncRParams;

public class FuncExp implements SimpleUnaryExp {
    private final String ident;
    private final FuncRParams funcRParams;

    public FuncExp(String ident, FuncRParams funcRParams) {
        this.ident = ident;
        this.funcRParams = funcRParams;
    }

    public String toString() {
        String ide = "IDENFR " + this.ident + "\nLPARENT (\n";
        if (this.funcRParams == null) {
            return ide + "RPARENT )\n";
        } else {
            return ide + this.funcRParams.toString() + "RPARENT )\n";
        }
    }
}
