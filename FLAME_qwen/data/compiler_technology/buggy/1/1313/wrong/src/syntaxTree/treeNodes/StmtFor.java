package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 语句 Stmt → 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
 */
public class StmtFor extends STNode {
    public Token tokenFor;
    public Token lParent;
    public ForStmt forStmt1;
    public Token semicolon1;
    public Cond cond;
    public Token semicolon2;
    public ForStmt forStmt2;
    public Token rParent;
    public Stmt stmt;
}
