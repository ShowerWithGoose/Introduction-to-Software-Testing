package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.Exp.Cond;

//| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
public class StmtFor implements StmtInf{
    private Token forTk;
    private Token lparent;
    private ForStmt forStmt1;
    private Token semicn1;
    private Cond cond;
    private Token semicn2;
    private ForStmt forStmt2;
    private Token rparent;
    private Stmt stmt;
    public StmtFor(Token forTk, Token lparent, ForStmt forStmt1,Token semicn1, Cond cond, Token semicn2, ForStmt forStmt2,Token rparent, Stmt stmt) {
        this.forTk = forTk;
        this.lparent = lparent;
        this.forStmt1 = forStmt1;
        this.semicn1 = semicn1;
        this.cond = cond;
        this.semicn2 = semicn2;
        this.forStmt2 = forStmt2;
        this.rparent = rparent;
        this.stmt = stmt;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.forTk.toString());
        sb.append(lparent.toString());
        if(this.forStmt1 != null) {
            sb.append(this.forStmt1.Parser_Output());
        }
        sb.append(this.semicn1.toString());
        if(this.cond != null) {
            sb.append(this.cond.Parser_Output());
        }
        sb.append(this.semicn2.toString());
        if(this.forStmt2 != null) {
            sb.append(this.forStmt2.Parser_Output());
        }
        sb.append(this.rparent.toString());
        sb.append(this.stmt.Parser_Output());
        return sb.toString();
    }
}
