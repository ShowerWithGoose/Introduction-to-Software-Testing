package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:16
 */
public class BlockNode {
    //Block → '{' { BlockItem } '}'
    token lbrace;
    token rbrace;
    ArrayList<BlockItemNode> blockItemNodes;
    public BlockNode(token lbrace,ArrayList<BlockItemNode> blockItemNodes,token rbrace){
        this.lbrace=lbrace;
        this.rbrace=rbrace;
        this.blockItemNodes=blockItemNodes;
    }

    public void output() throws IOException {
        out.write(lbrace.toString());
        for(BlockItemNode blockItemNode:blockItemNodes){
            blockItemNode.output();
        }
        out.write(rbrace.toString());
        out.write("<Block>");
    }
}
