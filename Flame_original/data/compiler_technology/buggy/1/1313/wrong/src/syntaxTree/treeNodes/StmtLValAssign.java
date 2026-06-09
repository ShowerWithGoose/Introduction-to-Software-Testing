package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 语句 Stmt → LVal '=' Exp ';' // i
 */
public class StmtLValAssign extends STNode {
    public LVal lVal;
    public Token assign;
    public Exp exp;
    public Token semicolon;
}
