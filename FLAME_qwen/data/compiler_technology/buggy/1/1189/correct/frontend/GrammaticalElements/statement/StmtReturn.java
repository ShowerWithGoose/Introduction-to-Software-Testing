package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.expression.Exp;
import frontend.Token;

public class StmtReturn extends StmtEle{
    private Token return_;
    private Exp exp;
    private Token semicolon;

    public StmtReturn(Token return_, Token semicolon) {
        this.return_ = return_;
        this.semicolon = semicolon;
    }

    public StmtReturn(Token return_, Exp exp, Token semicolon) {
        this.return_ = return_;
        this.exp = exp;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(return_.toString());
        if (exp != null) {
            sb.append(exp.toString());
        }
        sb.append(semicolon.toString());
        return sb.toString();
    }
}
