package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class NumberNode extends ASTNode {

    ASTNodes type = ASTNodes.Number;
    private Token Number;

    public NumberNode(Token Number) {
        this.Number = Number;
    }

    public ASTNodes getType() {
        return type;
    }

    public Token getNumber() {
        return Number;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(Number.getType() + " " + Number.getToken() + "\n");
        io.getParserWriter().write("<Number>\n");
    }

    
    public void postOrderNoPrint() {

    }
}
