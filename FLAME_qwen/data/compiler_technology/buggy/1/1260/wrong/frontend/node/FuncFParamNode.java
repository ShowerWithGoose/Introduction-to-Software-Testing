package frontend.node;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

import frontend.Token;

public class FuncFParamNode {
     private BTypeNode bTypeNode;
    private Token ident;
    private Token lBrack;
    private Token rBrack;
    public FuncFParamNode(BTypeNode bTypeNode, Token ident, Token lBrack, Token rBrack){
        this.bTypeNode = bTypeNode;
        this.ident = ident;
        this.lBrack = lBrack;
        this.rBrack = rBrack;
    }
    public void print(){
        bTypeNode.print();
        ident.print();
        if(lBrack != null){
            lBrack.print();
            rBrack.print();
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<FuncFParam>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
