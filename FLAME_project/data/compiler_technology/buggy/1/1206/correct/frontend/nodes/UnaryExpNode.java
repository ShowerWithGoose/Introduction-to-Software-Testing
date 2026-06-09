package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:21
 */
public class UnaryExpNode {
    //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    PrimaryExpNode primaryExpNode;

    token ident;
    token lparent;
    FuncRParamsNode funcRParamsNode;
    token rparent;

    UnaryOpNode unaryOpNode;
    UnaryExpNode unaryExpNode;
    public UnaryExpNode(PrimaryExpNode primaryExpNode){
        this.primaryExpNode=primaryExpNode;
    }
    public UnaryExpNode(token ident,token lparent,FuncRParamsNode funcRParamsNode,token rparent){
        this.ident=ident;
        this.lparent=lparent;
        this.funcRParamsNode=funcRParamsNode;
        this.rparent=rparent;
    }
    public UnaryExpNode(UnaryOpNode unaryOpNode,UnaryExpNode unaryExpNode){
        this.unaryOpNode=unaryOpNode;
        this.unaryExpNode=unaryExpNode;
    }
    public void output()throws IOException{
        if(primaryExpNode!=null){
            primaryExpNode.output();
        }else if(ident!=null){
            out.write(ident.toString());
            out.write(lparent.toString());
            if(funcRParamsNode!=null)funcRParamsNode.output();
            out.write(rparent.toString());
        }else if(unaryOpNode!=null){
            unaryOpNode.output();
            unaryExpNode.output();
        }
        out.write("<UnaryExp>");
    }
}
