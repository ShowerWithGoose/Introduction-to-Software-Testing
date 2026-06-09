package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class VarDefNode extends ASTNode{
    ASTNodes type = ASTNodes.VarDef;
    Token ident;
    boolean isArray;
    ConstExpNode constExpNode ;
    InitVal initVal ;

    public VarDefNode(Token ident, ConstExpNode constExpNode, InitVal initVal) {
        this.ident = ident;
        this.constExpNode = constExpNode;
        this.isArray = constExpNode != null;
        this.initVal = initVal;
    }

    public ASTNodes getType() {
        return type;
    }

    public ConstExpNode getConstExpNode() {
        return constExpNode;
    }

    public Token getIdent() {
        return ident;
    }

    public boolean isArray() {
        return isArray;
    }

    public InitVal getInitVal() {
        return initVal;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(ident.getType() + " " + ident.getToken() + "\n");
        if (constExpNode != null) {
            io.getParserWriter().write("LBRACK [\n");
            constExpNode.postOrderTraversal(io);
            io.getParserWriter().write("RBRACK ]\n");
        }
        if (initVal != null) {
            io.getParserWriter().write("ASSIGN =\n");
            initVal.postOrderTraversal(io);
        }
        io.getParserWriter().write("<VarDef>\n");
    }

    
    public void postOrderNoPrint() {

        if (constExpNode != null) {

            constExpNode.postOrderNoPrint();

        }
        if (initVal != null) {

            initVal.postOrderNoPrint();
        }

    }
}
