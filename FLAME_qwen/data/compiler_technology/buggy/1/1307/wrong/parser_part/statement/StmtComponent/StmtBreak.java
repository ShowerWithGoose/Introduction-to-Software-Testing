package parser_part.statement.StmtComponent;

import lexer_part.Token;

public class StmtBreak implements StmtComponent {
    private Token breakToken;
    private Token semicn;

    public StmtBreak(Token breakToken, Token semicn) {
        this.breakToken = breakToken;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        return breakToken.toString() + semicn.toString();
    }
}
