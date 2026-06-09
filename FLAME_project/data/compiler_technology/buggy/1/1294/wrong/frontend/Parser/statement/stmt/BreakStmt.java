package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.statement.StmtPort;

public class BreakStmt implements StmtPort {
    private Token breakTk;
    private Token semicn;
    public BreakStmt(Token breakTk, Token semicn) {
        this.breakTk = breakTk;
        this.semicn = semicn;
    }
    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.breakTk.grammarOutput());
        sb.append(this.semicn.grammarOutput());
        return sb.toString();
    }
}
