package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * Stmt â†’ 'return' [Exp] ';' // i
 */
public class StmtReturn extends STNode {
    public Token tokenReturn;
    public Exp exp;
    public Token semicolon;
}
