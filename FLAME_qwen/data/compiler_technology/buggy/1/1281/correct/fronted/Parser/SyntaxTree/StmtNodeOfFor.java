package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 13:29
 */
public class StmtNodeOfFor implements SyntaxNode{
    private Token forTk ; // for
    private Token leftParent; // '('
    private ForStmt firstForStmt;  // may
    private Token firstSemicn; // ';'
    private Cond cond;  //may
    private Token secondSemicn; // ';'
    private ForStmt secondForStmt;  // may
    private Token rightParent; // ')'
    private Stmt stmt;

    public StmtNodeOfFor(Token forTk, Token leftParent, ForStmt firstForStmt, Token firstSemicn, Cond cond, Token secondSemicn, ForStmt secondForStmt, Token rightParent, Stmt stmt) {
        this.forTk = forTk;
        this.leftParent = leftParent;
        this.firstForStmt = firstForStmt;
        this.firstSemicn = firstSemicn;
        this.cond = cond;
        this.secondSemicn = secondSemicn;
        this.secondForStmt = secondForStmt;
        this.rightParent = rightParent;
        this.stmt = stmt;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.forTk.output());
        sb.append(this.leftParent.output());
        if (this.firstForStmt != null) {
            sb.append(this.firstForStmt.output());
        }
        sb.append(this.firstSemicn.output());
        if (this.cond != null) {
            sb.append(this.cond.output());
        }
        sb.append(this.secondSemicn.output());
        if (this.secondForStmt != null) {
            sb.append(this.secondForStmt.output());
        }
        sb.append(this.rightParent.output());
        sb.append(this.stmt.output());
        return sb.toString();
    }
}
