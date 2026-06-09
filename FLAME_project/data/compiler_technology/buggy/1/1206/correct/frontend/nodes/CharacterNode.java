package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:20
 */
public class CharacterNode {
    token charConst;
    public CharacterNode(token charConst){
        this.charConst=charConst;
    }

    public void output() throws IOException {
        out.write(charConst.toString());
        out.write("<Character>");
    }
}
