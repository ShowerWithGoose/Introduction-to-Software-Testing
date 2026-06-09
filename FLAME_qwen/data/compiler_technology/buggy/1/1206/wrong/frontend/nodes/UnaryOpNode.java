package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:21
 */
public class UnaryOpNode {
    //UnaryOp → '+' | '−' | '!'
    token op;
    public UnaryOpNode(token op){
        this.op=op;
    }

    public void output() throws IOException {
        out.write(op.toString());
        out.write("<UnaryOp>");
    }
}
