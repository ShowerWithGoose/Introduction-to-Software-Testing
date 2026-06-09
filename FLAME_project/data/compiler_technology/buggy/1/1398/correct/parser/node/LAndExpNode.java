package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class LAndExpNode {
    ArrayList<EqExpNode> eqExpNodes;
    ArrayList<Token> operators;

    public LAndExpNode(ArrayList<EqExpNode> eqExpNodes, ArrayList<Token> operators) {
        this.eqExpNodes = eqExpNodes;
        this.operators = operators;
    }
    public void print() {
        for (int i = 0; i < operators.size(); i++)
        {
            eqExpNodes.get(i).print();
            System.out.println(NodeType.LAndExp);
            operators.get(i).print();
        }
        eqExpNodes.get(eqExpNodes.size() - 1).print();
        System.out.println(NodeType.LAndExp);
    }
}
