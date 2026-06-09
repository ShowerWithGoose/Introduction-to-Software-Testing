package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class MulExpNode {
    ArrayList<UnaryExpNode> unaryExpNodes;
    ArrayList<Token> operators;

    public MulExpNode(ArrayList<UnaryExpNode> unaryExpNodes, ArrayList<Token> operators) {
        this.unaryExpNodes = unaryExpNodes;
        this.operators = operators;
    }

    public void print() {
        for (int i = 0; i < operators.size(); i++)
        {
            unaryExpNodes.get(i).print();
            System.out.println(NodeType.MulExp);
            operators.get(i).print();
        }
        unaryExpNodes.get(unaryExpNodes.size() - 1).print();
        System.out.println(NodeType.MulExp);
    }


}
