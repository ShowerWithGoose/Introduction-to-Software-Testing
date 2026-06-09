package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.expression.Cond;
import frontend.parser.statement.ForStmt;

public class StmtFor implements StmtEle{
    private Token forTk; // 'while'
    private Token leftParent; // '('
    private ForStmt forStmt1;
    private Token semicn1;
    private Cond cond;
    private Token semicn2;
    private ForStmt forStmt2;
    private Token rightParent; // ')'
    private Stmt stmt;

    public StmtFor(Token forTk, Token leftParent, ForStmt forStmt1, Token semicn1, Cond cond, Token semicn2, ForStmt forStmt2, Token rightParent, Stmt stmt) {
        this.forTk = forTk;
        this.leftParent = leftParent;
        this.forStmt1 = forStmt1;   // MAY exist
        this.semicn1 = semicn1;
        this.cond = cond;   // MAY exist
        this.semicn2 = semicn2;
        this.forStmt2 = forStmt2;   // MAY exist
        this.rightParent = rightParent;
        this.stmt = stmt;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.forTk.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        if (forStmt1 != null) {
            sb.append(forStmt1.syntaxOutput());
        }
        sb.append(this.semicn1.syntaxOutput());
        if (cond != null) {
            sb.append(cond.syntaxOutput());
        }
        sb.append(this.semicn2.syntaxOutput());
        if (forStmt2 != null) {
            sb.append(forStmt2.syntaxOutput());
        }
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.stmt.syntaxOutput());
        return sb.toString();
    }
}
