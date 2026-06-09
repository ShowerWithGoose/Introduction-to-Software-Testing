package frontend.Tree;

public class PrimaryExp {
    private Exp exp;
    private LVal lVal;
    private Number number;
    private Character character;

    public PrimaryExp(Exp exp) {
        this.exp = exp;
    }

    public PrimaryExp(LVal lVal) {
        this.lVal = lVal;
    }

    public PrimaryExp(Number number) {
        this.number = number;
    }

    public PrimaryExp(Character character) {
        this.character = character;
    }
}
