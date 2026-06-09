package node;

import frontend.Token;

public class MyReturnStmt extends Stmt {
    private Exp exp;

    public MyReturnStmt(Exp exp) {
        super(Token.TokenType.RETURNTK);
        this.exp = exp;
    }

    public Exp getExp() {
        return exp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + getNodeType() + ">");
        ret.append("\n").append(getType());
        if (exp != null) ret.append("\n").append(exp);
        ret.append("\n<").append(getNodeType()).append("> <END>");
        return ret.toString();
    }
}
