package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class UnaryOpNode extends ASTNode {
    ASTNodes type = ASTNodes.UnaryOp;

    Token id;

    public UnaryOpNode(Token id) {
        this.id = id;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(id.getType() + " " + id.getToken() + "\n");
        io.getParserWriter().write("<UnaryOp>\n");
    }

    
    public void postOrderNoPrint() {

    }
}
