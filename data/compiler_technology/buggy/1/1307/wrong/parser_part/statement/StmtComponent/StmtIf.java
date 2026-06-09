package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.expression.Cond;
import parser_part.statement.Stmt;

public class StmtIf implements StmtComponent {
    private Token ifToken;
    private Token leftParent;
    private Cond cond;
    private Token rightParent;
    private Stmt stmt;
    private Token elseToken;
    private Stmt elseStmt;

    public StmtIf(Token ifToken, Token leftParent, Cond cond, Token rightParent, Stmt stmt, Token elseToken, Stmt elseStmt) {
        this.ifToken = ifToken;
        this.leftParent = leftParent;
        this.cond = cond;
        this.rightParent = rightParent;
        this.stmt = stmt;
        this.elseToken = elseToken;
        this.elseStmt = elseStmt;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(ifToken.toString());
        sb.append(leftParent).append(cond.toString()).append(rightParent).append(stmt);
        if (elseToken != null) {
            sb.append(elseToken).append(elseStmt);
        }
        return sb.toString();
    }

    public Stmt getStmt() {
        return stmt;
    }

    public Stmt getElseStmt() {
        return elseStmt;
    }
}
