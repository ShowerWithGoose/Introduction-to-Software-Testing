package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.statement.StmtPort;

public class ContinueStmt implements StmtPort {
    private Token continueTk;
    private Token semicn;
    public ContinueStmt(Token continueTk, Token semicn) {
        this.continueTk = continueTk;
        this.semicn = semicn;
    }
    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.continueTk.grammarOutput());
        sb.append(this.semicn.grammarOutput());
        return sb.toString();
    }
}
