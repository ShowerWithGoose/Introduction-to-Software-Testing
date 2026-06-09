package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 语句 Stmt → 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
 */
public class StmtIf extends STNode {
    public Token tokenIf;
    public Token lParent;
    public Cond cond;
    public Token rParent;
    public Stmt stmt;
    public Token tokenElse;
    public Stmt elseStmt;
}
