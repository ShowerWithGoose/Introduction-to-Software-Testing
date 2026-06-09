package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/9/30 11:34
 */
public class ConstDeclNode {
    //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    token constToken;
    BTypeNode bTypeNode;
    ArrayList<ConstDefNode> constDefNodes;
    ArrayList<token> commas;//逗号
    token semicn;
    public ConstDeclNode(
            token constToken,
            BTypeNode bTypeNode,
            ArrayList<ConstDefNode> constDefNodes,
            ArrayList<token> commas,
            token semicnToken){
        this.constToken=constToken;
        this.bTypeNode=bTypeNode;
        this.constDefNodes=constDefNodes;
        this.commas=commas;
        this.semicn=semicnToken;
    }

    public void output() throws IOException {
        out.write(constToken.toString());
        bTypeNode.output();
        constDefNodes.get(0).output();
        for(int i=1;i<constDefNodes.size();i++){
            out.write(commas.get(i-1).toString());
            constDefNodes.get(i).output();
        }
        out.write(semicn.toString());
        out.write("<ConstDecl>");
    }
}
