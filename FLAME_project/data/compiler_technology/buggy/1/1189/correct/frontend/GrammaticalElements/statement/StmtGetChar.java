package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.expression.LVal;
import frontend.Token;

public class StmtGetChar extends StmtEle{
    /*LVal* lVal;
    Token assign; // '='
    Token getchar;
    Token leftParen;
    Token rightParen;
    Token semicolon; // ';'*/
    private LVal lVal;
    private Token assign;
    private Token getChar;
    private Token leftParen;
    private Token rightParen;
    private Token semicolon;

    public StmtGetChar(LVal lVal, Token assign, Token getChar, Token leftParen, Token rightParen, Token semicolon) {
        this.lVal = lVal;
        this.assign = assign;
        this.getChar = getChar;
        this.leftParen = leftParen;
        this.rightParen = rightParen;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assign.toString());
        sb.append(getChar.toString());
        sb.append(leftParen.toString());
        sb.append(rightParen.toString());
        sb.append(semicolon.toString());
        return sb.toString();
    }
}
