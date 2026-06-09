package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:23
 */
public class EqExpNode {
    //EqExp → RelExp | EqExp ('==' | '!=') RelExp
    EqExpNode eqExpNode;
    RelExpNode relExpNode;
    token equalOrNotToken;
    public EqExpNode( EqExpNode eqExpNode, RelExpNode relExpNode, token equalOrNotToken){
        this.eqExpNode=eqExpNode;
        this.relExpNode=relExpNode;
        this.equalOrNotToken=equalOrNotToken;
    }

    public void output() throws IOException {
        relExpNode.output();
        out.write("<EqExp>");
        if(equalOrNotToken!=null){
            out.write(equalOrNotToken.toString());
            eqExpNode.output();
        }
    }
}
