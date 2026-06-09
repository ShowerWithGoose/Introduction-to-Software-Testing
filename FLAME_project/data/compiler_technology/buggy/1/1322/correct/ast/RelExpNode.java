package ast;

import IO.IO;
import enum_package.NodeType;
import enum_package.RelExpType;
import frontend.Token;
import frontend.Parser;

public class RelExpNode {
    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public RelExpNode relExp;
    public AddExpNode addExp; // 第一个加减表达式
    public Token op;

    public RelExpNode(AddExpNode addExp, RelExpNode relExp, Token op) {
        this.addExp = addExp;
        this.relExp = relExp;
        this.op = op;
    }

    public void print() {
        addExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.RelExp));
        if (op != null) {
            IO.write(op.toString());
            relExp.print();
        }
    }
}
