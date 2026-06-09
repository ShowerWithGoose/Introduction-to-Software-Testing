package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class PrimaryExpNode {
    public LValNode lValNode = null;
    public NumberNode numberNode = null;
    public CharacterNode characterNode = null;
    public Token leftParent = null;
    public Token rightParent = null;
    public ExpNode expNode = null;
    public PrimaryExpNode(LValNode lValNode){
        this.lValNode = lValNode;
    }
    public PrimaryExpNode(NumberNode numberNode){
        this.numberNode = numberNode;
    }
    public PrimaryExpNode(CharacterNode characterNode){
        this.characterNode = characterNode;
    }
    public PrimaryExpNode(ExpNode expNode, Token leftParent, Token rightParent){
        this.expNode = expNode;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
    }
    public void print() throws IOException {
        if(lValNode != null){
            lValNode.print();
        }
        else if(numberNode != null){
            numberNode.print();
        }
        else if(characterNode != null){
            characterNode.print();
        }
        else {
            OutputUtils.parserOutput(leftParent.toString());
            expNode.print();
            OutputUtils.parserOutput(rightParent.toString());
        }
        OutputUtils.parserOutput("<PrimaryExp>\n");
    }
}
