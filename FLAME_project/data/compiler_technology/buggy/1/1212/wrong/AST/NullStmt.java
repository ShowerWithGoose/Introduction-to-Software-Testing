package AST;
import IO.*;
public class NullStmt extends ASTNode{
    ASTNodes type = ASTNodes.NULL;

    public NullStmt() {

    }

    public ASTNodes getType() {
        return type;
    }


    
    public void postOrderTraversal(IO io) {

    }

    
    public void postOrderNoPrint() {

    }
}
