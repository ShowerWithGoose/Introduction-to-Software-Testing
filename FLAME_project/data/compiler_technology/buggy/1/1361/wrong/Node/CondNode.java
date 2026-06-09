package Node;

import IOcontrol.IO;
import LexParser.Parser;

public class CondNode {
    //条件表达式 Cond → LOrExp
    private LOrExpNode lOrExpNode;

    public CondNode(LOrExpNode lOrExpNode) {
        this.lOrExpNode = lOrExpNode;
    }

    public void print() {
        lOrExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.Cond));
    }
}
