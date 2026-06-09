package syntaxTree;

import java.util.ArrayList;

public class BlockStmt extends Stmt {
    final ArrayList<BlockItem> blockItems;

    public BlockStmt(ArrayList<BlockItem> blockItems) {
        this.blockItems = blockItems;
    }
}
