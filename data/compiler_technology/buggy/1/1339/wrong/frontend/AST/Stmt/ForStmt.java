package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.Exp.Cond;
import frontend.AST.Exp.Exp;
import frontend.AST.Exp.LVal;
import frontend.AST.SyntaxNode;
import frontend.TokenType;

//ForStmt â†’ 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
public class ForStmt implements SyntaxNode {
    private LVal lval;
    private Exp exp;

    public ForStmt(LVal lval, Exp exp) {
        this.lval = lval;
        this.exp = exp;
    }

    @Override
    public void print() {
        lval.print();
        AST.ast.addLine(TokenType.ASSIGN + " =");
        exp.print();
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<ForStmt>";
    }
}
