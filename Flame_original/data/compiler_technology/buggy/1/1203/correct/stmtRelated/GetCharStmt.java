package stmtRelated;

import assist.Node;

public class GetCharStmt extends Node {
    //GetCharStmt -> LVal '=' 'getchar''('')'';' //i,j
    public GetCharStmt() {
        this.type = SyntaxType.Private;
    }
}
