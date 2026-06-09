package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 12:50
 */
public class StmtNodeOfIf implements SyntaxNode{
    private Token ifTk; // 'if'
    private Token leftParent; // '('
    private Cond cond;
    private Token rightParent; // ')'
    private Stmt ifStmt;
    private Token elseTk; // 'else' MAY exist
    private Stmt elseStmt; // MAY exist

    public StmtNodeOfIf(Token ifTk, Token leftParent, Cond cond, Token rightParent, Stmt ifStmt, Token elseTk, Stmt elseStmt) {
        this.ifTk = ifTk;
        this.leftParent = leftParent;
        this.cond = cond;
        this.rightParent = rightParent;
        this.ifStmt = ifStmt;
        this.elseTk = elseTk;
        this.elseStmt = elseStmt;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ifTk.output());
        sb.append(this.leftParent.output());
        sb.append(this.cond.output());
        sb.append(this.rightParent.output());
        sb.append(this.ifStmt.output());
        if (elseTk != null) {
            sb.append(this.elseTk.output());
            sb.append(this.elseStmt.output());
        }
        return sb.toString();
    }
}
