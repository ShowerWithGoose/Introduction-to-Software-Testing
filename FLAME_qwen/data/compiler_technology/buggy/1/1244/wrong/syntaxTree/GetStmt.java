package syntaxTree;

import token.TokenType;

public class GetStmt extends Stmt {
    private final LVal lVal;
    private final TokenType bType;

    public GetStmt(final LVal lVal, final TokenType bType) {
        this.lVal = lVal;
        this.bType = bType;
    }
}
