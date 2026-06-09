package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.Exp;

public class StmtReturn extends Stmt {
    private Token returnTk;
    private Exp exp = null;
    private Token semicn;

    public StmtReturn(Token returnTk, Exp exp, Token semicn) {
        this.returnTk = returnTk;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(returnTk);
        if (exp != null) {
            sb.append(exp);
        }
        sb.append(semicn);
        sb.append(name + "\n");
        return sb.toString();
    }
}
