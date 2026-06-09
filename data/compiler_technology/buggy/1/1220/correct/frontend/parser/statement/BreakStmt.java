package frontend.parser.statement;

import frontend.lexer.Token;

public class BreakStmt implements StmtUnit{
    private Token breakTk;
    private Token semicn;

    public BreakStmt(Token breakTk, Token semicn) {
        this.breakTk = breakTk;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(breakTk.syntaxPrint());
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        return sb.toString();
    }
}
