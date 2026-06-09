package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.expression.Cond;
import frontend.Token;

public class StmtIf extends StmtEle {
    /*Token if_;
    Token leftParen;
    Cond* cond{};
    Token rightParen;
    Stmt* stmt{};
    Token else_;
    Stmt* stmtElse{};*/
    private Token if_;
    private Token leftParen;
    private Cond cond;
    private Token rightParen;
    private Stmt stmt;
    private Token else_;
    private Stmt stmtElse;

    public StmtIf(Token if_, Token leftParen, Cond cond, Token rightParen, Stmt stmt) {
        this.if_ = if_;
        this.leftParen = leftParen;
        this.cond = cond;
        this.rightParen = rightParen;
        this.stmt = stmt;
    }

    public StmtIf(Token if_, Token leftParen, Cond cond, Token rightParen, Stmt stmt, Token else_, Stmt stmtElse) {
        this.if_ = if_;
        this.leftParen = leftParen;
        this.cond = cond;
        this.rightParen = rightParen;
        this.stmt = stmt;
        this.else_ = else_;
        this.stmtElse = stmtElse;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(if_.toString());
        sb.append(leftParen.toString());
        sb.append(cond.toString());
        sb.append(rightParen.toString());
        sb.append(stmt.toString());
        if (else_ != null) {
            sb.append(else_.toString());
            sb.append(stmtElse.toString());
        }
        return sb.toString();
    }
}
