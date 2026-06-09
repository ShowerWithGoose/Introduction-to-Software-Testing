package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

public class CondNode {
    private LOrExpNode lOrExpNode;

    public CondNode(LOrExpNode lOrExpNode) {
        this.lOrExpNode = lOrExpNode;
    }

    public void print() {
        lOrExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<Cond>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
