package parser.node;

import parser.NodeType;

public class DeclNode {
    ConstDeclNode constDeclNode;
    VarDeclNode varDeclNode;

    public DeclNode(ConstDeclNode constDeclNode, VarDeclNode varDeclNode) {
        this.constDeclNode = constDeclNode;
        this.varDeclNode = varDeclNode;
    }
    public void print() {
        if (constDeclNode != null)
        {
            constDeclNode.print();
        }
        else
        {
            varDeclNode.print();
        }
    }
}
