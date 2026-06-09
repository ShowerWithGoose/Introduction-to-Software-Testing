package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class LValNode {
    private Token ident;
    private Token lBrack;
    private Token rBrack;
    private ExpNode expNode;
    public LValNode(Token ident, Token lBrack, ExpNode expNode, Token rBrack){
        this.ident = ident;
        this.lBrack = lBrack;
        this.rBrack = rBrack;
        this.expNode = expNode;
    }
    public void print(){
        ident.print();
        if(lBrack != null){
            lBrack.print();
            expNode.print();
            rBrack.print();
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<LVal>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }

}
