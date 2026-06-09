package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.Node;
import parser_part.expression.Exp;
import parser_part.expression.primaryExpression.LVal;

public class ForStmt implements Node {
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lVal, Token assign, Exp exp) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }

    @Override
    public String toString() {
        return lVal.toString() + assign.toString() + exp.toString() + "<ForStmt>\n";
    }
}
