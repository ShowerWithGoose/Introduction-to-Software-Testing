package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Parser;

public class ExpNode {
    // Exp â†’ AddExp
    AddExpNode addExp;

    public ExpNode(AddExpNode addExp) {
        this.addExp = addExp;
    }

    public void print() {
        addExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.Exp));
    }
}
