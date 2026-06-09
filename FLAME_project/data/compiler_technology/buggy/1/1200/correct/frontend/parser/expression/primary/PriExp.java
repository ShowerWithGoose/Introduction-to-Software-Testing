package frontend.parser.expression.primary;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class PriExp implements PExp {
    private Token lParent;
    private Exp exp;
    private Token rParent;
    private String errorLog = "";

    public PriExp(Token lParent, Exp exp, Token rParent) {
        this.lParent = lParent;
        this.exp = exp;
        this.rParent = rParent;
        if (rParent == null) {
            errorLog = exp.getLineno() + " j\n";
        }
    }

    @Override
    public int getLineno() {
        if (rParent != null) {
            return rParent.getLineno();
        } else {
            return exp.getLineno();
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(lParent.getOutPut());
        sb.append(exp.getOutPut());
        if (rParent != null) {
            sb.append(rParent.getOutPut());
        }
        return sb.toString();
    }

    @Override
    public String getError() {
        return exp.getError() + errorLog;
    }
}
