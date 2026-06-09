package stmtRelated;

import assist.Node;

public class PrintfStmt extends Node {
    //PrintfStmt -> 'printf''('StringConst{','Exp}')'';' //i,j
    public PrintfStmt() {
        this.type = SyntaxType.Private;
    }
}
