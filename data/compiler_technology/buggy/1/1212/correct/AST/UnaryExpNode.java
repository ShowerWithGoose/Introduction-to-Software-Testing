package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class UnaryExpNode extends ASTNode {

    ASTNodes type = ASTNodes.UnaryExp;
    PrimaryExp primaryExp = null;

    Token ident = null;

    FuncRNode funcRNodes = null;

    UnaryOpNode op = null;

    UnaryExpNode unaryExpNode;

    int t;
    public UnaryExpNode(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
        this.t = 1;
    }

    public UnaryExpNode(Token ident, FuncRNode funcRNodes) {
        this.ident = ident;
        this.funcRNodes = funcRNodes;
        this.t = 2;
    }

    public UnaryExpNode(UnaryOpNode op, UnaryExpNode unaryExpNode) {
        this.op = op;
        this.unaryExpNode = unaryExpNode;
        this.t = 3;
    }

    public ASTNodes getType() {
        return type;
    }

    public PrimaryExp getPrimaryExp() {
        return primaryExp;
    }

    public Token getIdent() {
        return ident;
    }

    public FuncRNode getFuncRNodes() {
        return funcRNodes;
    }

    public UnaryOpNode getOp() {
        return op;
    }

    public UnaryExpNode getUnaryExpNode() {
        return unaryExpNode;
    }

    public int getT() {
        return t;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        if(primaryExp != null) primaryExp.postOrderTraversal(io);
        if(ident != null) {
            io.getParserWriter().write(ident.getType() + " " + ident.getToken() + "\n");
            io.getParserWriter().write("LPARENT (\n");
            if (funcRNodes != null) {
                funcRNodes.postOrderTraversal(io);
            }
            io.getParserWriter().write("RPARENT )\n");
        }
        if(op != null) {
            op.postOrderTraversal(io);
            unaryExpNode.postOrderTraversal(io);
        }
        io.getParserWriter().write("<UnaryExp>\n");
    }

    
    public void postOrderNoPrint() {
        if(primaryExp != null) primaryExp.postOrderNoPrint();
        if(ident != null) {
            if (funcRNodes != null) {
                funcRNodes.postOrderNoPrint();
            }
        }
        if(op != null) {
            op.postOrderNoPrint();
            unaryExpNode.postOrderNoPrint();
        }
    }
}
