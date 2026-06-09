package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class LValNode extends ASTNode {

    ASTNodes type = ASTNodes.LVal;
    private final Token ident;

    private ExprNode expr;

    public LValNode(Token id, ExprNode expr) {
        this.ident = id;
        this.expr = expr;
    }

    public ASTNodes getType() {
        return type;
    }

    public Token getId() {
        return ident;
    }

    public ExprNode getExpr() {
        return expr;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(ident.getType() + " " + ident.getToken() + "\n");
        if(expr != null) {
            io.getParserWriter().write("LBRACK [\n");
            expr.postOrderTraversal(io);
            io.getParserWriter().write("RBRACK ]\n");
        }
        io.getParserWriter().write("<LVal>\n");
    }

    
    public void postOrderNoPrint() {

        if(expr != null) {

            expr.postOrderNoPrint();

        }

    }
}
