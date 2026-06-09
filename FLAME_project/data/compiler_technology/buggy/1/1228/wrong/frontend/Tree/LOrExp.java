package frontend.Tree;

public class LOrExp {
    private LOrExp lOrExp;
    private LAndExp lAndExp;

    public LOrExp(LOrExp lOrExp, LAndExp lAndExp) {
        this.lOrExp = lOrExp;
        this.lAndExp = lAndExp;
    }

    public LOrExp(LAndExp lAndExp) {
        this.lAndExp = lAndExp;
    }
}
