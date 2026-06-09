package frontend.parser.statement;

import frontend.lexer.Token;

public class ContinueStmt implements StmtUnit{
    private Token continueTk;
    private Token semicn;

    public ContinueStmt(Token continueTk, Token semicn) {
        this.continueTk = continueTk;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(continueTk.syntaxPrint());
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        return sb.toString();
    }
}
