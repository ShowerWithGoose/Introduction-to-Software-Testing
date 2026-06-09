package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:17
 */
public class LvalNode {
    //LVal → Ident ['[' Exp ']']
    token ident;
    token lbrack;
    token rbrack;
    ExpNode expNode;
    public LvalNode(token ident,token lbrack,token rbrack ,ExpNode expNode){
        this.ident=ident;
        this.lbrack=lbrack;
        this.rbrack=rbrack;
        this.expNode=expNode;
    }

    public void output() throws IOException {
        out.write(ident.toString());
        if(lbrack!=null){
            out.write(lbrack.toString());
            expNode.output();
            out.write(rbrack.toString());
        }
        out.write("<LVal>");
    }
}
