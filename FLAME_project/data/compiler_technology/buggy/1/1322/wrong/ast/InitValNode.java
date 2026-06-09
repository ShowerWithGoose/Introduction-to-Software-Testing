package ast;

import IO.IO;
import enum_package.InitValType;
import enum_package.NodeType;
import frontend.Token;

import java.util.List;
import frontend.Parser;

public class InitValNode {
    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public ExpNode exp; // 表达式初值
    public Token lBrace; // 指向 '{' 的叶节点
    public List<ExpNode> exps; // 数组初始化值列表
    public List<Token> commas; // 指向 ',' 的叶节点
    public Token rBrace; // 指向 '}' 的叶节点
    public Token strcon; // 字符串常量初值

    // 用于表达式初值
    public InitValNode(ExpNode exp, Token lBrace, List<ExpNode> exps, List<Token> commas, Token rBrace, Token stringConst) {
        this.exp = exp; // 设置表达式初值
        this.lBrace = lBrace;
        this.exps = exps; // 默认没有数组初始化值
        this.commas = commas;
        this.rBrace = rBrace;
        this.strcon = stringConst; // 默认没有字符串常量
    }

    public void print() {
        if (exp != null) {
            exp.print();
        } else if (lBrace != null) {
            IO.write(lBrace.toString());
            if (!exps.isEmpty()) {
                for (int i = 0; i < exps.size(); i++) {
                    exps.get(i).print();
                    if (i != exps.size() - 1) {
                        IO.write(commas.get(i).toString());
                    }
                }
            }
            IO.write(rBrace.toString());
        } else if (strcon != null) {
            IO.write(strcon.toString());
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.InitVal));
    }
}
