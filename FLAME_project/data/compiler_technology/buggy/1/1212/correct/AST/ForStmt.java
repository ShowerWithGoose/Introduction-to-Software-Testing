package AST;
import IO.*;

import java.io.IOException;

public class ForStmt extends ASTNode {
    ASTNodes type = ASTNodes.ForStmt;
    LValNode lValNode;
    ExprNode exprNode;


    public ForStmt(LValNode lValNode, ExprNode exprNode) {
        this.lValNode = lValNode;
        this.exprNode = exprNode;
    }

    public ASTNodes getType() {
        return type;
    }

    public ExprNode getExprNode() {
        return exprNode;
    }

    public LValNode getlValNode() {
        return lValNode;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        lValNode.postOrderTraversal(io);
        io.getParserWriter().write("ASSIGN =\n");
        exprNode.postOrderTraversal(io);
        io.getParserWriter().write("<ForStmt>\n");
    }

    
    public void postOrderNoPrint() {
        lValNode.postOrderNoPrint();
        exprNode.postOrderNoPrint();
    }
}
