package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class PrimaryExpNode {
    private Token leftParentToken;
    private ExpNode expNode;
    private Token rightParentToken;
    private LValNode lValNode;
    private NumberNode numberNode;
    private CharacterNode characterNode;
    public PrimaryExpNode(Token lParent, ExpNode expNode, Token rParent, LValNode lValNode, NumberNode numberNode, CharacterNode characterNode){
        this.leftParentToken = lParent;
        this.expNode = expNode;
        this.rightParentToken = rParent;
        this.lValNode = lValNode;
        this.numberNode = numberNode;
        this.characterNode = characterNode;
    }
    public void print(){
        if(leftParentToken != null){
            leftParentToken.print();
            expNode.print();
            rightParentToken.print();
        }else if(lValNode != null){
            lValNode.print();
        }else if(numberNode != null){
            numberNode.print();
        }else{
            characterNode.print();
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<PrimaryExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
