package AST;

import Lexer.Token;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
//关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp // 1.AddExp 2.
//< 3.> 4.<= 5.>= 均需覆盖
public class RelExpNode extends  ASTNode {

    ASTNodes type = ASTNodes.RelExp;
    ArrayList<AddExpNode> addExpNodes;

    ArrayList<Token> ops;

    public RelExpNode(ArrayList<AddExpNode> addExpNodes, ArrayList<Token> ops) {
        this.addExpNodes = addExpNodes;
        this.ops = ops;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<Token> getOps() {
        return ops;
    }

    public ArrayList<AddExpNode> getAddExpNodes() {
        return addExpNodes;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        for (int i = 0; i < addExpNodes.size(); i++){
            addExpNodes.get(i).postOrderTraversal(io);
            if (i < ops.size()){
                io.getParserWriter().write("<RelExp>\n");
                io.getParserWriter().write(ops.get(i).getType() + " " + ops.get(i).getToken() + "\n");
            }
        }
        io.getParserWriter().write("<RelExp>\n");
    }

    
    public void postOrderNoPrint() {
        for (int i = 0; i < addExpNodes.size(); i++){
            addExpNodes.get(i).postOrderNoPrint();
            if (i < ops.size()){

            }
        }
    }
}
