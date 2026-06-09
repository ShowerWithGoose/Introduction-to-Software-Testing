package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.expression.Cond;
import frontend.Parser.statement.ForStmt;
import frontend.Parser.statement.Stmt;
import frontend.Parser.statement.StmtPort;

//'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
public class ForLoopStmt implements StmtPort {
    private Token forTk;
    private Token lParent;
    private Token semicn1;
    private Token semicn2;
    private Token rParent;
    private Stmt stmt;
    private ForStmt forStmt1;
    private Cond cond;
    private ForStmt forStmt2;

    public ForLoopStmt(Token forTk, Token lParent, Token semicn1, Token semicn2
            , Token rParent, Stmt stmt, ForStmt forStmt1, Cond cond, ForStmt forStmt2) {
        this.forTk = forTk;
        this.lParent = lParent;
        this.semicn1 = semicn1;
        this.semicn2 = semicn2;
        this.rParent = rParent;
        this.stmt = stmt;
        this.forStmt1 = forStmt1;
        this.cond = cond;
        this.forStmt2 = forStmt2;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(forTk.grammarOutput());
        sb.append(lParent.grammarOutput());
        if (forStmt1 != null) {
            sb.append(forStmt1.grammarOutput());
        }
        sb.append(semicn1.grammarOutput());
        if (cond != null) {
            sb.append(cond.grammarOutput());
        }
        sb.append(semicn2.grammarOutput());
        if (forStmt2 != null) {
            sb.append(forStmt2.grammarOutput());
        }
        sb.append(rParent.grammarOutput());
        sb.append(stmt.grammarOutput());
        return sb.toString();
    }
}
