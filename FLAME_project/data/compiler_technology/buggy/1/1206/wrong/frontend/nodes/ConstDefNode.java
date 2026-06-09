package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/9/30 11:38
 */
public class ConstDefNode {
    //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    token ident;
    token assign;//=
    token lbrack,rbrack;//[,]
    ConstExpNode constExpNode;
    ConstInitValNode constInitValNode;
    public ConstDefNode(token ident,
                        token lbrack,
                        ConstExpNode constExpNode,
                        token rbrack,
                        token assign,
                        ConstInitValNode constInitValNode){
        this.ident=ident;
        this.lbrack=lbrack;
        this.constExpNode=constExpNode;
        this.rbrack=rbrack;
        this.assign=assign;
        this.constInitValNode=constInitValNode;

    }

    public void output() throws IOException {
        out.write(ident.toString());
        if(constExpNode!=null){
            out.write(lbrack.toString());
            constExpNode.output();
            out.write(rbrack.toString());
        }
        out.write(assign.toString());
        constInitValNode.output();
        out.write("<ConstDef>");
    }
}
