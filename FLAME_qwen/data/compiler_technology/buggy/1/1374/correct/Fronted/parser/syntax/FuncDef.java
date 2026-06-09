package Fronted.parser.syntax;

import Fronted.lexer.Token;

// FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block // j
public class FuncDef {

    private static final String name = "<FuncDef>";

    private FuncType funcType = null;

    private Token ident = null;

    private Token lparent = null;

    private FuncFParams funcFParams = null;

    private Token rparent = null;

    private Block block = null;

    public FuncDef(FuncType funcType, Token ident, Token lparent, FuncFParams funcFParams, Token rparent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lparent = lparent;
        this.funcFParams = funcFParams;
        this.rparent = rparent;
        this.block = block;
    }

    @Override
    public String toString(){
        StringBuilder out = new StringBuilder();
        out.append(funcType);
        out.append(ident);
        out.append(lparent);
        if(funcFParams!= null) out.append(funcFParams);
        out.append(rparent);
        out.append(block);
        out.append(name).append("\n");
        return out.toString();
    }

    public FuncType getFunctionType(){
        return funcType;
    }

    public Token getIdent(){
        return ident;
    }

    public Token getLparent(){
        return lparent;
    }

    public FuncFParams getFuncFParams(){
        return funcFParams;
    }

    public Token getRparent(){
        return rparent;
    }

    public Block getBlock(){
        return block;
    }

    public void setFuncType(FuncType funcType) {
        this.funcType = funcType;
    }

    public void setIdent(Token ident) {
        this.ident = ident;
    }

    public void setLparent(Token lparent) {
        this.lparent = lparent;
    }

    public void setFuncFParams(FuncFParams funcFParams) {
        this.funcFParams = funcFParams;
    }

    public void setRparent(Token rparent) {
        this.rparent = rparent;
    }

    public void setBlock(Block block) {
        this.block = block;
    }
}
