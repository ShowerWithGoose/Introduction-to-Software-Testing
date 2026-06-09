package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;

public class MainFuncDefNode {
    private Token intToken;
    private Token mainToken;
    private Token lparentToken;
    private Token rparentToken;
    private BlockNode blockNode;
    public MainFuncDefNode(Token intToken, Token mainToken, Token lparentToken, Token rparentToken, BlockNode blockNode){
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.lparentToken = lparentToken;
        this.rparentToken = rparentToken;
        this.blockNode = blockNode;
    }
    public void print(){
        intToken.print();
        mainToken.print();
        lparentToken.print();
        rparentToken.print();
        blockNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<MainFuncDef>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
