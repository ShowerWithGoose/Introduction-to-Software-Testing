package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;

import java.util.List;
import frontend.Parser;

public class FuncFParamsNode {
    // FuncFParams → FuncFParam { ',' FuncFParam }
    public List<FuncFParamNode> params; // 形参列表
    public List<Token> commas; // 指向 ',' 的叶节点

    public FuncFParamsNode(List<FuncFParamNode> param, List<Token> comma) {
        this.params = param;
        this.commas = comma;
    }

    public void print() {
        for (int i = 0; i < params.size(); i++) {
            params.get(i).print();
            if (i != params.size() - 1) {
                IO.write(commas.get(i).toString());
            }
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.FuncFParams));
    }
}
