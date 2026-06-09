package node;

import frontend.Token;

public class MyForStmt extends Stmt {
    private ForStmt forStmt1;
    private Cond cond;
    private ForStmt forStmt2;
    private Stmt stmt;

    public MyForStmt(ForStmt forStmt1, Cond cond, ForStmt forStmt2, Stmt stmt) {
        super(Token.TokenType.FORTK);
        this.forStmt1 = forStmt1;
        this.cond = cond;
        this.forStmt2 = forStmt2;
        this.stmt = stmt;
    }

    public ForStmt getForStmt1() {
        return forStmt1;
    }

    public Cond getCond() {
        return cond;
    }

    public ForStmt getForStmt2() {
        return forStmt2;
    }

    public Stmt getStmt() {
        return stmt;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + getNodeType() + ">");
        ret.append("\n").append(getType());
        ret.append("\n").append(forStmt1);
        ret.append("\n").append(cond);
        ret.append("\n").append(forStmt2);
        ret.append("\n").append(stmt);
        ret.append("\n<").append(getNodeType()).append("> <END>");
        return ret.toString();
    }
}