package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.expression.Cond;

public class ForCondStmt implements StmtUnit{
    //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    private Token forTk;
    private Token leftParent;
    private ForStmt forStmt1;
    private Token semicn1;
    private Cond cond;
    private Token semicn2;
    private ForStmt forStmt2;
    private  Token rightParent;
    private Stmt stmt;
    //不会发生缺少分号的错误

    public ForCondStmt(Token forTk, Token leftParent, ForStmt forStmt1, Token semicn1, Cond cond, Token semicn2, ForStmt forStmt2, Token rightParent, Stmt stmt) {
        this.forTk = forTk;
        this.leftParent = leftParent;
        this.forStmt1 = forStmt1;
        this.semicn1 = semicn1;
        this.cond = cond;
        this.semicn2 = semicn2;
        this.forStmt2 = forStmt2;
        this.rightParent = rightParent;
        this.stmt = stmt;
    }

    @Override
    public String syntaxPrint() {
        //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        StringBuilder sb = new StringBuilder();
        sb.append(forTk.syntaxPrint());
        sb.append(leftParent.syntaxPrint());
        if (forStmt1 != null) {
            sb.append(forStmt1.syntaxPrint());
        }
        if (semicn1 != null) {
            sb.append(semicn1.syntaxPrint());
        }
        if (cond != null) {
            sb.append(cond.syntaxPrint());
        }
        if (semicn2 != null) {
            sb.append(semicn2.syntaxPrint());
        }
        if (forStmt2 != null) {
            sb.append(forStmt2.syntaxPrint());
        }
        if (rightParent != null) {
            sb.append(rightParent.syntaxPrint());
        }
        sb.append(stmt.syntaxPrint());
        return sb.toString();
    }
}
