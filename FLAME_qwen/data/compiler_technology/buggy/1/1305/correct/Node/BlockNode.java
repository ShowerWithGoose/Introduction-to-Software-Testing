package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class BlockNode {
    public Token leftBrace;
    public Token rightBrace;
    public List<BlockItemNode> blockItemNodes = new ArrayList<>();
    public BlockNode(Token leftBrace, Token rightBrace, List<BlockItemNode> blockItemNodes){
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
        this.blockItemNodes = blockItemNodes;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(leftBrace.toString());
        for(BlockItemNode blockItemNode : blockItemNodes){
            blockItemNode.print();
        }
        OutputUtils.parserOutput(rightBrace.toString());
        OutputUtils.parserOutput("<Block>\n");
    }
}
