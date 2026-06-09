package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Expression.Cond;
import frontend.Parser.Statement.Stmt;
import frontend.Parser.Statement.StmtEle;

public class IfStmtEle implements StmtEle {
    private Token ifToken;
    private Token lparentToken;
    private Cond cond;
    private Token rparentToken;
    private Stmt ifstmt;
    private Token elesToken;    // 可选
    private Stmt elstmt;        // 可选

    public IfStmtEle(Token ifToken,
                     Token lparentToken,
                     Cond cond,
                     Token rparentToken,
                     Stmt ifstmt,
                     Token elesToken,
                     Stmt elstmt) {
        this.ifToken = ifToken;
        this.lparentToken = lparentToken;
        this.cond = cond;
        this.rparentToken = rparentToken;
        this.ifstmt = ifstmt;
        this.elesToken = elesToken;
        this.elstmt = elstmt;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ifToken);
        sb.append(lparentToken);
        sb.append(cond.printString());
        if (rparentToken != null) {
            sb.append(rparentToken);
        }
        sb.append(ifstmt.printString());
        if (elesToken != null) {
            sb.append(elesToken);
            sb.append(elstmt.printString());
        }
        return sb.toString();
    }
}
