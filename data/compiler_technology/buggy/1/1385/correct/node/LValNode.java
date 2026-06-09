package node;

import token.Token;

import java.io.IOException;
import java.util.List;

public class LValNode {
    // LVal â†’ Ident ['[' Exp ']']
    private Token ident;
    private Token leftBracket;
    private ExpNode expNode;
    private Token rightBracket;

    public LValNode(Token ident, Token leftBracket, ExpNode expNode,Token rightBracket) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.expNode = expNode;
        this.rightBracket = rightBracket;
    }
    
    public void print() throws IOException {
        ident.print();
        if (leftBracket!=null) {
            leftBracket.print();
            expNode.print();
            rightBracket.print();
        }
        Io.Text.printWord("<LVal>");
    }

}
