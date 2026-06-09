package Fronted.parser.syntax;

import Fronted.lexer.Token;

//  MainFuncDef â†’ 'int' 'main' '(' ')' Block // j
public class MainFuncDef {

    public static final String name = "<MainFuncDef>";

    private Token inttk = null;

    private Token maintk = null;

    private Token lparent = null;

    private Token rparent = null;

    private Block block = null;

    public MainFuncDef(Token inttk, Token maintk, Token lparent, Token rparent, Block block) {
        this.inttk = inttk;
        this.maintk = maintk;
        this.lparent = lparent;
        this.rparent = rparent;
        this.block = block;
    }

    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(inttk);
        out.append(maintk);
        out.append(lparent);
        out.append(rparent);
        out.append(block);
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getInttk() {
        return inttk;
    }

    public Token getMaintk() {
        return maintk;
    }

    public Token getLparent() {
        return lparent;
    }

    public Token getRparent() {
        return rparent;
    }

    public Block getBlock() {
        return block;
    }

    public void setInttk(){
        this.inttk = inttk;
    }

    public void setMaintk(){
        this.maintk = maintk;
    }

    public void setLparent(){
        this.lparent = lparent;
    }

    public void setRparent(){
        this.rparent = rparent;
    }

    public void setBlock(){
        this.block = block;
    }
}
