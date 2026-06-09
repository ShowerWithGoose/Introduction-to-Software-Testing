package node;

import token.Token;

import java.io.IOException;

public class PrimaryExpNode {
    // PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character

    private Token leftParentToken;
    private ExpNode expNode;
    private Token rightParentToken;
    private LValNode lValNode;
    private NumberNode numberNode;
    private CharacterNode characterNode;

    public PrimaryExpNode(Token leftParentToken, ExpNode expNode, Token rightParentToken) {
        this.leftParentToken = leftParentToken;
        this.expNode = expNode;
        this.rightParentToken = rightParentToken;
        lValNode = null;
        numberNode = null;
        characterNode = null;
    }

    public PrimaryExpNode(LValNode lValNode) {
        this.leftParentToken = null;
        this.expNode = null;
        this.rightParentToken = null;
        numberNode = null;
        characterNode = null;
        this.lValNode = lValNode;
    }

    public PrimaryExpNode(NumberNode numberNode) {
        this.leftParentToken = null;
        this.expNode = null;
        this.rightParentToken = null;
        lValNode = null;
        characterNode = null;
        this.numberNode = numberNode;
    }
    
    public PrimaryExpNode(CharacterNode characterNode) {
        this.leftParentToken = null;
        this.expNode = null;
        this.rightParentToken = null;
        lValNode = null;
        numberNode = null;
        this.characterNode = characterNode;
    }
    
    public void print() throws IOException {
        if (leftParentToken!=null) {
            leftParentToken.print();
            expNode.print();
            rightParentToken.print();
        }
        else if (lValNode!=null) {
            lValNode.print();
        }
        else if (numberNode!=null) {
            numberNode.print();
        }
        else {
            characterNode.print();
        }
        Io.Text.printWord("<PrimaryExp>");
    }

    
}
