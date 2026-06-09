package frontend.SyntaxTree;

import frontend.Token;

public class ConstDef {
    private Token ident;
    private ConstExp constExp;
    private ConstInitVal constInitVal;


    public void setIdent(Token curToken) {
        this.ident = curToken;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setConstInitVal(ConstInitVal constInitVal) {
        this.constInitVal = constInitVal;
    }
}
