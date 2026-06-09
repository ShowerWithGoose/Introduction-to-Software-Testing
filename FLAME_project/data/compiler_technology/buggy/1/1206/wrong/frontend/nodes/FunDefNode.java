package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/9/30 11:32
 */
public class FunDefNode {
    //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    FuncTypeNode funcTypeNode;
    token ident;
    token lparent;
    FuncFParamsNode funcFParamsNode;
    token rparent;
    BlockNode blockNode;
    public FunDefNode(FuncTypeNode funcTypeNode,token ident,token lparent,
                      FuncFParamsNode funcFParamsNode,token rparent,BlockNode blockNode){
        this.funcTypeNode=funcTypeNode;
        this.ident=ident;
        this.lparent=lparent;
        this.funcFParamsNode=funcFParamsNode;
        this.rparent=rparent;
        this.blockNode=blockNode;

    }

    public void output() {
        try {
            funcTypeNode.output();
            out.write(ident.toString());
            out.write(lparent.toString());
            if(funcFParamsNode!=null){
                funcFParamsNode.output();
            }
            out.write(rparent.toString());
            blockNode.output();
            out.write("<FuncDef>");
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
