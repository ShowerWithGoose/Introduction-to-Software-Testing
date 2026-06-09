package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:20
 */
public class NumberNode {
    token intConst;
    public NumberNode(token intConst){
        this.intConst=intConst;
    }

    public void output() throws IOException {
        out.write(intConst.toString());
        out.write("<Number>");
    }
}
