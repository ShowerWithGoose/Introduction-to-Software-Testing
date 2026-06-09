package syntacticanalysis.node.stmts;

import syntacticanalysis.node.Block;

public class Stmt3 extends Stmt {
    private String name = "<Stmt>";
    private Block block;

    public Stmt3(Block block) {
        this.block = block;
    }

    @Override
    public String syntaxOutput() {
        return block.syntaxOutput() + "\n" + name;
    }
}
