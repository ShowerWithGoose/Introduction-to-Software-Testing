package ast;

import IO.IO;
import enum_package.ConstInitValType;
import enum_package.NodeType;
import frontend.Token;

import java.util.List;
import frontend.Parser;

public class ConstInitValNode {
    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public ConstExpNode constExp; // 常量表达式
    public Token lBrace; // 指向 '{' 的叶节点
    public List<ConstExpNode> constExps; // 数组初始化值列表
    public List<Token> commas; // 指向 ',' 的叶节点
    public Token rBrace; // 指向 '}' 的叶节点
    public Token strcon;

    public ConstInitValNode(ConstExpNode constExp, Token lBrace, List<ConstExpNode> constExps, List<Token> commas, Token rBrace, Token strcon) {
        this.constExp = constExp;
        this.lBrace = lBrace;
        this.constExps = constExps;
        this.commas = commas;
        this.rBrace = rBrace;
        this.strcon = strcon; // 设置字符串常量
    }

    public void print() {
        if (constExp != null) {
            constExp.print();
        } else if (lBrace != null) {
            IO.write(lBrace.toString());
            if (!constExps.isEmpty()) {
                for (int i = 0; i < constExps.size(); i++) {
                    constExps.get(i).print();
                    if (i != constExps.size() - 1) {
                        IO.write(commas.get(i).toString());
                    }
                }
            }
            IO.write(rBrace.toString());
        } else if (strcon != null) {
            IO.write(strcon.toString());
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.ConstInitVal));
    }
}
