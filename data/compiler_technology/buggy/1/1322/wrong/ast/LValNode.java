package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class LValNode {
    // LVal → Ident ['[' Exp ']'] // k
    public Token identifier; // 标识符
    public Token lBrack; // '[‘的叶节点
    public ExpNode exp; // 可选的数组大小
    public Token rBrack; // ']‘的叶节点

    public LValNode(Token identifier, Token lBrack, ExpNode exp, Token rBrack) {
        this.identifier = identifier; // 保存标识符
        this.lBrack = lBrack;
        this.exp = exp;
        this.rBrack = rBrack;
    }

    public void print() {
        IO.write(identifier.toString());
        if (lBrack != null) {
            IO.write(lBrack.toString());
            exp.print();
            IO.write(rBrack.toString());
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.LVal));
    }
}
