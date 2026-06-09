package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * Stmt â†’ 'break' ';' // i
 */
public class StmtBreak extends STNode {
    public Token tokenBreak;
    public Token semicolon;
}
