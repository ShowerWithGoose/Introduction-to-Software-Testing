package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * Stmt â†’ LVal '=' 'getchar''('')'';' // i j
 */
public class StmtLValGetchar extends STNode {
    public LVal lVal;
    public Token assign;
    public Token getchar;
    public Token lParent;
    public Token rParent;
    public Token semicolon;
}
