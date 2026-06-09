package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:22
 */
public class MulExpNode {
    //MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    UnaryExpNode unaryExpNode;
    MulExpNode mulExpNode;
    token op;
    public MulExpNode(UnaryExpNode unaryExpNode,MulExpNode mulExpNode,token op){
        this.mulExpNode=mulExpNode;
        this.unaryExpNode=unaryExpNode;
        this.op=op;
    }

    public void output() throws IOException {

        unaryExpNode.output();
        out.write("<MulExp>");
        if(op!=null){
            out.write(op.toString());
            mulExpNode.output();
        }
    }
}
