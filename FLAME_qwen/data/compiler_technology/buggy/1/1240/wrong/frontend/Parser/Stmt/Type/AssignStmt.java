package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.Exp;
import frontend.Parser.Exp.Type.LVal;

public class AssignStmt implements StmtInter {
    // LVal '=' Exp
    private final LVal lval;
    private final LexType assign;
    private final Exp exp;

    public AssignStmt(LVal lval, LexType assign, Exp exp) {
        this.lval = lval;
        this.assign = assign;
        this.exp = exp;
    }

    @Override
    public String toString() {
        return lval.toString() + assign.toString() +
                exp.toString();
    }
}
