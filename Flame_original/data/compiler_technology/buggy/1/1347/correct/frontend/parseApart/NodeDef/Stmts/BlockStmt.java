package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Block;
import frontend.parseApart.NodeDef.Normal.Stmt;

public class BlockStmt extends Stmt {
    private Block block;

    public BlockStmt() {

    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public String returnSymbolType() {
        String string = "<Stmt>";
        return string;
    }
}
