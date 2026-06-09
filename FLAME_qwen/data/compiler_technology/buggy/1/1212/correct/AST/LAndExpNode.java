package AST;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
//逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp // 1.EqExp 2.&& 均需覆盖
public class LAndExpNode extends ASTNode{

    ASTNodes type = ASTNodes.LAndExp;
    ArrayList<EqExpNode> eqExpNodes;

    public LAndExpNode(ArrayList<EqExpNode> eqExpNodes) {
        this.eqExpNodes = eqExpNodes;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<EqExpNode> getEqExpNodes() {
        return eqExpNodes;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        for (int i = 0; i < eqExpNodes.size(); i++) {
            EqExpNode eqExpNode = eqExpNodes.get(i);
            eqExpNode.postOrderTraversal(io);
            if (i < eqExpNodes.size() - 1) {
                io.getParserWriter().write("<LAndExp>\n");
                io.getParserWriter().write("AND &&\n");
            }
        }
        io.getParserWriter().write("<LAndExp>\n");
    }

    
    public void postOrderNoPrint() {
        for (int i = 0; i < eqExpNodes.size(); i++) {
            EqExpNode eqExpNode = eqExpNodes.get(i);
            eqExpNode.postOrderNoPrint();
            if (i < eqExpNodes.size() - 1) {

            }
        }
    }
}
