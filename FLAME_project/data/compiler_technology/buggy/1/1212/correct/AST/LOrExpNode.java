package AST;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
//逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp // 1.LAndExp 2.|| 均需覆盖
public class LOrExpNode extends ASTNode{

    ASTNodes type = ASTNodes.LOrExp;
    ArrayList<LAndExpNode> lAndExpNodes;

    public LOrExpNode(ArrayList<LAndExpNode> lAndExpNodes) {
        this.lAndExpNodes = lAndExpNodes;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<LAndExpNode> getLAndExpNodes() {
        return lAndExpNodes;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        for (int i = 0; i < lAndExpNodes.size(); i++) {
            LAndExpNode lAndExpNode = lAndExpNodes.get(i);
            lAndExpNode.postOrderTraversal(io);
            if (i!= lAndExpNodes.size() - 1) {
                io.getParserWriter().write("<LOrExp>\n");
                io.getParserWriter().write("OR ||\n");
            }
        }
        io.getParserWriter().write("<LOrExp>\n");
    }

    
    public void postOrderNoPrint() {
        for (int i = 0; i < lAndExpNodes.size(); i++) {
            LAndExpNode lAndExpNode = lAndExpNodes.get(i);
            lAndExpNode.postOrderNoPrint();
            if (i!= lAndExpNodes.size() - 1) {

            }
        }
    }


}
