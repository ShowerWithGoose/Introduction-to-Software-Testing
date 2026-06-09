package node;

import frontend.Token;

public class MyContinueStmt extends Stmt {
    public MyContinueStmt() {
        super(Token.TokenType.CONTINUETK);
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + getNodeType() + ">");
        ret.append("\n").append(getType());
        ret.append("\n<").append(getNodeType()).append("> <END>");
        return ret.toString();
    }
}
