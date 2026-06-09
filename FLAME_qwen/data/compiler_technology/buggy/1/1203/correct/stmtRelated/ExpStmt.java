package stmtRelated;

import assist.Node;

public class ExpStmt extends Node {
    //ExpStmt -> [Exp]';' //i
    public ExpStmt() {
        this.type = SyntaxType.Private;
    }
}
