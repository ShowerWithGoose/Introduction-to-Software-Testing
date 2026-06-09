package AST;

public class FuncDef {
    private FuncType type;
    private Ident id;
    private FuncFParams params;
    private Block block;
    public FuncDef(FuncType type, Ident id, FuncFParams params, Block block) {
        this.type = type;
        this.id = id;
        this.params = params;
        this.block = block;
    }

}
