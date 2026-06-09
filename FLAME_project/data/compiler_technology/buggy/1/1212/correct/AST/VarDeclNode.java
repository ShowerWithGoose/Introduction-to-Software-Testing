package AST;

import Lexer.Token;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
public class VarDeclNode extends ASTNode {

    ASTNodes type = ASTNodes.VarDecl;
    Token t;

    ArrayList<VarDefNode> varDefNodes;

    public VarDeclNode(Token type, ArrayList<VarDefNode> varDefNodes) {
        this.t = type;
        this.varDefNodes = varDefNodes;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<VarDefNode> getVarDefNodes() {
        return varDefNodes;
    }

    public Token getTypeString() {
        return t;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(t.getType() + " " + t.getToken() + "\n");
        for (VarDefNode varDefNode : varDefNodes) {
            varDefNode.postOrderTraversal(io);
            if(varDefNodes.indexOf(varDefNode) != varDefNodes.size() - 1) {
                io.getParserWriter().write("COMMA ,\n");
            }
        }
        io.getParserWriter().write("SEMICN ;\n");
        io.getParserWriter().write("<VarDecl>\n");
    }

    
    public void postOrderNoPrint() {
        for (VarDefNode varDefNode : varDefNodes) {
            varDefNode.postOrderNoPrint();
            if(varDefNodes.indexOf(varDefNode) != varDefNodes.size() - 1) {

            }
        }
    }
}
