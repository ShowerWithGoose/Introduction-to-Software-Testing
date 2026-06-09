package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/9/30 11:35
 */
public class VarDeclNode {
    //VarDecl → BType VarDef { ',' VarDef } ';'
    BTypeNode bTypeNode;
    ArrayList<VarDefNode> varDefNodes;
    ArrayList<token> commas;
    token semicn;
    public VarDeclNode(BTypeNode bTypeNode,ArrayList<VarDefNode> varDefNodes,
                       ArrayList<token> commas,token semicn){
        this.bTypeNode=bTypeNode;
        this.varDefNodes=varDefNodes;
        this.commas=commas;
        this.semicn=semicn;

    }

    public void output() throws IOException {
        bTypeNode.output();
        varDefNodes.get(0).output();
        for(int i=1;i<varDefNodes.size();i++){
            out.write(commas.get(i-1).toString());
            varDefNodes.get(i).output();
        }
        out.write(semicn.toString());
        out.write("<VarDecl>");
    }
}
