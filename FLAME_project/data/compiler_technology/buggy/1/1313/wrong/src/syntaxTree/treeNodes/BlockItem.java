package src.syntaxTree.treeNodes;

import src.syntaxTree.STNode;
import src.syntaxTree.enums.BlockItemType;

/**
 * 语句块项 BlockItem → Decl | Stmt
 */
public class BlockItem extends STNode {
    public BlockItemType blockItemType;
    public Decl decl;
    public Stmt stmt;
}
