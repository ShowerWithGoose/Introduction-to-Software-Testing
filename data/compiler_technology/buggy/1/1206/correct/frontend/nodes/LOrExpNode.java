package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:18
 */
public class LOrExpNode {
    // LOrExp → LAndExp | LOrExp '||' LAndExp
    LAndExpNode lAndExpNode;
    LOrExpNode lOrExpNode;
    token or;
    public LOrExpNode(LOrExpNode lOrExpNode,token or,LAndExpNode lAndExpNode){
        this.lAndExpNode=lAndExpNode;
        this.lOrExpNode=lOrExpNode;
        this.or=or;
    }

    public void output() throws IOException {
        lAndExpNode.output();
        out.write("<LOrExp>");
        if(or!=null){
            out.write(or.toString());
            lOrExpNode.output();
        }
    }
}
