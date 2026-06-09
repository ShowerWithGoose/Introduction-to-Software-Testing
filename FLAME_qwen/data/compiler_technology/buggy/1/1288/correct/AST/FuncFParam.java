package AST;

public class FuncFParam {
    private BType bType;
    private Ident ident;
    private boolean isArray = false;
    public FuncFParam(BType bType, Ident ident, boolean isArray) {
        this.bType = bType;
        this.ident = ident;
        this.isArray = isArray;
    }

    public BType getBType() {
        return bType;
    }
    public Ident getIdent() {
        return ident;
    }
    public boolean isArray() {
        return isArray;
    }
}
