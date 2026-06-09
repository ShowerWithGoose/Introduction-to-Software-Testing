package AST;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import IO.*;

public class BlockNode extends ASTNode {

    ASTNodes type = ASTNodes.Block;
    public List<BlockItem> blockItems;

    int endLine ;
    public BlockNode(ArrayList<BlockItem> blockItems, Integer endLine) {
        this.blockItems = blockItems;
        this.endLine = endLine;
    }

    public ASTNodes getType() {
        return type;
    }

    public List<BlockItem> getBlockItems() {
        return blockItems;
    }

    public int getEndLine() {
        return endLine;
    }
    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("LBRACE {\n");
        for (BlockItem item : blockItems) {
            item.postOrderTraversal(io);
        }
        io.getParserWriter().write("RBRACE }\n");
        io.getParserWriter().write("<Block>\n");
    }

    
    public void postOrderNoPrint() {
        for (BlockItem item : blockItems) {
            item.postOrderNoPrint();
        }
    }
}
