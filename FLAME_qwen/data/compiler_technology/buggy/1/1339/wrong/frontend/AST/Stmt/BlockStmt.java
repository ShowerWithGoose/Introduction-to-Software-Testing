package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.TokenType;

import java.util.ArrayList;

//BlockStmt â†’ Block
public class BlockStmt extends Stmt {

    private Block block;

    public BlockStmt(Block block) {
        this.block = block;
    }

    @Override
    public void print() {
        block.print();
        super.print();
    }
}
