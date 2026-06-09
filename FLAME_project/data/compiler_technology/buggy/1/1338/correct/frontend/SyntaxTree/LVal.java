package frontend.SyntaxTree;

import frontend.Token;

public class LVal {
    private Token ident;
    private Exp exp;

    public LVal() {
    }

    public void setIdent(Token ident) {
        this.ident = ident;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }
}
