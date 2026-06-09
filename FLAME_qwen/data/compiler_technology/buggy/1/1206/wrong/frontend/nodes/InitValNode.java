package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:13
 */
public class InitValNode {
    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    ExpNode expNode;
    token lbrace;
    ArrayList<ExpNode> expNodes;
    ArrayList<token> commas;
    token rbrace;
    token string;
    public InitValNode(ExpNode expNode,token lbrace,ArrayList<ExpNode> expNodes,
                       ArrayList<token> commas,token rbrace,token string){
        this.expNodes=expNodes;
        this.expNode=expNode;
        this.lbrace=lbrace;
        this.rbrace=rbrace;
        this.commas=commas;
        this.string=string;

    }

    public void output() throws IOException {
        if(lbrace!=null){
            out.write(lbrace.toString());
            if(expNodes.size()>0){
                expNodes.get(0).output();
                for (int i = 1; i < expNodes.size(); i++) {
                    out.write(commas.get(i - 1).toString());
                    expNodes.get(i).output();
                }
            }
            out.write(rbrace.toString());
        }else if(string!=null){
            out.write(string.toString());
        }else {
            expNode.output();

        }
        out.write("<InitVal>");
    }
}
