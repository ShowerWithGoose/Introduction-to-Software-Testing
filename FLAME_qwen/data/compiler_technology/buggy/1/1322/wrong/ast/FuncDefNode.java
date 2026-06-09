package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class FuncDefNode {
    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
    public FuncTypeNode funcType; // 函数类型
    public Token identifier; // 函数名
    public Token lParent; // 指向 '(' 的叶节点
    public FuncFParamsNode funcFParams; // 函数形参表
    public Token rParent; // 指向 ')' 的叶节点
    public BlockNode block; // 函数体

    public FuncDefNode(FuncTypeNode funcType, Token identifier, Token lParent, FuncFParamsNode funcFParams, Token rParent, BlockNode block) {
        this.funcType = funcType;
        this.identifier = identifier; // 保存函数名
        this.lParent = lParent;
        this.funcFParams = funcFParams; // 保存函数形参表
        this.rParent = rParent;
        this.block = block;
    }

    public void print() {
        funcType.print();
        IO.write(identifier.toString());
        IO.write(lParent.toString());
        if (funcFParams != null) {
            funcFParams.print();
        }
        IO.write(rParent.toString());
        block.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.FuncDef));
    }
}
