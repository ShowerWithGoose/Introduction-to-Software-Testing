package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class UnaryExpNode {
    private PrimaryExpNode primaryExpNode;
    private Token ident;
    private Token leftParentToken;
    private FuncRParamsNode funcRParamsNode;
    private Token rightParentToken;
    private UnaryOpNode unaryOpNode;
    private UnaryExpNode unaryExpNode;
    public UnaryExpNode(PrimaryExpNode primaryExpNode, Token ident, Token lParent, FuncRParamsNode funcRParamsNode, Token rParent, UnaryOpNode unaryOpNode, UnaryExpNode unaryExpNode){
        this.primaryExpNode = primaryExpNode;
        this.ident = ident;
        this.leftParentToken = lParent;
        this.funcRParamsNode = funcRParamsNode;
        this.rightParentToken = rParent;
        this.unaryOpNode = unaryOpNode;
        this.unaryExpNode = unaryExpNode;
    }
    public void print(){
        if(primaryExpNode != null){
            primaryExpNode.print();
        }else if(ident != null){
            ident.print();
            leftParentToken.print();
            if(funcRParamsNode != null){
                funcRParamsNode.print();
            }
            rightParentToken.print();
        }else if(unaryOpNode != null){
            unaryOpNode.print();
            unaryExpNode.print();
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<UnaryExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }    

}
