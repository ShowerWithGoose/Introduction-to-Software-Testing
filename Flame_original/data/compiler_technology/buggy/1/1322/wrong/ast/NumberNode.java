package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class NumberNode {
    // Number → IntConst
    public Token inttk; // 整数常量的值

    public NumberNode(Token inttk) {
        this.inttk = inttk; // 保存整数值
    }

    public void print() {
        IO.write(inttk.toString());
        IO.write(Parser.nodeTypeLabel.get(NodeType.Number));
    }
}
