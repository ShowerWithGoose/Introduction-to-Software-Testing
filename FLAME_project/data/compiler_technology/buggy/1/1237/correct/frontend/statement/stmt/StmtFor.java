package frontend.statement.stmt;
import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Cond;
import frontend.expression.CondParser;

public class StmtFor implements StmtEle {
    private Token forTk; // 'for'
    private Token leftParent; // '('
    private ForStmt initStmt; // 初始语句 [ForStmt]
    private Token firstSemi; // 第一分号
    private Cond cond; // 条件语句 [Cond]
    private Token secondSemi; // 第二分号
    private ForStmt updateStmt; // 更新语句 [ForStmt]
    private Token rightParent; // ')'
    private Stmt stmt; // 循环体

    public StmtFor(Token forTk,
                   Token leftParent,
                   ForStmt initStmt,
                   Token firstSemi,
                   Cond cond,
                   Token secondSemi,
                   ForStmt updateStmt,
                   Token rightParent,
                   Stmt stmt) {
        this.forTk = forTk;
        this.leftParent = leftParent;
        this.initStmt = initStmt;
        this.firstSemi = firstSemi;
        this.cond = cond;
        this.secondSemi = secondSemi;
        this.updateStmt = updateStmt;
        this.rightParent = rightParent;
        this.stmt = stmt;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.forTk.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        if (this.initStmt != null) {
            sb.append(this.initStmt.syntaxOutput());
        }
        sb.append(this.firstSemi.syntaxOutput());
        if (this.cond != null) {
            sb.append(this.cond.syntaxOutput());
        }
        sb.append(this.secondSemi.syntaxOutput());
        if (this.updateStmt != null) {
            sb.append(this.updateStmt.syntaxOutput());
        }
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.stmt.syntaxOutput());
        return sb.toString();
    }
}
