package syntaxTree;

import token.TokenType;

public class ControlStmt extends Stmt {
    final TokenType controlType;

    public ControlStmt(TokenType controlType) {
        this.controlType = controlType;
    }
}
