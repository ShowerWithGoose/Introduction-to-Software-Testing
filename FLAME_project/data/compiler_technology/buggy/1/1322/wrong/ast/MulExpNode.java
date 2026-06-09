package ast;

import IO.IO;
import enum_package.MulExpType;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class MulExpNode {
    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public UnaryExpNode unaryExp; // 第一个一元表达式
    public MulExpNode mulExp; // 额外的一元表达式列表
    public Token op; // '*'、'/' 或 '%' 操作符列表

    public MulExpNode(UnaryExpNode unaryExp, MulExpNode mulExp, Token op) {
        this.mulExp = mulExp;
        this.op = op;
        this.unaryExp = unaryExp;
    }

    public void print() {
        unaryExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.MulExp));
        if (op != null) {
            IO.write(op.toString());
            mulExp.print();
        }
    }
}
