package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;

import java.util.List;
import frontend.Parser;

public class ConstDeclNode {
    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } // i
    public Token consttk; // 指向 'const' 的叶节点
    public BTypeNode type; // 指向 BType 的中间节点
    public List<ConstDefNode> constDefs; // 常量定义列表
    public List<Token> commas; // 指向 ',' 的叶节点
    public Token semicn; // 指向 ';' 的叶节点

    public ConstDeclNode(Token consttk, BTypeNode type, List<ConstDefNode> constDeclNodes, List<Token> commas, Token semicn) {
        this.consttk = consttk; // 设置 'const' 关键字
        this.type = type; // 设置基本类型
        this.constDefs = constDeclNodes; // 初始化常量定义列表
        this.commas = commas; // 初始化逗号列表
        this.semicn = semicn;
    }

    public void print(){
        IO.write(consttk.toString());
        type.print();
        for (int i = 0; i < constDefs.size(); i++) {
            constDefs.get(i).print();
            if (i != constDefs.size() - 1) {
                IO.write(commas.get(i).toString());
            }
        }
        IO.write(semicn.toString());
        IO.write(Parser.nodeTypeLabel.get(NodeType.ConstDecl));
    }
}
