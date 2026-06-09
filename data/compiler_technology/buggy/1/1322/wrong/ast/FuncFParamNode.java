package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class FuncFParamNode {
    // FuncFParam → BType Ident ['[' ']'] // k
    public BTypeNode type; // 基本类型节点
    public Token identifier; // 参数名
    public Token lBrack; // '[‘的叶节点
    public Token rBrack; // ']‘的叶节点

    public FuncFParamNode(BTypeNode type, Token identifier, Token lBrack, Token rBrack) {
        this.type = type;
        this.identifier = identifier; // 保存参数名
        this.lBrack = lBrack;
        this.rBrack = rBrack;
    }

    public void print() {
        type.print();
        IO.write(identifier.toString());
        if (lBrack != null) {
            IO.write(lBrack.toString());
            IO.write(rBrack.toString());
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.FuncFParam));
    }
}
