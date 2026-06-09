package node;

import token.Token;

/**
 * ClassName: FuncDef
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:03
 * @Version 1.0
 */
public class FuncDef extends Node{
    // FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
    public FuncType funcType;
    public Token ident;
    public Token lparent;
    public FuncFParams funcFParams;
    public Token rparent;
    public Block block;

    public FuncDef(FuncType funcType, Token ident, Token lparent, FuncFParams funcFParams, Token rparent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lparent = lparent;
        this.funcFParams = funcFParams;
        this.rparent = rparent;
        this.block = block;
        setLineNo(funcType);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(funcType.getPrintInfo());
        info.append(ident.getPrintInfo());
        info.append(lparent.getPrintInfo());
        if (funcFParams != null){
            info.append(funcFParams.getPrintInfo());
        }
        info.append(rparent.getPrintInfo());
        info.append(block.getPrintInfo());
        info.append("<FuncDef>\n");
        return info;
    }

}
