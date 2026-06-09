package AST;

public class LVal {
    private Ident ident;
    private Exp exp;
    private boolean isArray = false;
    public LVal(Ident ident, Exp exp) {
        this.ident = ident;
        this.exp = exp;
    }

    public Ident getIdent() {
        return ident;
    }
    public Exp getExp() {
        return exp;
    }
    public boolean isArray() {
        return isArray;
    }
}
