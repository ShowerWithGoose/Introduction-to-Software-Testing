package frontend.node;

import frontend.Parser;
import utils.MyIO;

public class CondNode {
    // 条件表达式 Cond -> LOrExp

    private LOrExpNode lOrExpNode;

    public CondNode(LOrExpNode lOrExpNode) {
        this.lOrExpNode = lOrExpNode;
    }

    public LOrExpNode getLOrExpNode() {
        return lOrExpNode;
    }

    public void print() {
        lOrExpNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.Cond));
    }
}
