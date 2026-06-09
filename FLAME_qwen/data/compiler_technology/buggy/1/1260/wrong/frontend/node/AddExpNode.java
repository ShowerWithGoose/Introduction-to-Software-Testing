package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class AddExpNode {
    private MulExpNode mulExpNode;
    private Token opToken;
    private AddExpNode addExpNode;
    public AddExpNode(MulExpNode mulExpNode, Token opToken, AddExpNode addExpNode){
        this.mulExpNode = mulExpNode;
        this.opToken = opToken;
        this.addExpNode = addExpNode;
    }
    public void print(){
        mulExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<AddExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
        if(opToken != null){
            opToken.print();
            addExpNode.print();
        }
    }
}
