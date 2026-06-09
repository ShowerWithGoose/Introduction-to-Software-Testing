package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class MainFuncDefNode {
    // MainFuncDef → 'int' 'main' '(' ')' Block // j
    public Token inttk; // 返回类型
    public Token maintk; // 函数名
    public Token lParent; // 指向 '(' 的叶节点
    public Token rParent; // 指向 ')' 的叶节点
    public BlockNode block; // 函数体

    public MainFuncDefNode(Token inttk, Token maintk, Token lParent, Token rParent, BlockNode block) {
        this.inttk = inttk; // 保存返回类型
        this.maintk = maintk; // 保存函数名
        this.lParent = lParent;
        this.rParent = rParent;
        this.block = block; // 保存函数体
    }

    public void print() {
        IO.write(inttk.toString());
        IO.write(maintk.toString());
        IO.write(lParent.toString());
        IO.write(rParent.toString());
        block.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.MainFuncDef));
    }
}
