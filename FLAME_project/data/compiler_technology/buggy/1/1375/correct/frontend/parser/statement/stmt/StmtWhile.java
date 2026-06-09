package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.expression.Cond;

public class StmtWhile implements StmtEle {
    public Token forTk; // 'for'
    public Token leftParent; // '('
    public ForStmt forStmtFirst = null;
    public Token semicnFirst; // ';'
    public Cond cond = null;
    public Token semicnSecond; // ';'
    public ForStmt forStmtSecond = null;
    public Token rightParent; // ')'
    public Stmt stmt;

    public StmtWhile(
            Token forTk,
            Token leftParent,
            ForStmt forStmtFirst,
            Token semicnFirst,
            Cond cond,
            Token semicnSecond,
            ForStmt forStmtSecond,
            Token rightParent,
            Stmt stmt){
        this.forTk = forTk;
        this.leftParent = leftParent;
        this.forStmtFirst = forStmtFirst;
        this.semicnFirst = semicnFirst;
        this.cond = cond;
        this.semicnSecond = semicnSecond;
        this.forStmtSecond = forStmtSecond;
        this.rightParent = rightParent;
        this.stmt = stmt;
    }
    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.forTk.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        if(this.forStmtFirst!=null) sb.append(this.forStmtFirst.syntaxOutput());
        sb.append(this.semicnFirst.syntaxOutput());
        if(this.cond!=null) sb.append(this.cond.syntaxOutput());
        sb.append(this.semicnSecond.syntaxOutput());
        if(this.forStmtSecond!=null)sb.append(this.forStmtSecond.syntaxOutput());
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.stmt.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num(){
        return stmt.my_line_num();
    }
}
