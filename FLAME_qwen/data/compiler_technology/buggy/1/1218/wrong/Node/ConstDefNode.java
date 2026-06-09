package Node;
import Token.*;
import frontend.Parser;

public class ConstDefNode {
    // ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private Token ident;
    private Token leftBrack;
    private Token rightBrack;
    private ConstExpNode constExpNode;
    private ConstInitValNode constInitValNode;
    Token eqToken;

    public ConstDefNode(Token ident, Token leftBrack, Token rightBrack, ConstExpNode constExpNode, Token eqToken, ConstInitValNode constInitValNode){
        this.ident = ident;
        this.leftBrack = leftBrack;
        this.rightBrack = rightBrack;
        this.constExpNode = constExpNode;
        this.eqToken = eqToken;
        this.constInitValNode = constInitValNode;
    }

    public void print(){
        Parser.getInstance().output(ident);
        if(constExpNode != null){
            Parser.getInstance().output(leftBrack);
            constExpNode.print();
            Parser.getInstance().output(rightBrack);
        }
        Parser.getInstance().output(eqToken);
        constInitValNode.print();
        Parser.getInstance().output(NodeType.ConstDef);
    }
}
