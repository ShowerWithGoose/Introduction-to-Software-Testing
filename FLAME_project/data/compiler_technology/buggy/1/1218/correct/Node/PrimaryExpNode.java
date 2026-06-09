package Node;

import Token.Token;
import frontend.Parser;

public class PrimaryExpNode {
    //PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character
    private enum PriExpType{
        Exp,
        LVal,
        Number,
        Character
    }
    private PriExpType type;
    private ExpNode expNode;
    private LValNode lValNode;
    private NumberNode numberNode;
    private CharacterNode characterNode;
    Token leftParent;
    Token rightParent;
    public PrimaryExpNode(ExpNode expNode, Token leftParent, Token rightParent){
        //'(' Exp ')'
        type = PriExpType.Exp;
        this.expNode = expNode;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
    }

    public PrimaryExpNode(LValNode lValNode){
        //LVal
        type = PriExpType.LVal;
        this.lValNode = lValNode;
    }

    public PrimaryExpNode(NumberNode numberNode){
        //Number
        type = PriExpType.Number;
        this.numberNode = numberNode;
    }

    public PrimaryExpNode(CharacterNode characterNode){
        //Character
        type = PriExpType.Character;
        this.characterNode = characterNode;
    }

    public void print(){
        switch (type){
            case Exp:
                Parser.getInstance().output(leftParent);
                expNode.print();
                Parser.getInstance().output(rightParent);
                break;
            case LVal:
                lValNode.print();
                break;
            case Number:
                numberNode.print();
                break;
            case Character:
                characterNode.print();
                break;
            default:
                break;
        }
        Parser.getInstance().output(NodeType.PrimaryExp);
    }
}
