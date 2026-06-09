package syntacticanalysis.node.function;

import lexicalanalysis.Token;
import syntacticanalysis.node.Block;

public class MainFuncDef {
    private String name = "<MainFuncDef>";
    private Token inttk;
    private Token maintk;
    private Token lparent;
    private Token rparent;
    private Block block;

    public MainFuncDef(Token inttk, Token maintk,
                       Token lparent, Token rparent,
                       Block block) {
        this.inttk = inttk;
        this.maintk = maintk;
        this.lparent = lparent;
        this.rparent = rparent;
        this.block = block;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(inttk);
        sb.append("\n");
        sb.append(maintk);
        sb.append("\n");
        sb.append(lparent);
        sb.append("\n");
        sb.append(rparent);
        sb.append("\n");
        sb.append(block.syntaxOutput());
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
