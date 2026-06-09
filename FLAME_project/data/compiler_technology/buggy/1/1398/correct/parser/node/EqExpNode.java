package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class EqExpNode {
    ArrayList<RelExpNode> relExpNodes;
    ArrayList<Token> operators;
    public EqExpNode(ArrayList<RelExpNode> relExpNodes, ArrayList<Token> operators) {
        this.relExpNodes = relExpNodes;
        this.operators = operators;
    }
    public void print() {
        for (int i = 0; i < operators.size(); i++)
        {
            relExpNodes.get(i).print();
            System.out.println(NodeType.EqExp);
            operators.get(i).print();
        }
        relExpNodes.get(relExpNodes.size() - 1).print();
        System.out.println(NodeType.EqExp);
    }

}
