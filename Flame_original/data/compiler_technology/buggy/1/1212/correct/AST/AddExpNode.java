package AST;

import java.io.IOException;
import java.util.ArrayList;

import Lexer.*;

import IO.*;

public class AddExpNode extends ASTNode {

    ASTNodes type = ASTNodes.AddExp;

    private ArrayList<MulExpNode> mulExpNodes;

    private ArrayList<Token> ops;

    public AddExpNode(ArrayList<MulExpNode> mulExpNodes, ArrayList<Token> ops) {
        this.mulExpNodes = mulExpNodes;
        this.ops = ops;
    }

    public ArrayList<MulExpNode> getMulExpNodes() {
        return mulExpNodes;
    }

    public ArrayList<Token> getOps() {
        return ops;
    }

    public ASTNodes getType() {
        return type;
    }

    public void postOrderTraversal(IO io) throws IOException {
        for(int i = 0; i < mulExpNodes.size(); i++) {
            mulExpNodes.get(i).postOrderTraversal(io);
            if(i < ops.size()) {
                io.getParserWriter().write("<AddExp>\n");
                io.getParserWriter().write(ops.get(i).getType() + " " + ops.get(i).getToken() + "\n");
            }
        }
        io.getParserWriter().write("<AddExp>\n");
    }

    
    public void postOrderNoPrint() {
        for(int i = 0; i < mulExpNodes.size(); i++) {
            mulExpNodes.get(i).postOrderNoPrint();
            if(i < ops.size()) {

            }
        }

    }
}
