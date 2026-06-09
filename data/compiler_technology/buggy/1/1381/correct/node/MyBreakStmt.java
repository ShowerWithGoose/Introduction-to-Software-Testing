package node;

import frontend.Token;

public class MyBreakStmt extends Stmt {
    public MyBreakStmt() {
        super(Token.TokenType.BREAKTK);
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + getNodeType() + ">");
        ret.append("\n").append(getType());
        ret.append("\n<").append(getNodeType()).append("> <END>");
        return ret.toString();
    }
}
