package Node;
import Token.*;
import frontend.Parser;

public class LValNode {
    // LVal â†’ Ident ['[' Exp ']']
    private Token ident;
    private ExpNode expNode;
    Token leftBrack;
    Token rightBrack;
    public LValNode(Token ident, ExpNode expNode, Token leftBrack, Token rightBrack){
        this.ident = ident;
        this.leftBrack = leftBrack;
        this.rightBrack = rightBrack;
        this.expNode = expNode;
    }

    public void print(){
        Parser.getInstance().output(ident);
        if(leftBrack != null){
            Parser.getInstance().output(leftBrack);
            expNode.print();
            Parser.getInstance().output(rightBrack);
        }
        Parser.getInstance().output(NodeType.LVal);
    }

}
