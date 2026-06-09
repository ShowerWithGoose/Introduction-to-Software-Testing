package frontend.Nodes;

import frontend.Token;

public class FuncDef implements Node {
    private FuncType funcType;
    private Token ident;
    private Token lParent;
    private FuncFParams funcFParams;
    private Token rParent;
    private Block block;

    public FuncDef() {
        this.funcType = null;
        this.ident = null;
        this.lParent = null;
        this.funcFParams = null;
        this.rParent = null;
        this.block = null;
    }

    public void addFuncType(FuncType funcType) {
        this.funcType = funcType;
    }

    public void addIdent(Token ident) {
        this.ident = ident;
    }

    public void addLParent(Token lParent) {
        this.lParent = lParent;
    }

    public void addFuncFParams(FuncFParams funcFParams) {
        this.funcFParams = funcFParams;
    }

    public void addRParent(Token rParent) {
        this.rParent = rParent;
    }

    public void addBlock(Block block) {
        this.block = block;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        if (funcType != null) {
            sb.append(funcType.error());
        }
        if (ident != null) {
            sb.append(ident.error());
        }
        if (lParent != null) {
            sb.append(lParent.error());
        }
        if (funcFParams != null) {
            sb.append(funcFParams.error());
        }
        if (rParent != null) {
            sb.append(rParent.error());
        }
        if (block != null) {
            sb.append(block.error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (funcType != null) {
            sb.append(funcType.toString());
        }
        if (ident != null) {
            sb.append(ident.toString());
        }
        if (lParent != null) {
            sb.append(lParent.toString());
        }
        if (funcFParams != null) {
            sb.append(funcFParams.toString());
        }
        if (rParent != null) {
            sb.append(rParent.toString());
        }
        if (block != null) {
            sb.append(block.toString());
        }
        sb.append("<FuncDef>\n");
        return sb.toString();
    }
}
