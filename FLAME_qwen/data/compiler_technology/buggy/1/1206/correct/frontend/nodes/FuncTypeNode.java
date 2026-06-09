package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:14
 */
public class FuncTypeNode {
    // FuncType → 'void' | 'int' | 'char'
    token typeToken;
    public FuncTypeNode(token typeToken){
        this.typeToken=typeToken;
    }

    public void output() throws IOException {
        out.write(typeToken.toString());
        out.write("<FuncType>");
    }
}
