package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class BlockNode {
    ArrayList<BlockItemNode> blockItemNodes;
    Token lBraceTK;
    Token rBraceTK;

    public BlockNode(ArrayList<BlockItemNode> blockItemNodes, Token lBraceTK, Token rBraceTK) {
        this.blockItemNodes = blockItemNodes;
        this.lBraceTK = lBraceTK;
        this.rBraceTK = rBraceTK;
    }

    public void print() {
        lBraceTK.print();
        for (BlockItemNode blockItemNode : blockItemNodes)
        {
            blockItemNode.print();
        }
        rBraceTK.print();
        System.out.println(NodeType.Block);
    }
}
