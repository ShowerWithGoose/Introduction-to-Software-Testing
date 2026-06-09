package frontend.nodes;

import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/9/30 12:03
 */
public class ConstExpNode {
    //ConstExp → AddExp
    AddExpNode addExpNode;
    public  ConstExpNode(AddExpNode addExpNode){
        this.addExpNode=addExpNode;
    }

    public void output() throws IOException {
        addExpNode.output();
        out.write("<ConstExp>");
    }
}
