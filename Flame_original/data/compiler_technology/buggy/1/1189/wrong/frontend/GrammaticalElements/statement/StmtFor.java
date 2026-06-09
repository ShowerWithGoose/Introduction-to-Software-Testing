package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.expression.Cond;
import frontend.Token;

public class StmtFor extends StmtEle{
    /*Token for_;
    Token leftParen;
    ForStmt* forStmt1;
    Token semicolon1;
    Cond* cond;
    Token semicolon2;
    ForStmt* forStmt2;
    Token rightParen;
    Stmt stmt;*/
    private Token for_;
    private Token leftParen;
    private ForStmt forStmt1;
    private Token semicolon1;
    private Cond cond;
    private Token semicolon2;
    private ForStmt forStmt2;
    private Token rightParen;
    private Stmt stmt;

    public StmtFor(Token for_, Token leftParen, ForStmt forStmt1, Token semicolon1, Cond cond, Token semicolon2, ForStmt forStmt2, Token rightParen, Stmt stmt) {
        this.for_ = for_;
        this.leftParen = leftParen;
        this.forStmt1 = forStmt1;
        this.semicolon1 = semicolon1;
        this.cond = cond;
        this.semicolon2 = semicolon2;
        this.forStmt2 = forStmt2;
        this.rightParen = rightParen;
        this.stmt = stmt;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(for_.toString());
        sb.append(leftParen.toString());
        if (forStmt1 != null) {
            sb.append(forStmt1.toString());
        }
        sb.append(semicolon1.toString());
        if (cond != null) {
            sb.append(cond.toString());
        }
        sb.append(semicolon2.toString());
        if (forStmt2 != null) {
            sb.append(forStmt2.toString());
        }
        sb.append(rightParen.toString());
        sb.append(stmt.toString());
        return sb.toString();
    }
}
