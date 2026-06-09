package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class RelExpNode {
    ArrayList<AddExpNode> addExpNodes;
    ArrayList<Token> operators;

    public RelExpNode(ArrayList<AddExpNode> addExpNodes, ArrayList<Token> operators) {
        this.addExpNodes = addExpNodes;
        this.operators = operators;
    }
    public void print() {
        for (int i = 0; i < operators.size(); i++)
        {
            addExpNodes.get(i).print();
            System.out.println(NodeType.MulExp);
            operators.get(i).print();
        }
        addExpNodes.get(addExpNodes.size() - 1).print();
        System.out.println(NodeType.RelExp);
    }
}
