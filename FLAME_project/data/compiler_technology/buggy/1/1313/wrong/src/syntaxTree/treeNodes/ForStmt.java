package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 语句 ForStmt → LVal '=' Exp
 */
public class ForStmt extends STNode {
    public LVal lVal;
    public Token assign;
    public Exp exp;
}
