package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class AddExpNode {
    ArrayList<MulExpNode> mulExpNodes;
    ArrayList<Token> operators;
    public AddExpNode(ArrayList<MulExpNode> mulExpNodes, ArrayList<Token> operators) {
        this.mulExpNodes = mulExpNodes;
        this.operators = operators;
    }
    public void print() {
        for (int i = 0; i < operators.size(); i++)
        {
            mulExpNodes.get(i).print();
            System.out.println(NodeType.MulExp);
            operators.get(i).print();
        }
        mulExpNodes.get(mulExpNodes.size() - 1).print();
        System.out.println(NodeType.AddExp);
    }
}
