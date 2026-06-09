package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;
import src.syntaxTree.enums.StmtType;

/**
 * 语句 Stmt → LVal '=' Exp ';' // i
 * | [Exp] ';' // i
 * | Block
 * | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
 * | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
 * | 'break' ';' | 'continue' ';' // i
 * | 'return' [Exp] ';' // i
 * | LVal '=' 'getint''('')'';' // i j
 * | LVal '=' 'getchar''('')'';' // i j
 * | 'printf''('StringConst {','Exp}')'';' // i j
 */
public class Stmt extends STNode {
    public StmtType stmtType;
    public StmtLValAssign stmtLValAssign;
    public Exp exp;
    public Token semicolon;
    public Block block;
    public StmtIf stmtIf;
    public StmtFor stmtFor;
    public StmtBreak stmtBreak;
    public StmtContinue stmtContinue;
    public StmtReturn stmtReturn;
    public StmtLValGetint stmtLValGetint;
    public StmtLValGetchar stmtLValGetchar;
    public StmtPrintf stmtPrintf;

}
