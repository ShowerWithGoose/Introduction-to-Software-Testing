package AST;

import IO.*;

import java.io.IOException;

public class CondNode extends ASTNode {

    ASTNodes type = ASTNodes.Cond;
    LOrExpNode lOrExpNode;
    public CondNode(LOrExpNode lOrExpNode) {
        this.lOrExpNode = lOrExpNode;
    }

    public ASTNodes getType() {
        return type;
    }

    public LOrExpNode getLOrExpNode() {
        return lOrExpNode;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        lOrExpNode.postOrderTraversal(io);
        io.getParserWriter().write("<Cond>\n");
    }

    
    public void postOrderNoPrint() {
        lOrExpNode.postOrderNoPrint();
    }
}

