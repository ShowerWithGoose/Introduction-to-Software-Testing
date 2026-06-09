package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.Cond;

import java.util.ArrayList;

public class ForStmt implements StmtInter {
    // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    private final LexType forToken;
    private final ArrayList<LexType> brace;
    private final TinyFStmt forStmt1;
    private final ArrayList<LexType> semicolons;
    private final Cond cond;
    private final TinyFStmt forStmt2;
    private final Stmt stmt;

    public ForStmt(LexType forToken, ArrayList<LexType> brace, TinyFStmt forStmt1,
                   ArrayList<LexType> semicolons, Cond cond,TinyFStmt forStmt2, Stmt stmt)
    {
        this.forToken = forToken;
        this.brace = brace;
        this.forStmt1 = forStmt1;
        this.forStmt2 = forStmt2;
        this.semicolons = semicolons;
        this.cond = cond;
        this.stmt = stmt;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(forToken).append(brace.get(0));
        if (forStmt1 != null) {
            sb.append(forStmt1);
        }
        sb.append(semicolons.get(0));
        if (cond != null) {
            sb.append(cond);
        }
        sb.append(semicolons.get(1));
        if (forStmt2 != null) {
            sb.append(forStmt2);
        }
        sb.append(brace.get(1)).append(stmt);
        return sb.toString();
    }
}
