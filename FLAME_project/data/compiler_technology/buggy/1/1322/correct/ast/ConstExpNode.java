package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Parser;

public class ConstExpNode {
    // ConstExp → AddExp
    public AddExpNode addExp; // 加法表达式节点

    public ConstExpNode(AddExpNode addExp) {
        this.addExp = addExp; // 保存加法表达式
    }

    public void print() {
        addExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.ConstExp));
    }
}
