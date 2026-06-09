package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

import java.util.ArrayList;

public class BlockNode {
    //语句块 Block → '{' { BlockItem } '}'
    private Token leftBraceToken;
    private ArrayList<BlockItemNode> blockItemNodes;
    private Token rightBraceToken;

    public BlockNode(Token leftBraceToken, ArrayList<BlockItemNode> blockItemNodes, Token rightBraceToken) {
        this.leftBraceToken = leftBraceToken;
        this.blockItemNodes = blockItemNodes;
        this.rightBraceToken = rightBraceToken;
    }

    public void print() {
        IO.ParserOutput(leftBraceToken);
        for (BlockItemNode blockItemNode : blockItemNodes) {
            blockItemNode.print();
        }
        IO.ParserOutput(rightBraceToken);
        IO.ParserOutput(Parser.nodeType.get(NodeType.Block));
    }
}
