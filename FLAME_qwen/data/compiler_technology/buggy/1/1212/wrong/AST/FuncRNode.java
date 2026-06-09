package AST;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
//FuncRParams â†’ Exp { ',' Exp }
public class FuncRNode extends ASTNode {

    ASTNodes type = ASTNodes.FuncRParams;

    private ArrayList<ExprNode> exprs;

    public FuncRNode(ArrayList<ExprNode> exprs) {
        this.exprs = exprs;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<ExprNode> getExprs() {
        return exprs;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        for(ExprNode exp : exprs) {
            exp.postOrderTraversal(io);
            if(exprs.indexOf(exp) != exprs.size() - 1) {
                io.getParserWriter().write("COMMA ,\n");
            }
        }
        if (!exprs.isEmpty()) {
            io.getParserWriter().write("<FuncRParams>\n");
        }
    }

    
    public void postOrderNoPrint() {
        for(ExprNode exp : exprs) {
            exp.postOrderNoPrint();
            if(exprs.indexOf(exp) != exprs.size() - 1) {

            }
        }
    }


}
