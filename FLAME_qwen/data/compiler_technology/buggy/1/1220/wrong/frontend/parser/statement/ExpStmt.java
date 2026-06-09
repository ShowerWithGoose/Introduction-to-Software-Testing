package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class ExpStmt implements StmtUnit{
    // [Exp] ';'
    private Exp exp;
    private Token semicn;

    public ExpStmt(Exp exp, Token semicn) {
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        //[Exp] ';'
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.syntaxPrint());
        }
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        return sb.toString();
    }
}
