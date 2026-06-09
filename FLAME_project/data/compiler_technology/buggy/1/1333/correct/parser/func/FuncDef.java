package parser.func;

import parser.block.Block;

public class FuncDef {
    private final FuncType funcType;
    private final String ident;
    private final FuncFParams funcFParams;
    private final Block block;

    public FuncDef(FuncType funcType, String ident, FuncFParams funcFParams, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.funcFParams = funcFParams;
        this.block = block;
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.funcType.toString() +
                "IDENFR " + this.ident + "\nLPARENT (\n");
        if (this.funcFParams != null) {
            str.append(this.funcFParams.toString());
        }
        str.append("RPARENT )\n" + this.block.toString() + "<FuncDef>\n");
        return str.toString();
    }
}
