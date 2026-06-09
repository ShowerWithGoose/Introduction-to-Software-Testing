package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

public class ExpNode {
    private AddExpNode addExpNode;

    public ExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }
    public void print() {
        addExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<Exp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
