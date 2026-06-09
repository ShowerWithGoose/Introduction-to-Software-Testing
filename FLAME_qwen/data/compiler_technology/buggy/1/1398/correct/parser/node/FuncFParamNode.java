package parser.node;

import lexer.Token;
import lexer.TokenType;
import parser.NodeType;

public class FuncFParamNode {
    BTypeNode bTypeNode;
    Token identTK;
    Token lBrackTK;
    Token rBrackTK;

    public FuncFParamNode(BTypeNode bTypeNode, Token identTK, Token lBrackTK, Token rBrackTK) {
        this.bTypeNode = bTypeNode;
        this.identTK = identTK;
        this.lBrackTK = lBrackTK;
        this.rBrackTK = rBrackTK;
    }

    public void print() {
        bTypeNode.print();
        identTK.print();
        if (lBrackTK != null)
        {
            lBrackTK.print();
            rBrackTK.print();
        }
        System.out.println(NodeType.FuncFParam);
    }


}
