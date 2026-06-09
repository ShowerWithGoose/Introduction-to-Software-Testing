package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * Stmt â†’ 'continue' ';' // i
 */
public class StmtContinue extends STNode {
    public Token tokenContinue;
    public Token semicolon;
}
