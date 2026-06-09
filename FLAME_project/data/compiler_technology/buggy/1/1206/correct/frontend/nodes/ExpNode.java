package frontend.nodes;

import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:14
 */
public class ExpNode {
    //Exp → AddExp
    AddExpNode addExpNode;
    public ExpNode(AddExpNode addExpNode){
        this.addExpNode=addExpNode;
    }

    public void output() throws IOException {
        addExpNode.output();
        out.write("<Exp>");
    }
}
