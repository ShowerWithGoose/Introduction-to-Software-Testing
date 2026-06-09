package AST;

import Lexer.Token;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;

public class ConstDeclNode extends ASTNode {

    ASTNodes type = ASTNodes.ConstDecl;

    Token Btype;

    ArrayList<ConstDefNode> constDefNodes;

    public ConstDeclNode(Token Btype, ArrayList<ConstDefNode> constDefNodes) {
        this.Btype = Btype;
        this.constDefNodes = constDefNodes;
    }

    public ASTNodes getType() {
        return type;
    }

    public Token getBtype() {
        return Btype;
    }

    public ArrayList<ConstDefNode> getConstDefNodes() {
        return constDefNodes;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("CONSTTK const\n");
        io.getParserWriter().write(Btype.getType() + " " + Btype.getToken() + "\n");
        for (ConstDefNode constDefNode : constDefNodes) {
            constDefNode.postOrderTraversal(io);
            if(this.constDefNodes.indexOf(constDefNode) != constDefNodes.size() - 1) {
                io.getParserWriter().write("COMMA ,\n");
            }
        }
        io.getParserWriter().write("SEMICN ;\n");
        io.getParserWriter().write("<ConstDecl>\n");
    }

    
    public void postOrderNoPrint() {
        String btype = Btype.getType();
        for (ConstDefNode constDefNode : constDefNodes) {

            constDefNode.postOrderNoPrint();
        }
    }
}
