package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class AddExpNode {
    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    public MulExpNode mulExp;
    public AddExpNode addExp;
    public Token op;

    public AddExpNode(MulExpNode mulExp, AddExpNode AddExp, Token op) {
        this.mulExp = mulExp;
        this.addExp = AddExp;
        this.op = op;
    }

    public void print() {
        mulExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.AddExp));
        if (op != null) {
            IO.write(op.toString());
            addExp.print();
        }
    }
}
