package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class FuncFParamsNode {
    ArrayList<FuncFParamNode> funcFParamNodes;
    ArrayList<Token> commas;

    public FuncFParamsNode(ArrayList<FuncFParamNode> funcFParamNodes, ArrayList<Token> commas) {
        this.funcFParamNodes = funcFParamNodes;
        this.commas = commas;
    }

    public void print() {
        funcFParamNodes.get(0).print();
        for (int i = 0; i < funcFParamNodes.size(); i++)
        {
            commas.get(i - 1).print();
            funcFParamNodes.get(i).print();
        }
        System.out.println(NodeType.FuncFParams);
    }


}
