package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

public class ConstExpNode {
    private AddExpNode addExpNode;
    public ConstExpNode(AddExpNode addExpNode){
        this.addExpNode = addExpNode;
    }
    public void print(){
        addExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<ConstExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
