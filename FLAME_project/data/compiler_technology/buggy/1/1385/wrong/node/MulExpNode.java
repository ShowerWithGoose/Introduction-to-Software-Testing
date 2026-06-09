package node;


import token.Token;

import java.io.IOException;
import java.util.ArrayList;

public class MulExpNode {
    // MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp

    private ArrayList<UnaryExpNode> unaryExpNodes;
    private ArrayList<Token> operators;

    public MulExpNode(ArrayList<UnaryExpNode> unaryExpNodes, ArrayList<Token> operators) {
        this.unaryExpNodes = unaryExpNodes;
        this.operators = operators;
    }
    
    public void print() throws IOException {
        if (unaryExpNodes.size()==1) {
            unaryExpNodes.get(0).print();
            Io.Text.printWord("<MulExp>");
        }
        else {
            for (int i = 0;i<unaryExpNodes.size()-1;i+=1) {
                unaryExpNodes.get(i).print();
                Io.Text.printWord("<MulExp>");
                operators.get(i).print();
            }
            unaryExpNodes.get(unaryExpNodes.size()-1).print();
            Io.Text.printWord("<MulExp>");
        }
    }
}
