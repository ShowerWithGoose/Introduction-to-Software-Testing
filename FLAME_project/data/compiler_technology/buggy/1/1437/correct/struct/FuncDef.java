package struct;

import token.Token;

/* FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block */
public class FuncDef {
    private final FuncType funcType;
    private final Token ident;
    private final Token lParentToken;
    private final FuncFParams funcFParams;
    private final Token rParentToken;
    private final Block block;

    public FuncDef(FuncType funcType, Token ident, Token lParentToken, FuncFParams funcFParams, Token rParentToken, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lParentToken = lParentToken;
        this.funcFParams = funcFParams;
        this.rParentToken = rParentToken;
        this.block = block;
    }

    public FuncType getFuncType() {
        return funcType;
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLParentToken() {
        return lParentToken;
    }

    public FuncFParams getFuncFParams() {
        return funcFParams;
    }

    public Token getRParentToken() {
        return rParentToken;
    }

    public Block getBlock() {
        return block;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.toString());
        sb.append(ident.toString());
        sb.append(lParentToken.toString());
        if (funcFParams != null) {
            sb.append(funcFParams.toString());
        }
        sb.append(rParentToken.toString());
        sb.append(block.toString());
        sb.append("<FuncDef>\n");
        return sb.toString();
    }
}
