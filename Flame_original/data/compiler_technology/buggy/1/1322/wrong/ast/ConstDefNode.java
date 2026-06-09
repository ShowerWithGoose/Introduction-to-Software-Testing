package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class ConstDefNode {
    // ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    public Token identifier; // 标识符
    public Token lBrack; // '[‘的叶节点
    public ConstExpNode constExp; // 可选的数组大小
    public Token rBrack; // ']‘的叶节点
    public Token assign; // '=' 的叶节点
    public ConstInitValNode constInitVal; // 常量初值

    public ConstDefNode(Token identifier, Token lBrack, ConstExpNode constExp, Token rBrack, Token assign, ConstInitValNode constInitVal) {
        this.identifier = identifier; // 保存标识符
        this.lBrack = lBrack;
        this.constExp = constExp; // 默认没有数组大小
        this.rBrack = rBrack;
        this.assign = assign; // 默认没有 '='
        this.constInitVal = constInitVal; // 默认没有初始值
    }

    public void print(){
        IO.write(identifier.toString());
        if (lBrack != null) {
            IO.write(lBrack.toString());
            constExp.print();
            IO.write(rBrack.toString());
        }
        IO.write(assign.toString());
        constInitVal.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.ConstDef));
    }
}