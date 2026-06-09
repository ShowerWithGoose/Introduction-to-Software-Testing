package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.expression.Cond;
import parser_part.statement.Stmt;

public class StmtWhile implements StmtComponent {
    private Token whileToken;
    private Token leftParent;
    private Cond cond;
    private Token rightParent;
    private Stmt stmt;

    public StmtWhile(Token whileToken, Token leftParent, Cond cond, Token rightParent, Stmt stmt) {
        this.whileToken = whileToken;
        this.leftParent = leftParent;
        this.cond = cond;
        this.rightParent = rightParent;
        this.stmt = stmt;
    }

    @Override
    public String toString() {
        return whileToken.toString() + leftParent.toString() + cond.toString() +
                rightParent.toString() + stmt.toString();
    }
}
