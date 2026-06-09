package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.Exp.Cond;
import frontend.Token;
import frontend.TokenType;

//'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
public class IfStmt extends Stmt{
    private Cond cond;
    private Stmt stmt1;
    private Stmt stmt2;

    public IfStmt(Cond cond, Stmt stmt1, Stmt stmt2) {
        this.cond = cond;
        this.stmt1 = stmt1;
        this.stmt2 = stmt2;
    }

    public IfStmt(Cond cond, Stmt stmt1) {
        this.cond = cond;
        this.stmt1 = stmt1;
    }

    @Override
    public void print() {
        AST.ast.addLine(TokenType.IFTK + " if");
        AST.ast.addLine(TokenType.LPARENT + " (");
        cond.print();
        AST.ast.addLine(TokenType.RPARENT + " )");
        stmt1.print();
        if(stmt2 != null) {
            AST.ast.addLine(TokenType.ELSETK + " else");
            stmt2.print();
        }
        super.print();
    }
}
