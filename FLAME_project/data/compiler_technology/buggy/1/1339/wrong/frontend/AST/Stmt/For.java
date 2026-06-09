package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.Exp.Cond;
import frontend.TokenType;

//'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
public class For extends Stmt {
    private ForStmt forStmt1;
    private Cond cond;
    private ForStmt forStmt2;
    private Stmt stmt;

    public For(ForStmt forStmt1, Cond cond, ForStmt forStmt2, Stmt stmt) {
        this.forStmt1 = forStmt1;
        this.cond = cond;
        this.forStmt2 = forStmt2;
        this.stmt = stmt;
    }

    @Override
    public void print() {
        AST.ast.addLine(TokenType.FORTK + " for");
        AST.ast.addLine(TokenType.LPARENT + " (");
        if(forStmt1 != null) {
            forStmt1.print();
        }
        AST.ast.addLine(TokenType.SEMICN + " ;");
        if(cond != null) {
            cond.print();
        }
        AST.ast.addLine(TokenType.SEMICN + " ;");
        if(forStmt2 != null) {
            forStmt2.print();
        }
        AST.ast.addLine(TokenType.RPARENT + " )");
        stmt.print();
        super.print();
    }
}
