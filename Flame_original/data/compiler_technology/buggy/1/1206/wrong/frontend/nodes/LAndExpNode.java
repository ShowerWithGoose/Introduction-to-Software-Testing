package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:23
 */
public class LAndExpNode {
    //LAndExp → EqExp | LAndExp '&&' EqExp
    LAndExpNode lAndExpNode;
    EqExpNode eqExpNode;
    token and;
    public LAndExpNode(EqExpNode eqExpNode,token and,LAndExpNode lAndExpNode){
        this.lAndExpNode=lAndExpNode;
        this.eqExpNode=eqExpNode;
        this.and=and;
    }

    public void output() throws IOException {
        eqExpNode.output();
        out.write("<LAndExp>");
        if(and!=null){
            out.write(and.toString());
            lAndExpNode.output();
        }
    }
}
