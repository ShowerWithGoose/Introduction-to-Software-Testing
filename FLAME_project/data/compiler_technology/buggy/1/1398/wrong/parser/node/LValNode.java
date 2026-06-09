package parser.node;

import lexer.Token;
import lexer.TokenType;
import parser.NodeType;

public class LValNode {
    Token identTK;
    Token lBrackTK, rBrackTK;
    ExpNode expNode;
    public LValNode(Token identTK, Token lBrackTK, Token rBrackTK, ExpNode expNode) {
        this.identTK = identTK;
        this.lBrackTK = lBrackTK;
        this.rBrackTK = rBrackTK;
        this.expNode = expNode;
    }
    public void print() {
        identTK.print();
        if (lBrackTK != null)
        {
            lBrackTK.print();
            expNode.print();
            rBrackTK.print();
        }
        System.out.println(NodeType.LVal);
    }

}
