package frontend.Parser.Stmt.Type;

import frontend.Parser.Exp.Type.Exp;

public class ExpStmt implements StmtInter{
    // [Exp]
    public Exp exp;

    public ExpStmt(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        return exp.toString();
    }
}
