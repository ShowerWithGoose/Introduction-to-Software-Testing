package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.Exp.Exp;
import frontend.Token;
import frontend.TokenType;

// [Exp] ';' // i
public class ExpStmt extends Stmt {
    private Exp exp;

    public ExpStmt(Exp exp) {
        this.exp = exp;
    }

    public ExpStmt() {
    }

    @Override
    public void print() {
        if(exp != null) {
            exp.print();
        }
        AST.ast.addLine(TokenType.SEMICN + " ;");

        super.print();
    }
}
