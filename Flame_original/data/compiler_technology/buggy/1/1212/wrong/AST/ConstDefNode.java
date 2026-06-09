package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class ConstDefNode extends ASTNode {

    ASTNodes type = ASTNodes.ConstDef;

    public Token ident;
    public ConstExpNode constExpNode;

    public ConstInitValNode constInitValNode;

    public boolean isArray;

    public ConstDefNode(Token ident, ConstExpNode constExpNode, ConstInitValNode constInitValNode) {
        this.ident = ident;
        this.constExpNode = constExpNode;
        isArray = constExpNode != null;
        this.constInitValNode = constInitValNode;
    }

    public ASTNodes getType() {
        return type;
    }

    public Token getIdent() {
        return ident;
    }

    public ConstExpNode getConstExpNode() {
        return constExpNode;
    }

    public ConstInitValNode getConstInitValNode() {
        return constInitValNode;
    }

    public boolean isArray() {
        return isArray;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(this.ident.getType() + " " + this.ident.getToken() + "\n");
        if (constExpNode != null) {
            io.getParserWriter().write("LBRACK [\n");
            constExpNode.postOrderTraversal(io);
            io.getParserWriter().write("RBRACK ]\n");
        }
        io.getParserWriter().write("ASSIGN =\n");
        constInitValNode.postOrderTraversal(io);
        io.getParserWriter().write("<ConstDef>\n");
    }

    
    public void postOrderNoPrint() {
        if (constExpNode != null) {
            constExpNode.postOrderNoPrint();
        }
        constInitValNode.postOrderNoPrint();
    }
}
