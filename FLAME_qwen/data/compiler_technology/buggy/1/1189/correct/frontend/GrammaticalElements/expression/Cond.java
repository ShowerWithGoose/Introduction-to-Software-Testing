package frontend.GrammaticalElements.expression;

public class Cond {
    /*const string name = "<Cond>";
    LOrExp* lOrExp;*/
    private final String name = "<Cond>";
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String toString() {
        return lOrExp.toString() +
                this.name + '\n';
    }
}
