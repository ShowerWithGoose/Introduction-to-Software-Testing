package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class LOrExpNode {
    // 逻辑或表达式 LOrExp → LAndExp[ '||' LOrExp]
    private LAndExpNode lAndExpNode;
    private Token orToken;
    private LOrExpNode lOrExpNode;

    public LOrExpNode(LAndExpNode lAndExpNode, Token operator, LOrExpNode lOrExpNode) {
        this.lAndExpNode = lAndExpNode;
        this.orToken = operator;
        this.lOrExpNode = lOrExpNode;
    }

    public LAndExpNode getLAndExpNode() {
        return lAndExpNode;
    }

    public LOrExpNode getLOrExpNode() {
        return lOrExpNode;
    }

    public void print() {
        lAndExpNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.LOrExp));
        if (orToken != null) {
            MyIO.writeToken(orToken.toString());
            lOrExpNode.print();
        }
    }
}
