package frontend.SyntaxTree;

import frontend.Token;

public class FuncDef {
    private FuncType funcType;
    private Token ident;
    private FuncFParams funcFParams;
    private Block block;

    public void setFuncType(FuncType funcType) {
        this.funcType = funcType;
    }

    public void setIdent(Token curToken) {
        this.ident = curToken;
    }

    public void setFuncFParams(FuncFParams funcFParams) {
        this.funcFParams = funcFParams;
    }

    public void setBlock(Block block) {
        this.block = block;
    }
}
