package parser.node;

import lexer.Token;
import parser.NodeType;

public class ConstDefNode {
    Token identTK;
    Token lBrackTK;
    Token rBrackTK;
    ConstExpNode constExpNode;
    Token assignTK;
    ConstInitValNode constInitValNode;

    public ConstDefNode(Token identTK, Token lBrackTK, Token rBrackTK, ConstExpNode constExpNode, Token assignTK, ConstInitValNode constInitValNode) {
        this.identTK = identTK;
        this.lBrackTK = lBrackTK;
        this.rBrackTK = rBrackTK;
        this.constExpNode = constExpNode;
        this.assignTK = assignTK;
        this.constInitValNode = constInitValNode;
    }

    public void print() {
        identTK.print();
        if (lBrackTK != null)
        {
            lBrackTK.print();
            constExpNode.print();
            rBrackTK.print();
        }
        assignTK.print();
        constInitValNode.print();
        System.out.println(NodeType.ConstDef);

    }
}
