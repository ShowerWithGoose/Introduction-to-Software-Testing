package stmtRelated;

import assist.Node;

public class RecStmt extends Node {
    //RecStmt -> 'for''('[ForStmt]';'[Cond]';'[ForStmt]')'Stmt
    public RecStmt() {
        this.type = SyntaxType.Private;
    }
}
