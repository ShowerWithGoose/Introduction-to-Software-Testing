package AST;

import Lexer.Token;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
public class MulExpNode extends ASTNode{


    ASTNodes type = ASTNodes.MulExp;
    ArrayList<UnaryExpNode> unaryExpNodes;

    ArrayList<Token> ops;

    public MulExpNode(ArrayList<UnaryExpNode> unaryExpNodes, ArrayList<Token> ops) {
        this.unaryExpNodes = unaryExpNodes;
        this.ops = ops;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<Token> getOps() {
        return ops;
    }

    public ArrayList<UnaryExpNode> getUnaryExpNodes() {
        return unaryExpNodes;
    }


    
    public void postOrderTraversal(IO io) throws IOException {
        for(int i = 0; i < unaryExpNodes.size(); i++) {
            unaryExpNodes.get(i).postOrderTraversal(io);
            if(i < unaryExpNodes.size() - 1) {
                io.getParserWriter().write("<MulExp>\n");
                io.getParserWriter().write(ops.get(i).getType() + " " + ops.get(i).getToken() + "\n");
            }
        }
        io.getParserWriter().write("<MulExp>\n");
    }

    
    public void postOrderNoPrint() {
        for(int i = 0; i < unaryExpNodes.size(); i++) {
            unaryExpNodes.get(i).postOrderNoPrint();
            if(i < unaryExpNodes.size() - 1) {

            }
        }
    }
}
