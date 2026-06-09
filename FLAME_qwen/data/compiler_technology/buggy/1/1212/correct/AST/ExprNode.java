package AST;
import IO.*;

import java.io.IOException;

//表达式 Exp → AddExp
public class ExprNode extends ASTNode {

    ASTNodes type = ASTNodes.Exp;
    AddExpNode addExpNode;

    public ExprNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }

    public ASTNodes getType() {
        return type;
    }

    public AddExpNode getAddExpNode() {
        return addExpNode;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        addExpNode.postOrderTraversal(io);
        io.getParserWriter().write("<Exp>\n");
    }

    
    public void postOrderNoPrint() {
        addExpNode.postOrderNoPrint();
    }
}
