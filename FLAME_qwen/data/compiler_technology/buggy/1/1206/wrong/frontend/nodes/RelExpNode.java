package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:22
 */
public class RelExpNode {
    //RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    RelExpNode relExpNode;
    AddExpNode addExpNode;
    token op;
    public RelExpNode(RelExpNode relExpNode,AddExpNode addExpNode,token op){
        this.relExpNode=relExpNode;
        this.addExpNode=addExpNode;
        this.op=op;
    }

    public void output()throws IOException {
        addExpNode.output();
        out.write("<RelExp>");
        if(op!=null){
            out.write(op.toString());
            relExpNode.output();
        }
    }
}
