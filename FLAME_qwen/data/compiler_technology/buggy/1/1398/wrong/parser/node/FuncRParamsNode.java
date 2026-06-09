package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class FuncRParamsNode {
    ArrayList<ExpNode> expNodes;
    ArrayList<Token> commas;

    public FuncRParamsNode(ArrayList<ExpNode> expNodes, ArrayList<Token> commas) {
        this.expNodes = expNodes;
        this.commas = commas;
    }

    public void print() {
        expNodes.get(0).print();
        for (int i = 1; i < expNodes.size(); i++)
        {
            commas.get(i - 1).print();
            expNodes.get(i).print();
        }
        System.out.println(NodeType.FuncRParams);
    }

}
