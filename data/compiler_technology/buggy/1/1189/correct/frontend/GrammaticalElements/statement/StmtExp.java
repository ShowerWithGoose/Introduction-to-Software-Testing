package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.expression.Exp;
import frontend.Token;

public class StmtExp extends StmtEle{
    private Exp exp;
    private Token semicolon; // ';'

    public StmtExp(Token semicolon) {
        this.semicolon = semicolon;
    }

    public StmtExp(Exp exp, Token semicolon) {
        this.exp = exp;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.toString());
        }
        sb.append(semicolon.toString());
        return sb.toString();
    }
}
