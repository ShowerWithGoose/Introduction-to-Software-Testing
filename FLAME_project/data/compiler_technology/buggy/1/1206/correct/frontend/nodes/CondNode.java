package frontend.nodes;

import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:17
 */
public class CondNode {
    //Cond → LOrExp
    LOrExpNode lOrExpNode;
    public CondNode(LOrExpNode lOrExpNode){
        this.lOrExpNode=lOrExpNode;
    }

    public void output() throws IOException {
        lOrExpNode.output();
        out.write("<Cond>");
    }
}
