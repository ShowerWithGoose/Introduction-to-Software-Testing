package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Expression.Exp;
import frontend.Parser.Expression.LVal;
import frontend.Parser.Statement.StmtEle;

public class LvalExpStmtEle implements StmtEle {
    private LVal lVal;
    private Token assignToken;
    private Exp exp;
    private Token semicnToken;

    public LvalExpStmtEle(LVal lVal, Token assignToken, Exp exp, Token semicnToken) {
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.printString());
        sb.append(assignToken);
        sb.append(exp.printString());
        if (semicnToken != null) {
            sb.append(semicnToken);
        }
        return sb.toString();
    }
}
