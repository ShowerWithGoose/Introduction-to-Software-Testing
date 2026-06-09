package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Expression.Exp;
import frontend.Parser.Statement.StmtEle;

public class ExpStmtEle implements StmtEle {
    private Exp exp;    // 可选
    private Token semicnToken;

    public ExpStmtEle(Exp exp, Token semicnToken) {
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.printString());
        }
        if (semicnToken != null) {
            sb.append(semicnToken);
        }
        return sb.toString();
    }
}
