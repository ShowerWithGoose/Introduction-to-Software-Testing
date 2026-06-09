package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.ArrayList;
import java.util.List;

public class BlockNode {
    // 语句块 Block -> '{' { BlockItem } '}'

    private Token lbraceToken;
    private ArrayList<BlockItemNode> blockItemNodes;
    private Token rbraceToken;

    public BlockNode(Token lbraceToken, ArrayList<BlockItemNode> blockItemNodes, Token rbraceToken) {
        this.lbraceToken = lbraceToken;
        this.blockItemNodes = blockItemNodes;
        this.rbraceToken = rbraceToken;
    }

    public List<BlockItemNode> getBlockItemNodes() {
        return blockItemNodes;
    }

    public void print() {
        MyIO.writeToken(lbraceToken.toString());
        for (BlockItemNode blockItemNode : blockItemNodes) {
            blockItemNode.print();
        }
        MyIO.writeToken(rbraceToken.toString());
        MyIO.writeNode(Parser.nodeType.get(NodeType.Block));
    }
}
