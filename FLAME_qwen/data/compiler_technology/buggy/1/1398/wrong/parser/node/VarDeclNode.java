package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class VarDeclNode {
    BTypeNode bTypeNode;
    ArrayList<VarDefNode> varDefNodes;
    ArrayList<Token> commas;
    Token semicnTK;

    public VarDeclNode(BTypeNode bTypeNode, ArrayList<VarDefNode> varDefNodes, ArrayList<Token> commas, Token semicnTK) {
        this.bTypeNode = bTypeNode;
        this.varDefNodes = varDefNodes;
        this.commas = commas;
        this.semicnTK = semicnTK;
    }

    public void print() {
        bTypeNode.print();
        varDefNodes.get(0).print();
        for (int i = 1; i < varDefNodes.size(); i++)
        {
            commas.get(i-1).print();
            varDefNodes.get(i).print();
        }
        semicnTK.print();
        System.out.println(NodeType.VarDecl);
    }
}
