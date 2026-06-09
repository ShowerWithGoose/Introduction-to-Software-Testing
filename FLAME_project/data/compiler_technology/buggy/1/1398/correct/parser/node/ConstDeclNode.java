package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class ConstDeclNode {
    BTypeNode bTypeNode;
    ArrayList<ConstDefNode> constDefNodes;
    ArrayList<Token> commas;
    Token constTK;
    Token semicn;

    public ConstDeclNode(BTypeNode bTypeNode, ArrayList<ConstDefNode> constDefNodes, ArrayList<Token> commas, Token constTK, Token semicn) {
        this.bTypeNode = bTypeNode;
        this.constDefNodes = constDefNodes;
        this.commas = commas;
        this.constTK = constTK;
        this.semicn = semicn;
    }

    public void print() {
        constTK.print();
        bTypeNode.print();
        constDefNodes.get(0).print();
        for (int i = 1; i < constDefNodes.size(); i++)
        {
            commas.get(i - 1).print();
            constDefNodes.get(i).print();
        }
        semicn.print();
        System.out.println(NodeType.ConstDecl);
    }

}
