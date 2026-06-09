package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class LAndExpNode {
    private EqExpNode eqExpNode;
    private Token andToken;
    private LAndExpNode lAndExpNode;
    public LAndExpNode(EqExpNode eqExpNode, Token andToken, LAndExpNode lAndExpNode){
        this.eqExpNode = eqExpNode;
        this.andToken = andToken;
        this.lAndExpNode = lAndExpNode;
    }
    public void print() {
        eqExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<LAndExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
        if (andToken != null) {
            andToken.print();
            lAndExpNode.print();
        }
    }
}
