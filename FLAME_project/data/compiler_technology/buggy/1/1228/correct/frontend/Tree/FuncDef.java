package frontend.Tree;

public class FuncDef {
    private FuncType funcType;
    private Ident ident;
    private FuncFParams funcFParams;

    private Block block;

    public FuncDef(FuncType funcType, Ident ident, FuncFParams funcFParams, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.funcFParams = funcFParams;
        this.block = block;
    }

}
