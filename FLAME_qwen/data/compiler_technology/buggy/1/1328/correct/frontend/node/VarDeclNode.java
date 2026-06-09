package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.ArrayList;

public class VarDeclNode {
    // 变量声明 VarDecl -> BType VarDef { ',' VarDef } ';'
    private BTypeNode bTypeNode;
    private ArrayList<VarDefNode> varDefNodes;
    private Token commaToken;
    private Token semicnToken;

    public VarDeclNode(BTypeNode bTypeNode, ArrayList<VarDefNode> varDefNodes, Token commaToken, Token semicnToken) {
        this.bTypeNode = bTypeNode;
        this.varDefNodes = varDefNodes;
        this.commaToken = commaToken;
        this.semicnToken = semicnToken;
    }

    public ArrayList<VarDefNode> getVarDefNodes() {
        return varDefNodes;
    }

    public void print() {
        bTypeNode.print();
        varDefNodes.get(0).print();
        for (int i = 1; i < varDefNodes.size(); i++) {
            MyIO.writeToken(commaToken.toString());
            varDefNodes.get(i).print();
        }
        MyIO.writeToken(semicnToken.toString());
        MyIO.writeNode(Parser.nodeType.get(NodeType.VarDecl));
    }
}
