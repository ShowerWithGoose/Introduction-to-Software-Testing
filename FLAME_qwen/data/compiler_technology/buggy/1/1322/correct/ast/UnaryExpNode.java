package ast;

import IO.IO;
import enum_package.NodeType;
import enum_package.UnaryExpType;
import frontend.Token;
import frontend.Parser;
import frontend.Parser;

public class UnaryExpNode {
    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    public PrimaryExpNode primaryExp; // 基本表达式
    public Token identifier; // 标识符
    public Token lParent; // 指向 '(' 的叶节点
    public FuncRParamsNode funcRParams; // 函数实参表
    public Token rParent; // 指向 ')' 的叶节点
    public UnaryOpNode unaryOp; // 一元运算符
    public UnaryExpNode unaryExp;

    // 处理基本表达式
    public UnaryExpNode(PrimaryExpNode primaryExp, Token identifier, Token lParent, FuncRParamsNode funcRParams, Token rParent, UnaryOpNode unaryOp, UnaryExpNode unaryExp) {
        this.primaryExp = primaryExp;
        this.identifier = identifier;
        this.lParent = lParent;
        this.funcRParams = funcRParams;
        this.rParent = rParent;
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    public void print() {
        if (identifier!=null) {
            IO.write(identifier.toString());
            IO.write(lParent.toString());
            if (funcRParams != null) {
                funcRParams.print();
            }
            IO.write(rParent.toString());
        } else if (primaryExp != null) {
            primaryExp.print();
        } else if (unaryOp != null) {
            unaryOp.print();
            unaryExp.print();
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.UnaryExp));
    }
}
