package frontend;

public class ForStmt {
    // LVal '=' Exp
    private LVal lVal;
    private Exp exp;
    private Word den;

    public ForStmt() {}

    public void setDen(Word den) {
        this.den = den;
    }

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(den.getLeiBie()).append(" ").append(den.getStr()).append("\n");
        sb.append(exp.toString());
        sb.append("<ForStmt>");
        sb.append("\n");
        return sb.toString();
    }
}
