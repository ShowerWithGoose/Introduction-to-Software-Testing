package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.expression.Exp;
import parser_part.expression.primaryExpression.LVal;

public class StmtAssign implements StmtComponent {
    private LVal lVal;
    private Token assign;
    private Exp exp;
    private Token semicn;

    public StmtAssign(LVal lVal, Token assign, Exp exp, Token semicn) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        return lVal.toString() + assign.toString() + exp.toString() + semicn.toString();
    }
}
