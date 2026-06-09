package frontend.Tree;

public class LVal {
    private Ident ident;
    private Exp exp;

    public LVal(Ident ident) {
        this.ident = ident;
    }

    public LVal(Ident ident, Exp exp) {
        this.ident = ident;
        this.exp = exp;
    }

    public Ident getIdent() {
        return ident;
    }
}
