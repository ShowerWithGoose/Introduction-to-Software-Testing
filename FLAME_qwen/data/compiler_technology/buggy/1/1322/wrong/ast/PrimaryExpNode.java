package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class PrimaryExpNode {
    // PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
    public Token lParent; // 指向 '(' 的叶节点
    public ExpNode exp; // 表达式节点
    public Token rParent; // 指向 ')' 的叶节点
    public LValNode lValue; // 左值节点
    public NumberNode number; // 数值（如果是数值表达式）
    public CharacterNode character; // 字符（如果是字符表达式）

    // 用于处理括号中的表达式
    public PrimaryExpNode(Token lParent, ExpNode exp, Token rParent, LValNode lValue, NumberNode number, CharacterNode character) {
        this.lParent = lParent;
        this.exp = exp;
        this.rParent = rParent;
        this.lValue = lValue; // 默认没有左值
        this.number = number; // 默认没有数值
        this.character = character; // 默认没有字符
    }

    public void print() {
        if (lParent != null) {
            IO.write(lParent.toString());
            exp.print();
            IO.write(rParent.toString());
        } else if (lValue != null) {
            lValue.print();
        } else if (number != null) {
            number.print();
        } else if (character != null) {
            character.print();
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.PrimaryExp));
    }
}
