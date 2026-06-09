package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.expression.Exp;
import frontend.Parser.statement.StmtPort;

public class ExpStmt implements StmtPort {
    private Exp exp;
    private Token semicn;

    public ExpStmt(Exp exp, Token semicn) {
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        if (this.exp != null) {
            sb.append(exp.grammarOutput());
        }
        sb.append(semicn.grammarOutput());
        return sb.toString();
    }
}
