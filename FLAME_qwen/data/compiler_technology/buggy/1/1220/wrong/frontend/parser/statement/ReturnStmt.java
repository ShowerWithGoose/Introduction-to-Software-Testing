package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class ReturnStmt implements StmtUnit{
    private Token returnTk;
    private Exp exp;
    private Token semicn;

    public ReturnStmt(Token returnTk, Exp exp, Token semicn) {
        this.returnTk = returnTk;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        //'return' [Exp] ';'
        StringBuilder sb = new StringBuilder();
        sb.append(returnTk.syntaxPrint());
        if (exp!= null) {
            sb.append(exp.syntaxPrint());
        }
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        return sb.toString();
    }
}
