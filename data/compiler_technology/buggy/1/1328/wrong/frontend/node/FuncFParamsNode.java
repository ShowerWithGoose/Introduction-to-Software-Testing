package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.ArrayList;

public class FuncFParamsNode {
    // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }

    private ArrayList<FuncFParamNode> funcFParamNodes;
    private Token commaToken;

    public FuncFParamsNode(ArrayList<FuncFParamNode> funcFParamNodes, Token commaToken) {
        this.funcFParamNodes = funcFParamNodes;
        this.commaToken = commaToken;
    }

    public ArrayList<FuncFParamNode> getFuncFParamNodes() {
        return funcFParamNodes;
    }

    public void print() {
        funcFParamNodes.get(0).print();
        for (int i = 1; i < funcFParamNodes.size(); i++) {
            MyIO.writeToken(commaToken.toString());
            funcFParamNodes.get(i).print();
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.FuncFParams));
    }
}
