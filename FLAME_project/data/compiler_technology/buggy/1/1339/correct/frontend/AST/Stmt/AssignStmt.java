package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.Exp.Exp;
import frontend.AST.Exp.LVal;
import frontend.TokenType;

//LVal '=' Exp ';' // i
public class AssignStmt extends Stmt{
    private LVal lval;
    private Exp exp;

    public AssignStmt(LVal lval, Exp exp) {
        this.lval = lval;
        this.exp = exp;
    }

    @Override
    public void print() {
        lval.print();
        AST.ast.addLine(TokenType.ASSIGN + " =");
        exp.print();
        AST.ast.addLine(TokenType.SEMICN + " ;");
        super.print();
    }
}
