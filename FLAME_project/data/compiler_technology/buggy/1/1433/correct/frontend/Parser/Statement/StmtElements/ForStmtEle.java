package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Expression.Cond;
import frontend.Parser.Statement.ForStmt;
import frontend.Parser.Statement.Stmt;
import frontend.Parser.Statement.StmtEle;

public class ForStmtEle implements StmtEle {
    private Token forToken;
    private Token lparentToken;
    private ForStmt forStmt1;       // 可选
    private Token semicnToken1;
    private Cond cond;              // 可选
    private Token semicnToken2;
    private ForStmt forStmt2;       // 可选
    private Token rparentToken;
    private Stmt stmt;

    public ForStmtEle(Token forToken,
                    Token lparentToken, 
                    ForStmt forStmt1, 
                    Token semicnToken1, 
                    Cond cond, 
                    Token semicnToken2, 
                    ForStmt forStmt2, 
                    Token rparentToken, 
                    Stmt stmt) {
        this.forToken = forToken;
        this.lparentToken = lparentToken;
        this.forStmt1 = forStmt1;
        this.semicnToken1 = semicnToken1;
        this.cond = cond;
        this.semicnToken2 = semicnToken2;
        this.forStmt2 = forStmt2;
        this.rparentToken = rparentToken;
        this.stmt = stmt;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(forToken);
        sb.append(lparentToken);
        if (forStmt1 != null) {
            sb.append(forStmt1.printString());
        }
        if (semicnToken1 != null) {
            sb.append(semicnToken1);
        }
        if (cond != null) {
            sb.append(cond.printString());
        }
        if (semicnToken2 != null) {
            sb.append(semicnToken2);
        }
        if (forStmt2 != null) {
            sb.append(forStmt2.printString());
        }
        if (rparentToken != null) {
            sb.append(rparentToken);
        }
        sb.append(stmt.printString());
        return sb.toString();
    }
}
