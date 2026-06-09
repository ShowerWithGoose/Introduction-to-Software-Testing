package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;

import java.util.List;
import frontend.Parser;

public class FuncRParamsNode {
    // FuncRParams → Exp { ',' Exp }
    public List<ExpNode> exps; // 形参列表
    public List<Token> commas; // 指向 ',' 的叶节点

    public FuncRParamsNode(List<ExpNode> exps, List<Token> comma) {
        this.exps = exps;
        this.commas = comma;
    }

    public void print() {
        for (int i = 0; i < exps.size(); i++) {
            exps.get(i).print();
            if(i != exps.size() - 1) {
                IO.write(commas.get(i).toString());
            }
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.FuncRParams));
    }
}
