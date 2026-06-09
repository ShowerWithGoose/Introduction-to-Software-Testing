package Node;

import frontend.Parser;

import java.util.ArrayList;
import Token.*;

public class BlockNode {
    // Block â†’ '{' { BlockItem } '}'
    ArrayList<BlockItemNode> blockItemNodes;
    Token leftBrace;
    Token rightBrace;
    public BlockNode(ArrayList<BlockItemNode> blockItemNodes, Token leftBrace, Token rightBrace){
        this.blockItemNodes = blockItemNodes;
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
    }

    public void print(){
        Parser.getInstance().output(leftBrace);
        for(BlockItemNode b : blockItemNodes){
            b.print();
        }
        Parser.getInstance().output(rightBrace);
        Parser.getInstance().output(NodeType.Block);
    }
}
