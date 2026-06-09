package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Parser;

public class CondNode {
    // Cond â†’ LOrExp
    public LOrExpNode lOrExp;

    public CondNode(LOrExpNode lOrExp) {
        this.lOrExp = lOrExp;
    }

    public void print() {
        lOrExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.Cond));
    }
}
