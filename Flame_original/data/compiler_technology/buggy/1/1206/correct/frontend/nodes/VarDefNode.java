package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 0:17
 */
public class VarDefNode {
    //VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    token ident;
    token lbrack;
    ConstExpNode constExpNode;
    token rbrack;
    token assign;
    InitValNode initValNode;
    public VarDefNode(token ident,token lbrack,ConstExpNode constExpNode,token rbrack,
                      token assign,InitValNode initValNode){
        this.ident=ident;
        this.lbrack=lbrack;
        this.constExpNode=constExpNode;
        this.rbrack=rbrack;
        this.assign = assign;
        this.initValNode=initValNode;

    }

    public void output() throws IOException {
        out.write(ident.toString());
        if(lbrack!=null){
            out.write(lbrack.toString());
            constExpNode.output();
            out.write(rbrack.toString());
        }
        if(assign!=null){
            out.write(assign.toString());
            initValNode.output();
        }
        out.write("<VarDef>");
    }
}
