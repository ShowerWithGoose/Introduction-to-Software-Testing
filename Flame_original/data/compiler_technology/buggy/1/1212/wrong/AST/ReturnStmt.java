package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class ReturnStmt extends ASTNode{
    ASTNodes type = ASTNodes.ReturnStmt;

    Token token;
    ExprNode expr;

    public ReturnStmt(Token token, ExprNode expr) {
        this.token = token;
        this.expr = expr;
    }

    public Token getToken() {
        return token;
    }

    public boolean isNull() {
        return expr == null;
    }

    public ASTNodes getType() {
        return type;
    }

    public ExprNode getExpr() {
        return expr;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("RETURNTK return\n");
        if (expr != null) expr.postOrderTraversal(io);
        io.getParserWriter().write("SEMICN ;\n");
    }

    
    public void postOrderNoPrint() {
        if (expr != null) expr.postOrderNoPrint();
    }
}
