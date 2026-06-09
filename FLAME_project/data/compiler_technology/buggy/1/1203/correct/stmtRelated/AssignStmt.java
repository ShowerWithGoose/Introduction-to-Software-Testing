package stmtRelated;

import assist.Node;

public class AssignStmt extends Node {
    // AssignStmt -> LVal '=' Exp';' //i
    public AssignStmt() {
        this.type = SyntaxType.Private;
    }
}
