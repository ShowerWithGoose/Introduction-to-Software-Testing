package frontend.SyntaxTree;

import frontend.Token;

public class VarDef {
    private Token ident;
    private ConstExp constExp;
    private InitVal initVal;

    public void setIdent(Token curToken) {
        this.ident = curToken;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }
}
