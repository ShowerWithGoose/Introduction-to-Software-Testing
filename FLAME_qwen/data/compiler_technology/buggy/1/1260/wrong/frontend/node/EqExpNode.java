package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class EqExpNode {
    private RelExpNode relExpNode;
    private Token operator;
    private EqExpNode eqExpNode;
    public EqExpNode(RelExpNode relExpNode, Token opToken, EqExpNode eqExpNode){
        this.relExpNode = relExpNode;
        this.operator = opToken;
        this.eqExpNode = eqExpNode;
    }
    public void print() {
        relExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<EqExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
        if (operator != null) {
            operator.print();
            eqExpNode.print();
        }
    }
}
