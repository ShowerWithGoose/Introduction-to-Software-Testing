package AST;

public class PrimaryExp {
    private Exp exp;
    private LVal lVal;
    private Num num;
    private Cha cha;

    public PrimaryExp(Exp exp) {
        this.exp = exp;
    }
    public PrimaryExp(LVal lVal) {
        this.lVal = lVal;
    }
    public PrimaryExp(Num num) {
        this.num = num;
    }
    public PrimaryExp(Cha cha) {
        this.cha = cha;
    }

}
