package AST;
import IO.*;

import java.io.IOException;

public class MainFuncDef extends ASTNode {

    ASTNodes type = ASTNodes.MainFuncDef;
    BlockNode blockNode;

    public MainFuncDef(BlockNode blockNode) {
        this.blockNode = blockNode;
    }

    public ASTNodes getType() {
        return type;
    }

    public BlockNode getBlockNode() {
        return blockNode;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("INTTK int\n");
        io.getParserWriter().write("MAINTK main\n");
        io.getParserWriter().write("LPARENT (\n");
        io.getParserWriter().write("RPARENT )\n");
        blockNode.postOrderTraversal(io);
        io.getParserWriter().write("<MainFuncDef>\n");
    }

    
    public void postOrderNoPrint() {
        blockNode.postOrderNoPrint();
    }
}
