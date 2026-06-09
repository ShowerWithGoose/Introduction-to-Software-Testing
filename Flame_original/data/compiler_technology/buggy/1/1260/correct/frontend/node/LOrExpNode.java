package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class LOrExpNode {
    private LAndExpNode lAndExpNode;
    private Token orToken;
    private LOrExpNode lOrExpNode;
    public LOrExpNode(LAndExpNode lAndExpNode, Token orToken, LOrExpNode lOrExpNode){
        this.lAndExpNode = lAndExpNode;
        this.orToken = orToken;
        this.lOrExpNode = lOrExpNode;
    }
    public void print() {
        lAndExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<LOrExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
        if (orToken != null) {
            orToken.print();
            lOrExpNode.print();
        }
    }
}
