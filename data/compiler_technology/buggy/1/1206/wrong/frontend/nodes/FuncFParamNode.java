package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/11 9:21
 */
public class FuncFParamNode {
    // FuncFParam → BType Ident ['[' ']']
    BTypeNode bTypeNode;
    token ident;
    token lbrack;
    token rbrack;
    public FuncFParamNode(BTypeNode bTypeNode,token ident,token lbrack ,token rbrack){
        this.bTypeNode=bTypeNode;
        this.ident=ident;
        this.lbrack=lbrack;
        this.rbrack=rbrack;
    }

    public void output() throws IOException {
        bTypeNode.output();
        out.write(ident.toString());
        if(lbrack!=null){
            out.write(lbrack.toString());
            out.write(rbrack.toString());
        }
        out.write("<FuncFParam>");
    }
}
