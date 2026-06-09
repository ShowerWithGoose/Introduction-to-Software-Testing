package node;

import token.Token;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class ConstDefNode {
    // ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private Token ident;
    private Token leftBracket;
    private ConstExpNode constExpNode;
    private Token rightBracket;
    private Token equalToken;
    private ConstInitValNode constInitValNode;

    public ConstDefNode(Token ident, Token leftBracket, ConstExpNode constExpNode, Token rightBracket, Token equalToken, ConstInitValNode constInitValNode) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.constExpNode = constExpNode;
        this.rightBracket = rightBracket;
        this.equalToken = equalToken;
        this.constInitValNode = constInitValNode;
    }
    
    public void print() throws IOException {
        ident.print();
        if (constExpNode!=null) {
            leftBracket.print();
            constExpNode.print();
            rightBracket.print();
        }
        equalToken.print();
        constInitValNode.print();
        Io.Text.printWord("<ConstDef>");
    }
}
