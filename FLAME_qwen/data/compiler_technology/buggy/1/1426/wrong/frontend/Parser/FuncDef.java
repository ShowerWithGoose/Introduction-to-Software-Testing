package frontend.Parser;

import frontend.Token;
import frontend.Parser.Func.FuncFParams;
import frontend.Parser.Func.FuncType;
import frontend.Parser.Stmt.Block;
import frontend.Parser.solid.Ident;

//函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // 1.无形参 2.有形参
public class FuncDef implements Output{
    private final String name = "<FuncDef>";
    private FuncType funcType;
    private Ident ident;
    private Token lparent;
    private FuncFParams funcFParams = null;
    private Token rparent;
    private Block block;

    public FuncDef(FuncType funcType, Ident ident, Token lparent, Token rparent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lparent = lparent;
        this.rparent = rparent;
        this.block = block;
    }
    public FuncDef(FuncType funcType, Ident ident, Token lparent, FuncFParams funcFParams,Token rparent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lparent = lparent;
        this.funcFParams = funcFParams;
        this.rparent = rparent;
        this.block = block;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcType.Parser_Output());
        sb.append(this.ident.Parser_Output());
        sb.append(this.lparent.toString());
        if(funcFParams != null) {
            sb.append(funcFParams.Parser_Output());
        }
        sb.append(this.rparent.toString());
        sb.append(this.block.Parser_Output());
        sb.append(this.name + "\n");

        return sb.toString();
    }
}
