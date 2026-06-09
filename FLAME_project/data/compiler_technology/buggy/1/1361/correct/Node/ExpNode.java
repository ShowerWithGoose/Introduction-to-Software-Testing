package Node;

import IOcontrol.IO;
import LexParser.Parser;

public class ExpNode {
    //表达式 Exp → AddExp
    private AddExpNode addExpNode;

    public ExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }

    public void print() {
        addExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.Exp));
    }
}
