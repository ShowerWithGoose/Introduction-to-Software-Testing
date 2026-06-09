package src.syntaxTree.treeNodes;

import src.syntaxTree.STNode;
import src.syntaxTree.enums.DeclType;

/**
 * 声明 Decl → ConstDecl | VarDecl
 */
public class Decl extends STNode {
    public DeclType declType;
    public ConstDecl constDecl;
    public VarDecl varDecl;
}
