package frontend.SyntaxTree;

import frontend.Token;

public class FuncFParam {
    private BType BType;
    private Token ident;

    public FuncFParam() {
    }

    public void setBType(BType BType) {
        this.BType = BType;
    }

    public void setIdent(Token ident) {
        this.ident = ident;
    }
}
