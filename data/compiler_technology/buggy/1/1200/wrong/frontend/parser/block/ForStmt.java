package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class ForStmt {
    private final String name = "<ForStmt>";
    private LVal lVal;
    private Token eq;
    private Exp exp;

    public ForStmt(LVal lVal, Token eq, Exp exp) {
        this.lVal = lVal;
        this.eq = eq;
        this.exp = exp;
    }

    public int getLineno() {
        return exp.getLineno();
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.getOutPut());
        sb.append(eq.getOutPut());
        sb.append(exp.getOutPut());
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        return lVal.getError() + exp.getError();
    }
}
