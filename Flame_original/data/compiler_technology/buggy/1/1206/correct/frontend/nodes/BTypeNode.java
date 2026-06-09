package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/9/30 11:36
 */
public class BTypeNode {
    //BType → 'int' | 'char'
    token typeToken;
    public BTypeNode(token typeToken){
        this.typeToken=typeToken;
    }

    public void output() throws IOException {
        out.write(typeToken.toString());
    }
}
