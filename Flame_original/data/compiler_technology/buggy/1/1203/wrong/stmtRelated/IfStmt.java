package stmtRelated;

import assist.Node;

public class IfStmt extends Node {
    //IfStmt -> 'if''('Cond')'Stmt['else'Stmt] //j
    public IfStmt() {
        this.type = SyntaxType.Private;
    }
}
