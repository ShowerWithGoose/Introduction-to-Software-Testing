package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;

public class RelExpNode {
    // RelExp -> AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private ArrayList<AddExpNode> addExpNodes;
    private ArrayList<Token> operators;


    public RelExpNode(ArrayList<AddExpNode> addExpNodes,ArrayList<Token> operators) {
        this.addExpNodes = addExpNodes;
        this.operators = operators;
    }
    
    public void print() throws IOException {
        if (operators.isEmpty()) {
            addExpNodes.get(0).print();
            Io.Text.printWord("<RelExp>");
        }
        else {
            for (int i = 0;i<addExpNodes.size()-1;i+=1) {
                addExpNodes.get(i).print();
                Io.Text.printWord("<RelExp>");
                operators.get(i).print();
            }
            addExpNodes.get(addExpNodes.size()-1).print();
            Io.Text.printWord("<RelExp>");
        }
    }
    
}
