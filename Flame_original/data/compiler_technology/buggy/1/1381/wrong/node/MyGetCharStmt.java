package node;

import frontend.Token;

public class MyGetCharStmt extends Stmt {
    private LVal lVal;

    public MyGetCharStmt(LVal lVal) {
        super(Token.TokenType.GETCHARTK);
        this.lVal = lVal;
    }

    public LVal getLVal() {
        return lVal;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" +  getNodeType() + ">");
        ret.append("\n").append( getType());
        ret.append("\n").append(lVal);
        ret.append("\n<").append( getNodeType()).append("> <END>");
        return ret.toString();
    }
}
