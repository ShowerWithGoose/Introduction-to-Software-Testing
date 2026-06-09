package AST;

import Lexer.Token;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
//相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp // 1.RelExp 2.== 3.!= 均需
//覆盖
public class EqExpNode extends ASTNode{

    ASTNodes type = ASTNodes.EqExp;
    ArrayList<RelExpNode> relExpNodes;

    ArrayList<Token> ops;

    public EqExpNode(ArrayList<RelExpNode> relExpNodes, ArrayList<Token> ops) {
        this.relExpNodes = relExpNodes;
        this.ops = ops;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<RelExpNode> getRelExpNodes() {
        return relExpNodes;
    }

    public ArrayList<Token> getOps() {
        return ops;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        for (int i = 0; i < relExpNodes.size(); i++) {
            relExpNodes.get(i).postOrderTraversal(io);
            if (i < ops.size()) {
                io.getParserWriter().write("<EqExp>\n");
                io.getParserWriter().write(ops.get(i).getType() + " " + ops.get(i).getToken() + "\n");
            }
        }
        io.getParserWriter().write("<EqExp>\n");
    }

    
    public void postOrderNoPrint() {
        for (int i = 0; i < relExpNodes.size(); i++) {
            relExpNodes.get(i).postOrderNoPrint();
            if (i < ops.size()) {

            }
        }
    }
}
