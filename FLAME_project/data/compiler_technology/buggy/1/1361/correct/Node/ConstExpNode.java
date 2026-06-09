package Node;

import IOcontrol.IO;
import LexParser.Parser;

public class ConstExpNode {
    //常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量
    private AddExpNode addExpNode;

    public ConstExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }

    public void print() {
        addExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.ConstExp));
    }
}
