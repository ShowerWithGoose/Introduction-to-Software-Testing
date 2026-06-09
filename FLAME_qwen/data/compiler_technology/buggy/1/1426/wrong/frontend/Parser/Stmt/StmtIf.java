package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.Exp.Cond;

//| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
public class StmtIf implements StmtInf{
    private Token ifTk;
    private Token lparent;
    private Cond cond;
    private Token rparent;
    private Stmt stmt;
    private Token elseTk;
    private Stmt elseStmt;

    public StmtIf(Token ifTk, Token lparent, Cond cond, Token rparent, Stmt stmt)
    {
        this.ifTk = ifTk;
        this.lparent = lparent;
        this.cond = cond;
        this.rparent = rparent;
        this.stmt = stmt;
    }
    public StmtIf(Token ifTk, Token lparent, Cond cond, Token rparent, Stmt stmt,Token elseTk, Stmt elseStmt) {
        this.ifTk = ifTk;
        this.lparent = lparent;
        this.cond = cond;
        this.rparent = rparent;
        this.stmt = stmt;
        this.elseTk = elseTk;
        this.elseStmt = elseStmt;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ifTk.toString());
        sb.append(this.lparent.toString());
        sb.append(this.cond.Parser_Output());
        sb.append(this.rparent.toString());
        sb.append(this.stmt.Parser_Output());
        if(this.elseTk != null)
        {
            sb.append(this.elseTk.toString());
            sb.append(this.elseStmt.Parser_Output());
        }
        return sb.toString();
    }
}
