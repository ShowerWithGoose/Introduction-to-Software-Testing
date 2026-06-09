package Node;
import Token.*;
import frontend.Parser;

public class FuncFParamNode {
    // FuncFParam â†’ BType Ident ['[' ']']
    private BTypeNode bTypeNode;
    private Token ident;
    private Token leftBrack;
    private Token rightBrack;
    public FuncFParamNode(BTypeNode bTypeNode, Token ident, Token leftBrack, Token rightBrack){
        this.bTypeNode = bTypeNode;
        this.ident = ident;
        this.leftBrack = leftBrack;
        this.rightBrack = rightBrack;
    }

    public void print(){
        bTypeNode.print();
        Parser.getInstance().output(ident);
        if(this.leftBrack != null){
            Parser.getInstance().output(leftBrack);
            Parser.getInstance().output(rightBrack);
        }
        Parser.getInstance().output(NodeType.FuncFParam);
    }
}
