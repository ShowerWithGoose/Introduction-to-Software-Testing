package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;

public class FuncDefNode {
    private FuncTypeNode funcTypeNode;
    private Token ident;
    private Token lParent;
    private FuncFParamsNode funcFParamsNode;
    private Token rParent;
    private BlockNode blockNode;
    public FuncDefNode(FuncTypeNode funcTypeNode, Token ident, Token lParent, FuncFParamsNode funcFParamsNode, Token rParent, BlockNode blockNode){
        this.funcTypeNode = funcTypeNode;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParamsNode = funcFParamsNode;
        this.rParent = rParent;
        this.blockNode = blockNode;
    }
    public void print(){
        funcTypeNode.print();
        ident.print();
        lParent.print();
        if (funcFParamsNode != null) {
            funcFParamsNode.print();
        }
        rParent.print();
        blockNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<FuncDef>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }

}
