package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.expression.LVal;
import frontend.Token;

public class StmtGetInt extends StmtEle{
    private LVal lVal;
    private Token assign;
    private Token getInt;
    private Token leftParen;
    private Token rightParen;
    private Token semicolon;

    public StmtGetInt(LVal lVal, Token assign, Token getInt, Token leftParen, Token rightParen, Token semicolon) {
        this.lVal = lVal;
        this.assign = assign;
        this.getInt = getInt;
        this.leftParen = leftParen;
        this.rightParen = rightParen;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assign.toString());
        sb.append(getInt.toString());
        sb.append(leftParen.toString());
        sb.append(rightParen.toString());
        sb.append(semicolon.toString());
        return sb.toString();
    }
}
