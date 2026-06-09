package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.Exp.Exp;
import frontend.TokenType;

//'return' [Exp] ';' // i
public class ReturnStmt extends Stmt{
    private Exp exp;

    public ReturnStmt(Exp exp) {
        this.exp = exp;
    }

    public ReturnStmt() {
    }

    @Override
    public void print() {
        AST.ast.addLine(TokenType.RETURNTK + " return");
        if(exp != null) {
            exp.print();
        }
        AST.ast.addLine(TokenType.SEMICN + " ;");
        super.print();
    }
}
