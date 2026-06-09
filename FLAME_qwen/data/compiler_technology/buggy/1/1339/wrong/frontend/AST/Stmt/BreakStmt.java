package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.TokenType;

//'break' ';'
public class BreakStmt extends Stmt{
    public BreakStmt() {
    }

    public void print() {
        AST.ast.addLine(TokenType.BREAKTK + " break");
        AST.ast.addLine(TokenType.SEMICN + " ;");
        super.print();
    }
}
