package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.Cond;
import frontend.Parser.SyntaxNode.ForStmt;

/*
'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
 */
public class StmtFor extends Stmt {
    private Token forTk;
    private Token lParent;
    private ForStmt forStmt1 = null;
    private Token semicn1;
    private Cond cond = null;
    private Token semicn2;
    private ForStmt forStmt2 = null;
    private Token rParent;
    private Stmt stmt;

    public StmtFor(Token forTk, Token lParent, ForStmt forStmt1,
                   Token semicn1, Cond cond, Token semicn2, ForStmt forStmt2,
                   Token rParent, Stmt stmt) {
        this.forTk = forTk;
        this.lParent = lParent;
        this.forStmt1 = forStmt1;
        this.semicn1 = semicn1;
        this.cond = cond;
        this.semicn2 = semicn2;
        this.forStmt2 = forStmt2;
        this.rParent = rParent;
        this.stmt = stmt;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(forTk);
        sb.append(lParent);
        if (forStmt1 != null) {
            sb.append(forStmt1);
        }
        sb.append(semicn1);
        if (cond != null) {
            sb.append(cond);
        }
        sb.append(semicn2);
        if (forStmt2 != null) {
            sb.append(forStmt2);
        }
        sb.append(rParent);
        sb.append(stmt);
        sb.append(name + "\n");
        return sb.toString();
    }
}
