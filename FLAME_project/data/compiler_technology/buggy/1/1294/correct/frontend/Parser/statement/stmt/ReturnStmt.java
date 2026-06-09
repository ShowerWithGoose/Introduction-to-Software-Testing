package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.expression.Exp;
import frontend.Parser.statement.StmtPort;

public class ReturnStmt implements StmtPort {
    private Token returnTk;
    private Exp exp;
    private Token semicn;

    public ReturnStmt(Token returnTk, Exp exp, Token semicn) {
        this.returnTk = returnTk;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.returnTk.grammarOutput());
        if (this.exp != null) {
            sb.append(this.exp.grammarOutput());
        }
        sb.append(this.semicn.grammarOutput());
        return sb.toString();
    }

}
