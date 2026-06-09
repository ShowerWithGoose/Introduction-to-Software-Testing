package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.ArrayList;

public class ConstDeclNode {
    // 常量声明 ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
    private Token constToken;
    private BTypeNode bTypeNode;
    private ArrayList<ConstDefNode> constDefNodes;
    private Token commaToken;
    private Token semicnToken;

    public ConstDeclNode(Token constToken, BTypeNode bTypeNode, ArrayList<ConstDefNode> constDefNodes, Token commaToken, Token semicnToken) {
        this.constToken = constToken;
        this.bTypeNode = bTypeNode;
        this.constDefNodes = constDefNodes;
        this.commaToken = commaToken;
        this.semicnToken = semicnToken;
    }

    public BTypeNode getbTypeNode() {
        return bTypeNode;
    }
    public ArrayList<ConstDefNode> getConstDefNodes() {
        return constDefNodes;
    }

    public void print() {
        MyIO.writeToken(constToken.toString());
        bTypeNode.print();
        constDefNodes.get(0).print();
        for (int i = 1; i < constDefNodes.size(); i++) {
            MyIO.writeToken(commaToken.toString());
            constDefNodes.get(i).print();
        }
        MyIO.writeToken(semicnToken.toString());
        MyIO.writeNode(Parser.nodeType.get(NodeType.ConstDecl));
    }
}
