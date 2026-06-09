package frontend.SyntaxUnits.StmtUnits;

import frontend.SyntaxUnits.Cond;
import frontend.SyntaxUnits.ForStmt;
import frontend.SyntaxUnits.Stmt;

public class ForBlockStmt implements StmtUnit{
    private final Stmt stmt;
    private final ForStmt initStmt;
    private final boolean hasInitStmt;
    private final ForStmt endStmt;
    private final boolean hasEndStmt;
    private final Cond cond;
    private final boolean hasCond;

    public ForBlockStmt(Stmt stmt) {
        this.stmt = stmt;
        initStmt = null;
        hasInitStmt = false;
        endStmt = null;
        hasEndStmt  = false;
        cond = null;
        hasCond = false;
    }

    public ForBlockStmt(Stmt stmt, ForStmt forStmt, boolean first) {
        if (first) {
            this.stmt = stmt;
            this.initStmt = forStmt;
            hasInitStmt = true;
            endStmt = null;
            hasEndStmt  = false;
            cond = null;
            hasCond = false;
        }
        else {
            this.stmt = stmt;
            initStmt = null;
            hasInitStmt = false;
            this.endStmt = forStmt;
            hasEndStmt  = true;
            cond = null;
            hasCond = false;
        }
    }

    public ForBlockStmt(Stmt stmt, Cond cond) {
        this.stmt = stmt;
        initStmt = null;
        hasInitStmt = false;
        endStmt = null;
        hasEndStmt  = false;
        this.cond = cond;
        hasCond = true;
    }

    public ForBlockStmt(Stmt stmt, Cond cond, ForStmt forStmt, boolean first) {
        if (first) {
            this.stmt = stmt;
            this.initStmt = forStmt;
            hasInitStmt = true;
            endStmt = null;
            hasEndStmt  = false;
            this.cond = cond;
            hasCond = true;
        }
        else {
            this.stmt = stmt;
            initStmt = null;
            hasInitStmt = false;
            this.endStmt = forStmt;
            hasEndStmt  = true;
            this.cond = cond;
            hasCond = true;
        }
    }

    public ForBlockStmt(Stmt stmt, ForStmt initStmt, ForStmt endStmt) {
        this.stmt = stmt;
        this.initStmt = initStmt;
        hasInitStmt = true;
        this.endStmt = endStmt;
        hasEndStmt  = true;
        cond = null;
        hasCond = false;
    }

    public ForBlockStmt(Stmt stmt,ForStmt initStmt, Cond cond, ForStmt endStmt) {
        this.stmt = stmt;
        this.initStmt = initStmt;
        hasInitStmt = true;
        this.endStmt = endStmt;
        hasEndStmt  = true;
        this.cond = cond;
        hasCond = true;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("FORTK" + " for" +  "\n");
        stringBuilder.append("LPARENT" + " (" +  "\n");
        if (hasInitStmt) stringBuilder.append(initStmt.toPrint());
        stringBuilder.append("SEMICN" + " ;" +  "\n");
        if (hasCond) stringBuilder.append(cond.toPrint());
        stringBuilder.append("SEMICN" + " ;" +  "\n");
        if (hasEndStmt) stringBuilder.append(endStmt.toPrint());
        stringBuilder.append("RPARENT" + " )" +  "\n");
        stringBuilder.append(stmt.toPrint());
        return stringBuilder.toString();
    }
}
