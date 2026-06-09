package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class CharacterNode {
    // Character → CharConst
    public Token chartk; // 字符常量的值

    public CharacterNode(Token chartk) {
        this.chartk = chartk; // 保存整数值
    }

    public void print() {
        IO.write(chartk.toString());
        IO.write(Parser.nodeTypeLabel.get(NodeType.Character));
    }
}
