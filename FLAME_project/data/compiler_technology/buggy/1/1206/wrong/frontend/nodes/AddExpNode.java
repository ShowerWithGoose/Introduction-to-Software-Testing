package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:18
 */
public class AddExpNode {
    //AddExp → MulExp | AddExp ('+' | '−') MulExp
    MulExpNode mulExpNode;
    AddExpNode addExpNode;
    token op;
    public AddExpNode(MulExpNode mulExpNode,AddExpNode addExpNode,token op){
        this.mulExpNode=mulExpNode;
        this.addExpNode=addExpNode;
        this.op=op;
    }

    public void output()throws IOException {
        mulExpNode.output();
        out.write("<AddExp>");
        if(op!=null){
            out.write(op.toString());
            addExpNode.output();
        }
    }
}
