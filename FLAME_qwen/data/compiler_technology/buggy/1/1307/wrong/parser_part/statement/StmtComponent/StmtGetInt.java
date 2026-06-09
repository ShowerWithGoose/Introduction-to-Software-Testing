package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.expression.primaryExpression.LVal;

public class StmtGetInt implements StmtComponent {
    private LVal lVal;
    private Token assign;
    private Token getInt;
    private Token leftParent;
    private Token rightParent;
    private Token semicn;

    public StmtGetInt(LVal lVal, Token assign, Token getInt, Token leftParent, Token rightParent, Token semicn) {
        this.lVal = lVal;
        this.assign = assign;
        this.getInt = getInt;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        return lVal.toString() + assign.toString() + getInt.toString() +
                leftParent.toString() + rightParent.toString() + semicn.toString();
    }
}
