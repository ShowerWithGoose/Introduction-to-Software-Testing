package node;

import frontend.Parser;

public class FuncDef {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.FuncDef;
    private FuncType funcType;
    private Ident ident;
    private FuncFParams funcFParams;
    private Block block;

    public FuncDef(FuncType funcType, Ident ident, FuncFParams funcFParams, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.funcFParams = funcFParams;
        this.block = block;
    }

    private FuncDef(FuncType funcType, Ident ident, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.block = block;
        this.funcFParams = null;
    }

    public FuncType getFuncType() {
        return funcType;
    }

    public Ident getIdent() {
        return ident;
    }

    public FuncFParams getFuncFParams() {
        return funcFParams;
    }

    public Block getBlock() {
        return block;
    }

    public boolean haveFParams() {
        return funcFParams != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(funcType);
        ret.append("\n").append(" ").append(ident);
        if (haveFParams()) {
            ret.append("\n").append(funcFParams);
        }
        ret.append("\n").append(block);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
