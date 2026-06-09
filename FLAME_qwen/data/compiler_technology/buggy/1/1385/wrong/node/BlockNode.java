package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;

public class BlockNode {
    // Block -> '{' { BlockItem } '}'

    private Token leftBraceToken;
    private ArrayList<BlockItemNode> blockItemNodes;
    private Token rightBraceToken;

    public BlockNode(Token leftBraceToken, ArrayList<BlockItemNode> blockItemNodes, Token rightBraceToken) {
        this.leftBraceToken = leftBraceToken;
        this.blockItemNodes = blockItemNodes;
        this.rightBraceToken = rightBraceToken;
    }
    
    public void print() throws IOException {
        leftBraceToken.print();
        if (!blockItemNodes.isEmpty()) {
            for (BlockItemNode blockItemNode: blockItemNodes) {
                blockItemNode.print();
            }
        }
        rightBraceToken.print();
        Io.Text.printWord("<Block>");
    }
    
}
