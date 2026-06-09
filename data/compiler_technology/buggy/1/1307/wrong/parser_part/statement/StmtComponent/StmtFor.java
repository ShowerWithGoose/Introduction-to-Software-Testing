package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.expression.Cond;
import parser_part.statement.Stmt;

public class StmtFor implements StmtComponent {
    private Token forToken;
    private Token leftParent;
    private ForStmt forStmt1;
    private Token semicn1;
    private Cond cond;
    private Token semicn2;
    private ForStmt forStmt2;
    private Token rightParent;
    private Stmt stmt;

    public StmtFor(Token forToken, Token leftParent, ForStmt forStmt1, Token semicn1, Cond cond, Token semicn2, ForStmt forStmt2, Token rightParent, Stmt stmt) {
        this.forToken = forToken;
        this.leftParent = leftParent;
        this.forStmt1 = forStmt1;
        this.semicn1 = semicn1;
        this.cond = cond;
        this.semicn2 = semicn2;
        this.forStmt2 = forStmt2;
        this.rightParent = rightParent;
        this.stmt = stmt;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(forToken.toString() + leftParent.toString());
        if (forStmt1 != null) {
            sb.append(forStmt1);
        }
        sb.append(semicn1);
        if (cond != null) {
            sb.append(cond);
        }
        sb.append(semicn2);
        if (forStmt2 != null) {
            sb.append(forStmt2);
        }
        sb.append(rightParent).append(stmt);
        return sb.toString();
    }

    public Stmt getStmt() {
        return stmt;
    }
}
