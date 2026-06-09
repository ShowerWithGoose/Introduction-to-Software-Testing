package node;


import token.Token;

import java.io.IOException;
import java.util.List;

public class FuncFParamNode {
    //  FuncFParam â†’ BType Ident ['[' ']']

    private BTypeNode bTypeNode;
    private Token ident;
    private Token leftBracket;
    private Token rightBracket;

    public FuncFParamNode(BTypeNode bTypeNode, Token ident, Token leftBracket, Token rightBracket) {
        this.bTypeNode = bTypeNode;
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
    }
    
    public void print() throws IOException {
        bTypeNode.print();
        ident.print();
        if (leftBracket!=null) {
            leftBracket.print();
            rightBracket.print();
        }
        Io.Text.printWord("<FuncFParam>");
    }

}
