package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.AddExp;
import frontend.Parser.SyntaxNode.Exp;
import frontend.Parser.SyntaxNode.LVal;

public class StmtAssign extends Stmt {
    private LVal lVal;
    private Token assign;
    private Exp exp;
    private Token semicn;

    public StmtAssign(LVal lval, Token assign, Exp exp, Token semicn) {
        this.lVal = lval;
        this.assign = assign;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal);
        sb.append(assign);
        sb.append(exp);
        sb.append(semicn);
        sb.append(name + "\n");
        return sb.toString();
    }
}
