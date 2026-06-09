package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.expression.Cond;
import frontend.Parser.statement.Stmt;
import frontend.Parser.statement.StmtPort;

// 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
public class IfStmt implements StmtPort {
    private Token ifTk;
    private Token lParent;
    private Cond cond;
    private Token rParent;
    private Stmt if2Stmt;
    private Token elseTk;
    private Stmt else2Stmt;

    public IfStmt(Token ifTk, Token lParent, Cond cond, Token rParent,
                  Stmt if2Stmt, Token elseTk, Stmt else2Stmt) {
        this.ifTk = ifTk;
        this.lParent = lParent;
        this.cond = cond;
        this.rParent = rParent;
        this.if2Stmt = if2Stmt;
        this.elseTk = elseTk;
        this.else2Stmt = else2Stmt;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ifTk.grammarOutput());
        sb.append(lParent.grammarOutput());
        sb.append(cond.grammarOutput());
        sb.append(rParent.grammarOutput());
        sb.append(if2Stmt.grammarOutput());
        if (elseTk != null && else2Stmt != null) {
            sb.append(elseTk.grammarOutput());
            sb.append(else2Stmt.grammarOutput());
        }
        return sb.toString();
    }
}
