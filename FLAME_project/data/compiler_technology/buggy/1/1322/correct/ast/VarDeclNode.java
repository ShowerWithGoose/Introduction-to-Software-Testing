package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;

import java.util.List;
import frontend.Parser;

public class VarDeclNode {
    // VarDecl → BType VarDef { ',' VarDef } ';' // i
    public BTypeNode type; // 指向基本类型的中间节点
    public List<VarDefNode> varDefs; // 变量定义列表
    public List<Token> commas; // 指向 ',' 的叶节点
    public Token semicolon; // 指向 ';' 的叶节点

    public VarDeclNode(BTypeNode type, List<VarDefNode> varDefs, List<Token> commas, Token semicolon) {
        this.type = type; // 设置基本类型
        this.varDefs = varDefs;
        this.commas = commas;
        this.semicolon = semicolon;
    }

    public void print() {
        type.print();
        varDefs.get(0).print();
        for (int i = 1; i < varDefs.size(); i++) {
            IO.write(commas.get(i - 1).toString());
            varDefs.get(i).print();
        }
        IO.write(semicolon.toString());
        IO.write(Parser.nodeTypeLabel.get(NodeType.VarDecl));
    }
}
