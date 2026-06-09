package frontend.nonTerminal.Stmt;

import frontend.nonTerminal.Block;
import frontend.nonTerminal.Stmt.Stmt;
import frontend.tool.myWriter;

public class BlockStmt extends Stmt {
    public Block block;

    @Override
    public void visit() {
        block.visit();
        myWriter.writeNonTerminal("Stmt");
    }
}
