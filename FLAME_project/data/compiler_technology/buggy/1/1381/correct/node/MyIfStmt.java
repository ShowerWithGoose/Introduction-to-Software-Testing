package node;

import frontend.Token;

public class MyIfStmt extends Stmt {
    private Cond ifCond;
    private Stmt thenStmt;
    private Stmt elseStmt;

    public MyIfStmt(Cond ifCond, Stmt thenStmt, Stmt elseStmt) {
        super(Token.TokenType.IFTK);
        this.ifCond = ifCond;
        this.thenStmt = thenStmt;
        this.elseStmt = elseStmt;
    }

    public Cond getIfCond() {
        return ifCond;
    }

    public Stmt getThenStmt() {
        return thenStmt;
    }

    public Stmt getElseStmt() {
        return elseStmt;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + getNodeType() + ">");
        ret.append("\n").append(getType());
        ret.append("\n").append(ifCond);
        ret.append("\n").append(thenStmt);
        if (elseStmt != null) ret.append("\n").append(elseStmt);
        ret.append("\n<").append(getNodeType()).append("> <END>");
        return ret.toString();
    }
}