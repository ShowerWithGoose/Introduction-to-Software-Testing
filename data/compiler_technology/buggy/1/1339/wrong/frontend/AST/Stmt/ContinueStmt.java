package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.TokenType;

//'continue' ';'
public class ContinueStmt extends Stmt{
    public ContinueStmt() {
    }

    public void print() {
        AST.ast.addLine(TokenType.CONTINUETK + " continue");
        AST.ast.addLine(TokenType.SEMICN + " ;");
        super.print();
    }
}
