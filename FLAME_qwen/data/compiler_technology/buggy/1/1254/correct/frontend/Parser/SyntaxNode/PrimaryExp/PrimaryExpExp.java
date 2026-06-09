package frontend.Parser.SyntaxNode.PrimaryExp;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.Exp;

public class PrimaryExpExp extends PrimaryExp {
    private Token lparent;
    private Exp exp;
    private Token rparent;

    public PrimaryExpExp(Token lparent, Exp exp, Token rparent) {
        this.lparent = lparent;
        this.exp = exp;
        this.rparent = rparent;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lparent);
        sb.append(exp);
        sb.append(rparent);
        sb.append(name + "\n");
        return sb.toString();
    }
}
