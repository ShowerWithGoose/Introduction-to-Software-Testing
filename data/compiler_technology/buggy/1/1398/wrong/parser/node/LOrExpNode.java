package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class LOrExpNode {
    ArrayList<LAndExpNode> lAndExpNodes;
    ArrayList<Token> operators;

    public LOrExpNode(ArrayList<LAndExpNode> lAndExpNodes, ArrayList<Token> operators) {
        this.lAndExpNodes = lAndExpNodes;
        this.operators = operators;
    }
    public void print() {
        for (int i = 0; i < operators.size(); i++)
        {
            lAndExpNodes.get(i).print();
            System.out.println(NodeType.MulExp);
            operators.get(i).print();
        }
        lAndExpNodes.get(lAndExpNodes.size() - 1).print();
        System.out.println(NodeType.LOrExp);
    }
}
