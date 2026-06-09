package frontend.Tree;

public class LAndExp {
    private LAndExp lAndExp;
    private EqExp eqExp;

    public LAndExp(LAndExp lAndExp, EqExp eqExp) {
        this.lAndExp = lAndExp;
        this.eqExp = eqExp;
    }
    public LAndExp(EqExp eqExp) {
        this.eqExp = eqExp;
    }
}
