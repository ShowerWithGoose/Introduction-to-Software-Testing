package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * Stmt â†’ LVal '=' 'getint''('')'';' // i j
 */
public class StmtLValGetint extends STNode {
    public LVal lVal;
    public Token assign;
    public Token getint;
    public Token lParent;
    public Token rParent;
    public Token semicolon;
}
