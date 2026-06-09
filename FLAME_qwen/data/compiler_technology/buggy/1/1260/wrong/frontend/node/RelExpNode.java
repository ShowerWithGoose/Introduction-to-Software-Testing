package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class RelExpNode {
    private AddExpNode addExpNode;
    private Token operator;
    private RelExpNode relExpNode;

    public RelExpNode(AddExpNode addExpNode, Token opToken, RelExpNode relExpNode){
        this.addExpNode = addExpNode;
        this.operator = opToken;
        this.relExpNode = relExpNode;
    }
    public void print(){
        addExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<RelExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
        if (operator != null) {
            operator.print();
            relExpNode.print();
        }
    }
}
