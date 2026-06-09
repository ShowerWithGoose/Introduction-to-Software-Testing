package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primaryExp.LVal;

public class LValExpStmt implements StmtUnit{
    //LVal '=' Exp ';'
    private LVal lVal;
    private Token assign;
    private Exp exp;
    private Token semicn;

    public LValExpStmt(LVal lVal, Token assign, Exp exp, Token semicn) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        // LVal '=' Exp ';'
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.syntaxPrint());
        sb.append(assign.syntaxPrint());
        sb.append(exp.syntaxPrint());
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        return sb.toString();
    }
}
