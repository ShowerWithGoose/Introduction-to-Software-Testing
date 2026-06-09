package Parser.Stmt;

import Lexer.Token;
import Parser.Exp.Cond;

/**
 * @Description:
 * @date 2024/10/13
 */
public class StmtFor implements StmtEle{
    private Token forTk; // 'for'
    private Token leftParent; // '('
    private ForStmt firstForStmt;
    private Token firstSemicolon;
    private Cond cond;
    private Token secondSemicolon;
    private ForStmt secondForStmt;
    private Token rightParent; // ')'
    private Stmt forStmt;

    public StmtFor(Token forTk, Token leftParent, ForStmt firstForStmt, Token firstSemicolon, Cond cond, Token secondSemicolon, ForStmt secondForStmt, Token rightParent, Stmt forStmt) {
        this.forTk = forTk;
        this.leftParent = leftParent;
        this.firstForStmt = firstForStmt;
        this.firstSemicolon = firstSemicolon;
        this.cond = cond;
        this.secondSemicolon = secondSemicolon;
        this.secondForStmt = secondForStmt;
        this.rightParent = rightParent;
        this.forStmt = forStmt;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(forTk.toStringprint());
        sb.append(leftParent.toStringprint());
        if(firstForStmt!=null){
            sb.append(firstForStmt.print_tree());
        }
        sb.append(firstSemicolon.toStringprint());
        if(cond!=null){
            sb.append(cond.print_tree());
        }
        sb.append(secondSemicolon.toStringprint());
        if(secondForStmt!=null){
            sb.append(secondForStmt.print_tree());
        }
        sb.append(rightParent.toStringprint());
        sb.append(forStmt.print_tree());
        return sb.toString();
    }
}
