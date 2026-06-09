package syntacticanalysis.node.function;

import lexicalanalysis.Token;
import syntacticanalysis.node.Block;

public class FuncDef {
    private String name = "<FuncDef>";
    private FuncType funcType;
    private Token ident;
    private Token lparent;
    private FuncFParams funcFParams;
    private Token rparent;
    private Block block;

    public FuncDef(FuncType funcType, Token ident, Token lparent, FuncFParams funcFParams,
                   Token rparent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lparent = lparent;
        this.funcFParams = funcFParams;
        this.rparent = rparent;
        this.block = block;
    }

    public String syntaxOutput()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.syntaxOutput());
        sb.append("\n");
        sb.append(ident);
        sb.append("\n");
        sb.append(lparent);
        if (funcFParams != null) {
            sb.append("\n");
            sb.append(funcFParams.syntaxOutput());
        }
        sb.append("\n");
        sb.append(rparent);
        sb.append("\n");
        sb.append(block.syntaxOutput());
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
