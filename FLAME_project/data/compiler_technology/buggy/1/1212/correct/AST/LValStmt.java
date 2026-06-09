package AST;
import IO.*;

import java.io.IOException;

public class LValStmt extends ASTNode{

    ASTNodes type = ASTNodes.LValStmt;
    LValNode LVal;

    ExprNode expr;

    public LValStmt(LValNode LVal, ExprNode expr) {
        this.LVal = LVal;
        this.expr = expr;
    }

    public ExprNode getExpr() {
        return expr;
    }

    public ASTNodes getType() {
        return type;
    }

    public LValNode getLVal() {
        return LVal;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        LVal.postOrderTraversal(io);
        io.getParserWriter().write("ASSIGN =\n");
        expr.postOrderTraversal(io);
        io.getParserWriter().write("SEMICN ;\n");
    }

    
    public void postOrderNoPrint() {
        LVal.postOrderNoPrint();

        expr.postOrderNoPrint();

    }
}
