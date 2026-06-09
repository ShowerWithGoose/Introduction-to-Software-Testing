package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/9/30 11:33
 */
public class MainFuncDefNode {
    //MainFuncDef → 'int' 'main' '(' ')' Block
    token intToken;
    token mainToken;
    token lparent;
    token rparent;
    BlockNode blockNode;
    public MainFuncDefNode(token intToken,token mainToken,token lparent,token rparent,BlockNode blockNode) {
        this.intToken=intToken;
        this.mainToken=mainToken;
        this.lparent=lparent;
        this.rparent=rparent;
        this.blockNode=blockNode;

    }

    public void output()throws IOException {
        out.write(intToken.toString());
        out.write(mainToken.toString());
        out.write(lparent.toString());
        out.write(rparent.toString());
        blockNode.output();
        out.write("<MainFuncDef>");
    }
}
