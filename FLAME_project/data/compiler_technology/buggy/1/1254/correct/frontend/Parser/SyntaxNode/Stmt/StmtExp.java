package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.Exp;

public class StmtExp extends Stmt {
    private Exp exp;
    private Token semicn;

    public StmtExp(Exp exp, Token semicn) {
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp);
        }
        sb.append(semicn);
        sb.append(name + "\n");
        return sb.toString();
    }
}
