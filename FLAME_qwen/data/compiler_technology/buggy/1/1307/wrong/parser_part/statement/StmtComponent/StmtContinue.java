package parser_part.statement.StmtComponent;

import lexer_part.Token;

public class StmtContinue implements StmtComponent {
    private Token continueToken;
    private Token semicn;

    public StmtContinue(Token continueToken, Token semicn) {
        this.continueToken = continueToken;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        return continueToken.toString() + semicn.toString();
    }
}
