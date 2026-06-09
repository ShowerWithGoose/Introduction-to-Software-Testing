package stmtRelated;

import assist.Node;

public class ReturnStmt extends Node {
    //ReturnStmt -> 'return'[Exp]';' //i
    public ReturnStmt() {
        this.type = SyntaxType.Private;
    }
}
