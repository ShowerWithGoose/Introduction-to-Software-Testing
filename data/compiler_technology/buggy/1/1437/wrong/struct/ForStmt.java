package struct;

import token.Token;

/* ForStmt â†’ LVal '=' Exp */
public class ForStmt {
    private final LVal lVal;
    private final Token assignToken;
    private final Exp exp;

    public ForStmt(LVal lVal, Token assignToken, Exp exp) {
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.exp = exp;
    }

    public LVal getLVal() {
        return lVal;
    }

    public Token getAssignToken() {
        return assignToken;
    }

    public Exp getExp() {
        return exp;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assignToken.toString());
        sb.append(exp.toString());
        sb.append("<ForStmt>\n");
        return sb.toString();
    }
}
