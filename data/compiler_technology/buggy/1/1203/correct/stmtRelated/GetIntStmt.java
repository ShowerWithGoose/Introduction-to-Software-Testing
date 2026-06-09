package stmtRelated;

import assist.Node;

public class GetIntStmt extends Node {
    //GetIntStmt -> LVal '=' 'getint''('')'';' //i,j
    public GetIntStmt() {
        this.type = SyntaxType.Private;
    }
}
